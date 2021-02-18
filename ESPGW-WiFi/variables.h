///////////////////////////////////////////////////////////////////////
// configuration file
///////////////////////////////////////////////////////////////////////
const char wifi_cfg_file[] = "wifi.json";
const char dev_cfg_file[] = "device.json";
const char mqtt_cfg_file[] = "mqtt.json";
const char gw_cfg_file[] = "gw.json";
///////////////////////////////////////////////////////////////////////

//

///////////////////////////////////////////////////////////////////////
// flags
///////////////////////////////////////////////////////////////////////
bool cfg_wifi = false;
bool cfg_dev = false;
bool cfg_mqtt = false;
bool cfg_gw = false;

bool use_wifi = false;
bool use_ssl = false;
bool use_softap = false;
bool use_dns = false;
bool use_mqtt = false;
bool use_webserver = false;
bool use_gw = false;
bool use_esp_now_bridge = false;

bool start_mqtt = false;
bool start_webserver = true;
bool start_esp_now_bridge = false;

bool do_ota_update = false;
///////////////////////////////////////////////////////////////////////

//

///////////////////////////////////////////////////////////////////////
// WIFI
///////////////////////////////////////////////////////////////////////
char SSIDa[32] = "";
char PASSa[65] = "";

char SSIDb[32] = "";
char PASSb[65] = "";

const char STA_PASS[] = "abcd1234";
IPAddress STA_IP(192, 168, 10, 1);
IPAddress STA_MASK(255, 255, 255, 0);
const byte DNS_PORT = 53;
///////////////////////////////////////////////////////////////////////

//

///////////////////////////////////////////////////////////////////////
// DEVICE
///////////////////////////////////////////////////////////////////////
const char FW_NAME[] = "ESPGW-WiFi";
#ifdef LNG
#if LNG == 1
const char LANG[] = "_RO";
#else
const char LANG[] = "";
#endif
#endif

char update_url[128] = "esp.3dstar.ro/";

char LOC[32] = "home/";
char TIP[32] = "gateway/";
char NAME[32] = "espnow";
char XTRA[32] = "";

bool heartbeat = false;
uint8_t heartbeat_minutes = 60;
unsigned long last_heartbeat = 0;
///////////////////////////////////////////////////////////////////////

//

///////////////////////////////////////////////////////////////////////
// MQTT
///////////////////////////////////////////////////////////////////////
char MQTT_HOST[128] = "mqtt.3dstar.ro";
int MQTT_PORT = 1883;
char MQTT_USER[32] = "test";
char MQTT_PASS[64] = "12345678";

char WILL[32] = "/will";
char PUB[32] = "/msgs";
char SUB[32] = "/cmnd";
char STAT[32] = "/stat";
///////////////////////////////////////////////////////////////////////

//

///////////////////////////////////////////////////////////////////////
// ESP-Now bridge
///////////////////////////////////////////////////////////////////////
uint8_t enb_accolade = 0;            // number of opened accolades
uint8_t enb_position = 0;            // position in rx buffer
char enb_buffer[256];                // rx buffer for relaying
unsigned int enb_accolade_start = 0; // time last message started
bool enb_during_message = false;     // flag that we are in the middle of a message
uint16_t enb_max_time = 2000;        // max 2 seconds to finish message
///////////////////////////////////////////////////////////////////////

//

///////////////////////////////////////////////////////////////////////
// Let's Encrypt CA certificate for SSL
// it will authenticate any valid Let's Encrypt issued cert
///////////////////////////////////////////////////////////////////////
#ifdef USE_SSL
static const char digicert[] PROGMEM = R"EOF(
-----BEGIN CERTIFICATE-----
MIIEZTCCA02gAwIBAgIQQAF1BIMUpMghjISpDBbN3zANBgkqhkiG9w0BAQsFADA/
MSQwIgYDVQQKExtEaWdpdGFsIFNpZ25hdHVyZSBUcnVzdCBDby4xFzAVBgNVBAMT
DkRTVCBSb290IENBIFgzMB4XDTIwMTAwNzE5MjE0MFoXDTIxMDkyOTE5MjE0MFow
MjELMAkGA1UEBhMCVVMxFjAUBgNVBAoTDUxldCdzIEVuY3J5cHQxCzAJBgNVBAMT
AlIzMIIBIjANBgkqhkiG9w0BAQEFAAOCAQ8AMIIBCgKCAQEAuwIVKMz2oJTTDxLs
jVWSw/iC8ZmmekKIp10mqrUrucVMsa+Oa/l1yKPXD0eUFFU1V4yeqKI5GfWCPEKp
Tm71O8Mu243AsFzzWTjn7c9p8FoLG77AlCQlh/o3cbMT5xys4Zvv2+Q7RVJFlqnB
U840yFLuta7tj95gcOKlVKu2bQ6XpUA0ayvTvGbrZjR8+muLj1cpmfgwF126cm/7
gcWt0oZYPRfH5wm78Sv3htzB2nFd1EbjzK0lwYi8YGd1ZrPxGPeiXOZT/zqItkel
/xMY6pgJdz+dU/nPAeX1pnAXFK9jpP+Zs5Od3FOnBv5IhR2haa4ldbsTzFID9e1R
oYvbFQIDAQABo4IBaDCCAWQwEgYDVR0TAQH/BAgwBgEB/wIBADAOBgNVHQ8BAf8E
BAMCAYYwSwYIKwYBBQUHAQEEPzA9MDsGCCsGAQUFBzAChi9odHRwOi8vYXBwcy5p
ZGVudHJ1c3QuY29tL3Jvb3RzL2RzdHJvb3RjYXgzLnA3YzAfBgNVHSMEGDAWgBTE
p7Gkeyxx+tvhS5B1/8QVYIWJEDBUBgNVHSAETTBLMAgGBmeBDAECATA/BgsrBgEE
AYLfEwEBATAwMC4GCCsGAQUFBwIBFiJodHRwOi8vY3BzLnJvb3QteDEubGV0c2Vu
Y3J5cHQub3JnMDwGA1UdHwQ1MDMwMaAvoC2GK2h0dHA6Ly9jcmwuaWRlbnRydXN0
LmNvbS9EU1RST09UQ0FYM0NSTC5jcmwwHQYDVR0OBBYEFBQusxe3WFbLrlAJQOYf
r52LFMLGMB0GA1UdJQQWMBQGCCsGAQUFBwMBBggrBgEFBQcDAjANBgkqhkiG9w0B
AQsFAAOCAQEA2UzgyfWEiDcx27sT4rP8i2tiEmxYt0l+PAK3qB8oYevO4C5z70kH
ejWEHx2taPDY/laBL21/WKZuNTYQHHPD5b1tXgHXbnL7KqC401dk5VvCadTQsvd8
S8MXjohyc9z9/G2948kLjmE6Flh9dDYrVYA9x2O+hEPGOaEOa1eePynBgPayvUfL
qjBstzLhWVQLGAkXXmNs+5ZnPBxzDJOLxhF2JIbeQAcH5H0tZrUlo5ZYyOqA7s9p
O5b85o3AM/OJ+CktFBQtfvBhcJVd9wvlwPsk+uyOy2HI7mNxKKgsBTt375teA2Tw
UdHkhVNcsAKX1H7GNNLOEADksd86wuoXvg==
-----END CERTIFICATE-----
)EOF";
#endif
///////////////////////////////////////////////////////////////////////
