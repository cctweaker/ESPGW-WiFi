///////////////////////////////////////////////////////////////////////
// device type (used in HOSTNAME and MQTT client) combined with ESP id
///////////////////////////////////////////////////////////////////////
char NAME[8] = "espgw";
///////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////
// device location also used as topic prefix
///////////////////////////////////////////////////////////////////////
char LOC[16] = "location";
///////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////
// primary WIFI
///////////////////////////////////////////////////////////////////////
char SSIDa[32] = "WiFi";
char PASSa[64] = "password";
///////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////
// secondary WIFI
///////////////////////////////////////////////////////////////////////
char SSIDb[32] = "WiFi";
char PASSb[64] = "password";
///////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////
// MQTT login
///////////////////////////////////////////////////////////////////////
char MQTT_HOST[64] = "www.mqtt.server";
int MQTT_PORT = 8883;
char MQTT_USER[64] = "mqtt_user";
char MQTT_PASS[64] = "mqtt_password";
///////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////
// update server, keep final / if path or end in .php if file
///////////////////////////////////////////////////////////////////////
char update_url[128] = "https://esp.3dstar.ro/";
///////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////
// heartbeat with information by mqtt
///////////////////////////////////////////////////////////////////////
// on - true or false - off
bool heartbeat = true;
// time in minutes between messages
uint16_t heartbeat_minutes = 10;
///////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////
// ESP supply voltage reporting
///////////////////////////////////////////////////////////////////////
// measure your ESP VCC voltage with a good multimeter
// should be around 3.30V
#define MEASURED 3.3
// enter the ESP reported voltage
// this will fluctuate from ESP to ESP
// i've seen up to 3.39V reported
#define REPORTED 3.3
float FACTOR = 1024.0 * MEASURED / REPORTED;
///////////////////////////////////////////////////////////////////////
