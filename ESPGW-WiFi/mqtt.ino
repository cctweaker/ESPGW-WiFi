
//////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////
// #### ##    ## #### ########    ##     ##  #######  ######## ########
//  ##  ###   ##  ##     ##       ###   ### ##     ##    ##       ##
//  ##  ####  ##  ##     ##       #### #### ##     ##    ##       ##
//  ##  ## ## ##  ##     ##       ## ### ## ##     ##    ##       ##
//  ##  ##  ####  ##     ##       ##     ## ##  ## ##    ##       ##
//  ##  ##   ###  ##     ##       ##     ## ##    ##     ##       ##
// #### ##    ## ####    ##       ##     ##  ##### ##    ##       ##

void init_mqtt()
{
    if (!start_mqtt || !use_wifi)
        return;

    char topic[128];
    sprintf(topic, "%s%s%s%s%s", LOC, TIP, NAME, XTRA, WILL);

    client.begin(MQTT_HOST, MQTT_PORT, net);
    client.setWill(topic, "0", true, 0);
    client.onMessage(messageReceived);

    connect_mqtt();
}

//////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////
//  ######   #######  ##    ## ##    ## ########  ######  ########    ##     ##  #######  ######## ########
// ##    ## ##     ## ###   ## ###   ## ##       ##    ##    ##       ###   ### ##     ##    ##       ##
// ##       ##     ## ####  ## ####  ## ##       ##          ##       #### #### ##     ##    ##       ##
// ##       ##     ## ## ## ## ## ## ## ######   ##          ##       ## ### ## ##     ##    ##       ##
// ##       ##     ## ##  #### ##  #### ##       ##          ##       ##     ## ##  ## ##    ##       ##
// ##    ## ##     ## ##   ### ##   ### ##       ##    ##    ##       ##     ## ##    ##     ##       ##
//  ######   #######  ##    ## ##    ## ########  ######     ##       ##     ##  ##### ##    ##       ##

void connect_mqtt()
{
    uint8_t i = 0;

    while (WiFi.status() != WL_CONNECTED)
    {
        delay(100);
        i++;
        if (i > 200)
            ESP.restart();
    }

#ifdef USE_SSL
    BearSSL::X509List cert(digicert);
    net.setTrustAnchors(&cert);
#endif

    i = 0;
    while (!client.connect(NAME, MQTT_USER, MQTT_PASS))
    {
        delay(100);
        i++;
        if (i > 200)
        {
            use_mqtt = false;
            return;
        }
    }

    char topic[128];

    sprintf(topic, "%s%s%s%s%s/+", LOC, TIP, NAME, XTRA, SUB);
    client.subscribe(topic, 0);

    sprintf(topic, "%s%s%s%s%s", LOC, TIP, NAME, XTRA, WILL);
    client.publish(topic, "1", true, 0);

    mqtt_heartbeat();

    use_mqtt = true;
}

//////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////
// ##        #######   #######  ########
// ##       ##     ## ##     ## ##     ##
// ##       ##     ## ##     ## ##     ##
// ##       ##     ## ##     ## ########
// ##       ##     ## ##     ## ##
// ##       ##     ## ##     ## ##
// ########  #######   #######  ##

void mqtt_loop()
{
    if (heartbeat)
        if ((unsigned long)(millis() - last_heartbeat) > heartbeat_minutes * 60 * 1000)
        {
            last_heartbeat = millis();
            mqtt_heartbeat();
        }
}

//////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////
// ########  ##     ##
// ##     ##  ##   ##
// ##     ##   ## ##
// ########     ###
// ##   ##     ## ##
// ##    ##   ##   ##
// ##     ## ##     ##

void messageReceived(String &topic, String &payload)
{
    uint8_t idx = topic.lastIndexOf('/') + 1;
    String cmnd = topic.substring(idx);
    uint8_t value = payload.toInt();

    if (cmnd == "reset")
    {
        ESP.restart();
    }

    if (cmnd == "webserver")
    {
        if (value)
            start_webserver = true;
        else
            start_webserver = false;

        fs_save_device();
    }

    if (cmnd == "update")
    {
        do_ota_update = true;
        return;
    }
}

//////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////
// ##     ## ########    ###    ########  ######## ########  ########    ###    ########
// ##     ## ##         ## ##   ##     ##    ##    ##     ## ##         ## ##      ##
// ##     ## ##        ##   ##  ##     ##    ##    ##     ## ##        ##   ##     ##
// ######### ######   ##     ## ########     ##    ########  ######   ##     ##    ##
// ##     ## ##       ######### ##   ##      ##    ##     ## ##       #########    ##
// ##     ## ##       ##     ## ##    ##     ##    ##     ## ##       ##     ##    ##
// ##     ## ######## ##     ## ##     ##    ##    ########  ######## ##     ##    ##

void mqtt_heartbeat()
{
    char topic[128];
    char mqtt_tx[256];

    DynamicJsonDocument doc(256);

#ifndef USE_SSL
    doc["fw"] = FW_NAME;
#else
    doc["fw"] = String(FW_NAME) + "_SSL";
#endif
    doc["ver"] = VERSION;
    doc["ID"] = String(ESP.getChipId(), HEX);
    doc["Vcc"] = ESP.getVcc();
    doc["SSID"] = WiFi.SSID();
    doc["RSSI"] = WiFi.RSSI();
    doc["BSSID"] = WiFi.BSSIDstr();
    doc["IP"] = WiFi.localIP().toString();

    serializeJson(doc, mqtt_tx);
    doc.clear();
    sprintf(topic, "%s%s%s%s%s", LOC, TIP, NAME, XTRA, STAT);
    client.publish(topic, mqtt_tx, true, 0);

    doc["free heap"] = ESP.getFreeHeap();
    doc["heap frag"] = ESP.getHeapFragmentation();
    doc["max block"] = ESP.getMaxFreeBlockSize();
    doc["core v"] = ESP.getCoreVersion();
    doc["sdk v"] = ESP.getSdkVersion();
    doc["sketch"] = ESP.getSketchSize();
    doc["sketch free"] = ESP.getFreeSketchSpace();
    doc["MD5"] = ESP.getSketchMD5();
    doc["crc"] = ESP.checkFlashCRC();

    serializeJson(doc, mqtt_tx);
    doc.clear();
    sprintf(topic, "%s%s%s%s%s/1", LOC, TIP, NAME, XTRA, STAT);
    client.publish(topic, mqtt_tx, true, 0);

    doc["CPU freq"] = ESP.getCpuFreqMHz();
    doc["flash freq"] = ESP.getFlashChipSpeed() / 1000000;
    doc["flash ID"] = String(ESP.getFlashChipId(), HEX);
    doc["flash size"] = ESP.getFlashChipSize();
    doc["real flash size"] = ESP.getFlashChipRealSize();
    doc["CPU cycles"] = ESP.getCycleCount();

    serializeJson(doc, mqtt_tx);
    doc.clear();
    sprintf(topic, "%s%s%s%s%s/2", LOC, TIP, NAME, XTRA, STAT);
    client.publish(topic, mqtt_tx, true, 0);
}

//////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////
