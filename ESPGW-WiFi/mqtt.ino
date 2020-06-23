//////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////

void mqtt_setup()
{
    client.begin(MQTT_HOST, MQTT_PORT, net);
    client.setWill(MQTT_WILL_TOPIC, "0", true, 0);
    client.onMessage(messageReceived);
    mqtt_connect();
}

//////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////

void mqtt_connect()
{
    uint8_t i = 0;

    while (WiFi.status() != WL_CONNECTED)
    {
        delay(100);
        i++;
        if (i > 100)
            ESP.restart();
    }

    // certificare
    BearSSL::X509List cert(digicert);
    net.setTrustAnchors(&cert);

    while (!client.connect(HOSTNAME, MQTT_USER, MQTT_PASS))
    {
        delay(100);
        i++;
        if (i > 100)
            ESP.restart();
    }

    client.subscribe(MQTT_CMND_TOPIC, 0);
    client.publish(MQTT_WILL_TOPIC, "1", true, 0);
}

//////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////

void messageReceived(String &topic, String &payload)
{

    uint8_t idx = topic.lastIndexOf('/') + 1;
    String cmnd = topic.substring(idx);

    if (cmnd == "save")
    {
        do_save_config = true;
        return;
    }

    if (cmnd == "update")
    {
        do_ota_update = true;
        return;
    }

    if (cmnd == "reset")
    {
        ESP.restart();
    }

    if (cmnd == "format")
    {
        do_fs_format = true;
        return;
    }

    if (cmnd == "list")
    {
        do_list_config = true;
        return;
    }

    /////////////////

    if (cmnd == "config")
    {
        StaticJsonDocument<1024> doc;
        deserializeJson(doc, payload);

        if (doc.containsKey("NAME"))
            strlcpy(NAME, doc["NAME"], sizeof(NAME));
        if (doc.containsKey("LOC"))
            strlcpy(LOC, doc["LOC"], sizeof(LOC));

        if (doc.containsKey("SSIDa"))
            strlcpy(SSIDa, doc["SSIDa"], sizeof(SSIDa));
        if (doc.containsKey("PASSa"))
            strlcpy(PASSa, doc["PASSa"], sizeof(PASSa));
        if (doc.containsKey("SSIDb"))
            strlcpy(SSIDb, doc["SSIDb"], sizeof(SSIDb));
        if (doc.containsKey("PASSb"))
            strlcpy(PASSb, doc["PASSb"], sizeof(PASSb));

        if (doc.containsKey("MQTT_HOST"))
            strlcpy(MQTT_HOST, doc["MQTT_HOST"], sizeof(MQTT_HOST));
        if (doc.containsKey("MQTT_PORT"))
            MQTT_PORT = doc["MQTT_PORT"];
        if (doc.containsKey("MQTT_USER"))
            strlcpy(MQTT_USER, doc["MQTT_USER"], sizeof(MQTT_USER));
        if (doc.containsKey("MQTT_PASS"))
            strlcpy(MQTT_PASS, doc["MQTT_PASS"], sizeof(MQTT_PASS));

        if (doc.containsKey("update_url"))
            strlcpy(update_url, doc["update_url"], sizeof(update_url));

        if (doc.containsKey("FACTOR"))
            FACTOR = doc["FACTOR"];
        if (doc.containsKey("heartbeat"))
            heartbeat = doc["heartbeat"];
        if (doc.containsKey("heartbeat_minutes"))
            heartbeat_minutes = doc["heartbeat_minutes"];

        doc.clear();
        init_others();
        return;
    }
}

//////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////

void init_mac_topics()
{
    sprintf(HOSTNAME, "%s_%x", NAME, ESP.getChipId());
    sprintf(MQTT_WILL_TOPIC, "%s/%s_%x%s", LOC, NAME, ESP.getChipId(), WILL);
    sprintf(MQTT_CMND_TOPIC, "%s/%s_%x%s", LOC, NAME, ESP.getChipId(), CMND);
    sprintf(MQTT_STAT_TOPIC, "%s/%s_%x%s", LOC, NAME, ESP.getChipId(), STAT);
    sprintf(MQTT_MSGS_TOPIC, "%s/%s_%x%s", LOC, NAME, ESP.getChipId(), MSGS);
}

//////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////

void send_heartbeat()
{
    char tx[256];
    float supply = (float)ESP.getVcc() / FACTOR;

    sprintf(tx, "{\"t\":\"%s\",\"n\":\"%s\",\"v\":%d,\"ID\":\"%x\",\"Vin\":%.2f,\"SSID\":\"%s\",\"RSSI\":%d,\"BSSID\":\"%s\"}", TIP, NAME, VERSION, ESP.getChipId(), supply, WiFi.SSID().c_str(), WiFi.RSSI(), WiFi.BSSIDstr().c_str());

    client.publish(MQTT_STAT_TOPIC, tx, true, 0);
}

//////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////

void process_serial()
{
    if (got_espnow_message)
        return;

    char c;

    while (Serial.available())
    {
        c = Serial.read();

        if (c == '{')
            accolades++;

        if (accolades > 0)
        {
            buffer[strlen(buffer)] = c;
            position++;
        }

        if (c == '}' && accolades > 0)
            accolades--;
    }

    if (accolades == 0 && position > 0)
        got_espnow_message = true;

    if (position == 255 && accolades > 0)
        clear_buffer();
}

//////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////

void clear_buffer()
{
    for (uint16_t i = 0; i < buffer_length; i++)
    {
        buffer[i] = 0;
    }

    got_espnow_message = false;
    position = 0;
    accolades = 0;
}

//////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////

void send_to_mqtt()
{
    client.publish(MQTT_MSGS_TOPIC, buffer, false, 0);
    clear_buffer();
}