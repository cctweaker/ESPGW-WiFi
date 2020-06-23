//////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////

void load_config()
{
    if (!LittleFS.begin())
        return;

    // open config file for reading
    File configFile = LittleFS.open(config_file, "r");
    if (!configFile)
    {
        return;
    }

    StaticJsonDocument<2048> doc;

    // Read content from config file.
    deserializeJson(doc, configFile);
    configFile.close();
    LittleFS.end();

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
}

//////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////

void save_config()
{

    do_save_config = false;

    if (!LittleFS.begin())
        return;

    StaticJsonDocument<2048> doc;

    doc["NAME"] = NAME;
    doc["LOC"] = LOC;

    doc["SSIDa"] = SSIDa;
    doc["PASSa"] = PASSa;
    doc["SSIDb"] = SSIDb;
    doc["PASSb"] = PASSb;

    doc["MQTT_HOST"] = MQTT_HOST;
    doc["MQTT_PORT"] = MQTT_PORT;
    doc["MQTT_USER"] = MQTT_USER;
    doc["MQTT_PASS"] = MQTT_PASS;

    doc["update_url"] = update_url;

    doc["FACTOR"] = FACTOR;
    doc["heartbeat"] = heartbeat;
    doc["heartbeat_minutes"] = heartbeat_minutes;

    // serialize & write config
    File configFile = LittleFS.open(config_file, "w");
    if (!configFile)
        return;

    serializeJson(doc, configFile);
    configFile.close();

    doc.clear();

    LittleFS.end();

    client.publish(MQTT_STAT_TOPIC, "Save complete.", false, 0);
}

//////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////

void format_fs()
{
    do_fs_format = false;

    if (!LittleFS.begin())
        return;

    LittleFS.format();

    LittleFS.end();

    client.publish(MQTT_STAT_TOPIC, "Format complete.", false, 0);
}

//////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////

void list_config()
{
    do_list_config = false;

    if (!LittleFS.begin())
        return;

    // open config file for reading
    File configFile = LittleFS.open(config_file, "r");

    Serial.println();
    Serial.println(&config_file[0]);

    while (configFile.available())
        Serial.print((char)configFile.read());

    LittleFS.end();
}