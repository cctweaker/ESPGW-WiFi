const char page_header_start[] PROGMEM = R"=====(
<!DOCTYPE html>
<html lang="en">
<head>
  <title>%s</title>
  <meta name="viewport" content="width=device-width, initial-scale=1.0, maximum-scale=2.0, minimum-scale=0.10">
  <meta name='mobile-web-app-capable' content='yes'>
)=====";

const char page_header_refresh[] PROGMEM = R"=====(
<meta http-equiv="refresh" content="%d;url=/">
)=====";

const char page_header_end[] PROGMEM = R"=====(
  <meta name='theme-color' content='#000'>
  <link rel='icon' sizes='256x256' href='https://esp.3dstar.ro/favicon.png'>
</head>
<body style="background-color:#000;color:#fff;text-align:center;">
)=====";

const char page_footer[] PROGMEM = R"=====(
<hr><br><b>
<a href="https://3dstar.ro/">3DStar</a> -
<a href="https://3dstar.ro/proiecte/esp-gw">ESP-GW</a> -
<a href="https://github.com/cctweaker/ESPGW-WiFi">GitHub</a>
</b><br><br>
%s v%0.2f
<br><br>
</body>
</html>
)=====";

const char page_content_title[] PROGMEM = R"=====(
<h2>%s</h2>
)=====";

const char page_content_not_found[] PROGMEM = R"=====(
<br><br><h3>Page not found<br><br>Click button or wait for page reload.</h3><br><br>
)=====";

const char page_content_restart[] PROGMEM = R"=====(
<br><br><h3>Device restart<br><br>Click button or wait for page reload.</h3><br><br>
)=====";

const char page_content_erase_settings[] PROGMEM = R"=====(
<br><br><h3>Settings erased.<br><br>
Current settings are still in memory, please save at least the WiFi credentials to keep connectivity before restarting the device.<br><br>
Click button or wait for page reload.</h3><br><br>
)=====";

const char page_content_update[] PROGMEM = R"=====(
<br><br><h3>Performing firmware update...<br><br>
Click button or wait for page reload.</h3>
Software updates take about 30-40 seconds.<br><br>
)=====";

const char page_content_main_menu_button[] PROGMEM = R"=====(
<form action="/"><input type="submit" value="Main menu"></form>
)=====";

const char form_buttons[] PROGMEM = R"=====(
<input type="submit" value="Submit"><br><br><input type="submit" name="save" value="Save config"></form>
<br><form action="/"><input type="submit" value="Back"></form><br>
)=====";

const char save_to_config[] PROGMEM = R"=====(
<hr>Save to config file: 
)=====";

const char html_hr[] PROGMEM = R"=====(
<hr>
)=====";

const char html_br[] PROGMEM = R"=====(
<br>
)=====";

const char html_table_i[] PROGMEM = R"=====(
<table align="center"><tr>
)=====";

const char html_table_s[] PROGMEM = R"=====(
</tr></table>
)=====";

const char html_table_tr[] PROGMEM = R"=====(
</tr><tr>
)=====";

const char html_table_tr_hr[] PROGMEM = R"=====(
</tr><tr><td colspan="2"><hr></td></tr><tr>
)=====";

const char form_start[] PROGMEM = R"=====(
<form>
)=====";

const char form_text_field_string[] PROGMEM = R"=====(
%s<br><input type="text" name="%s" value="%s"><br><br>
)=====";

const char form_text_field_string_min[] PROGMEM = R"=====(
%s<br><input type="text" name="%s" value="%s" minlength="1"><br><br>
)=====";

const char form_text_field_int[] PROGMEM = R"=====(
%s<br><input type="text" name="%s" value="%d"><br><br>
)=====";

const char form_text_field_int_min[] PROGMEM = R"=====(
%s<br><input type="text" name="%s" value="%d" minlength="1"><br><br>
)=====";

const char form_text_field_hex4[] PROGMEM = R"=====(
%s<br><input type="text" name="%s" value="%04X"><br><br>
)=====";

const char form_text_field_hex6[] PROGMEM = R"=====(
%s<br><input type="text" name="%s" value="%06X"><br><br>
)=====";

const char form_select_field[] PROGMEM = R"=====(
%s<br><select name="%s">
)=====";

const char form_select_field_end[] PROGMEM = R"=====(
</select><br><br>
)=====";

const char form_option_field[] PROGMEM = R"=====(
<option value="%d">%s</option>
)=====";

const char form_option_field_selected[] PROGMEM = R"=====(
<option value="%d" selected>%s</option>
)=====";

const char form_yes_no[] PROGMEM = R"=====(
%s<br><select name="%s"><option value="1" %s>yes</option><option value="0" %s>no</option></select><br><br>
)=====";

const char form_add_del_field[] PROGMEM = R"=====(
<input type="submit" name="%sadd" value="Add"><input type="submit" name="%sdel" value="Remove"><br><br>
)=====";

const char form_light_field[] PROGMEM = R"=====(
Light %d channel: <input type="text" name="light%d" value="%d" minlength="1" size="1"><br>
)=====";

const char form_simple_field[] PROGMEM = R"=====(
Simple %d channel: <input type="text" name="simple%d" value="%d" minlength="1" size="1"><br>
)=====";

const char form_shutter_up_field[] PROGMEM = R"=====(
UP channel: <input type="text" name="shup%d" value="%d" minlength="1" size="1"><br>
)=====";

const char form_shutter_down_field[] PROGMEM = R"=====(
DOWN channel: <input type="text" name="shdw%d" value="%d" minlength="1" size="1"><br>
)=====";

const char form_shutter_tmt_field[] PROGMEM = R"=====(
Timeout: <input type="text" name="shtmt%d" value="%d" minlength="1" size="1"><br>
)=====";

const char form_timed_field[] PROGMEM = R"=====(
Channel: <input type="text" name="timed%d" value="%d" minlength="1" size="1"><br>
)=====";

const char form_timed_tmt_field[] PROGMEM = R"=====(
Timeout: <input type="text" name="timedtmt%d" value="%d" minlength="1" size="1"><br>
)=====";

const char form_timeout_select[] PROGMEM = R"=====(
Units: <select name="%s%d">
<option value="1" %s>millisecond(s)</option>
<option value="1000" %s>second(s)</option>
<option value="60000" %s>minute(s)</option>
<option value="3600000" %s>hour(s)</option>
<option value="86400000" %s>day(s)</option>
</select><br><br>
)=====";

const char form_expander_field[] PROGMEM = R"=====(
Channel %d to: <input type="text" name="exp%d" value="%d" minlength="1" size="1"><br>
)=====";

const char form_gmac_field[] PROGMEM = R"=====(
<input type="text" name="gmac%d" value="%02X" minlength="1">%s
)=====";

const char form_umac_field[] PROGMEM = R"=====(
<input type="text" name="umac%d" value="%02X" minlength="1">%s
)=====";

const char form_kok_field[] PROGMEM = R"=====(
<input type="text" name="kok%d" value="%02X" minlength="1">
)=====";

const char form_key_field[] PROGMEM = R"=====(
<input type="text" name="key%d" value="%02X" minlength="1">
)=====";

const char form_end[] PROGMEM = R"=====(
</form>
)=====";

const char menu_entry[] PROGMEM = R"=====(
<form action="%s"><input type="submit" value="%s" %s></form><br>
)=====";

const char menu_entry_scan_wifi[] PROGMEM = R"=====(
<form><input type="submit" name="scan" value="Scan WiFi"></form><br>
)=====";

const char menu_entry_reload_page[] PROGMEM = R"=====(
<form><input type="submit" value="Reload page"></form><br>
)=====";

const char menu_entry_check_restart[] PROGMEM = R"=====(
onSubmit="if(!confirm(\'Are you sure you wish to restart the device?\')){return false;}"
)=====";

const char menu_entry_check_erase[] PROGMEM = R"=====(
onSubmit="if(!confirm(\'Are you sure you wish to erase all settings?\')){return false;}"
)=====";

const char menu_entry_check_update[] PROGMEM = R"=====(
onSubmit="if(!confirm(\'Are you sure you wish to update the firmware?\')){return false;}"
)=====";

const char littlefs_failure[] PROGMEM = R"=====(
LittleFS failure!
)=====";

const char file_write_failure[] PROGMEM = R"=====(
File write failure!
)=====";

const char file_write_success[] PROGMEM = R"=====(
File write success.
)=====";

const char expander_mcp23017[] PROGMEM = R"=====(
Using MCP23017 IO expander, 16 channels available.<br>
)=====";

const char expander_pca9557[] PROGMEM = R"=====(
Using PCA9557 IO expander, 8 channels available.<br>
)=====";

const char expander_pca9536[] PROGMEM = R"=====(
Using PCA9536 IO expander, 4 channels available.<br>
)=====";

const char light_channels[] PROGMEM = R"=====(
<b>LIGHT channels</b><br>
)=====";

const char simple_channels[] PROGMEM = R"=====(
<b>SIMPLE channels</b><br>
)=====";

const char shutter_channels[] PROGMEM = R"=====(
<b>SHUTTER channels</b><br>
)=====";

const char shutter_number[] PROGMEM = R"=====(
Shutter %d<br>
)=====";

const char timed_channels[] PROGMEM = R"=====(
<b>TIMED channels</b><br>
)=====";

const char timed_number[] PROGMEM = R"=====(
Timed %d<br>
)=====";

const char menu_entry_device[] PROGMEM = R"=====(
Device
)=====";

const char menu_entry_wifi[] PROGMEM = R"=====(
WiFi
)=====";

const char menu_entry_mqtt[] PROGMEM = R"=====(
MQTT
)=====";

const char menu_entry_gateway[] PROGMEM = R"=====(
Gateway
)=====";

const char menu_entry_channels[] PROGMEM = R"=====(
Channels
)=====";

const char menu_entry_light_channels[] PROGMEM = R"=====(
Light channels
)=====";

const char menu_entry_simple_channels[] PROGMEM = R"=====(
Normal channels
)=====";

const char menu_entry_shutter_channels[] PROGMEM = R"=====(
Shutter channels
)=====";

const char menu_entry_timed_channels[] PROGMEM = R"=====(
Timed channels
)=====";

const char menu_entry_expander[] PROGMEM = R"=====(
IO Expander
)=====";

const char menu_entry_update[] PROGMEM = R"=====(
Update firmware
)=====";

const char menu_entry_erase[] PROGMEM = R"=====(
Erase settings
)=====";

const char menu_entry_restart[] PROGMEM = R"=====(
Restart
)=====";

const char menu_entry_sysinfo[] PROGMEM = R"=====(
System information
)=====";

const char txt_loc[] PROGMEM = R"=====(
LOC
)=====";

const char txt_tip[] PROGMEM = R"=====(
TIP
)=====";

const char txt_name[] PROGMEM = R"=====(
NAME
)=====";

const char txt_xtra[] PROGMEM = R"=====(
NAME suffix
)=====";

const char txt_mqtt_main_topic[] PROGMEM = R"=====(
MQTT topic will be:<br><input type="text" disabled" value="%s%s%s%s"><br><br>
)=====";

const char txt_invert_outputs[] PROGMEM = R"=====(
Relay outputs?
)=====";

const char txt_update_url[] PROGMEM = R"=====(
Update URL
)=====";

const char txt_heartbeat[] PROGMEM = R"=====(
Heartbeat
)=====";

const char txt_heartbeat_minutes[] PROGMEM = R"=====(
Heartbeat minutes
)=====";

const char txt_start_webserver[] PROGMEM = R"=====(
Start webserver
)=====";

const char txt_start_espnow[] PROGMEM = R"=====(
Start ESP-Now bridge
)=====";

const char txt_ssl_supported[] PROGMEM = R"=====(
This firmware supports SSL connections!
)=====";

const char txt_mqtt_host[] PROGMEM = R"=====(
MQTT host/ip
)=====";

const char txt_mqtt_port[] PROGMEM = R"=====(
MQTT port
)=====";

const char txt_mqtt_user[] PROGMEM = R"=====(
MQTT user
)=====";

const char txt_mqtt_pass[] PROGMEM = R"=====(
MQTT password
)=====";

const char txt_mqtt_will[] PROGMEM = R"=====(
WILL subtopic
)=====";

const char txt_mqtt_pub[] PROGMEM = R"=====(
PUB subtopic
)=====";

const char txt_mqtt_sub[] PROGMEM = R"=====(
SUB subtopic
)=====";

const char txt_mqtt_stat[] PROGMEM = R"=====(
STAT subtopic
)=====";

const char txt_mqtt_start[] PROGMEM = R"=====(
Start MQTT<br>(needs WiFi enabled)
)=====";

const char txt_enb_max_time[] PROGMEM = R"=====(
Timeout (ms)<br>until RX buffer is discarded
)=====";

const char txt_chn_to_expander[] PROGMEM = R"=====(
<b>Channel number to<br>expander physical pin</b><br><br>
)=====";

const char txt_fw_name[] PROGMEM = R"=====(
<td>FW name</td><td>%s</td>
)=====";

const char txt_fw_version[] PROGMEM = R"=====(
<td>FW version</td><td>%.2f</td>
)=====";

const char txt_fw_size[] PROGMEM = R"=====(
<td>FW size</td><td>%.2f KB</td>
)=====";

const char txt_free_flash_size[] PROGMEM = R"=====(
<td>free flash size</td><td>%.2f KB</td
)=====";

const char txt_fw_md5[] PROGMEM = R"=====(
<td>FW MD5</td><td>%s</td>
)=====";

const char txt_fw_crc[] PROGMEM = R"=====(
<td>FW CRC</td><td>%s</td>
)=====";

const char txt_core_version[] PROGMEM = R"=====(
<td>Core version</td><td>%s</td>
)=====";

const char txt_sdk_version[] PROGMEM = R"=====(
<td>SDK version</td><td>%s</td>
)=====";

const char txt_reset_reason[] PROGMEM = R"=====(
<td>Reset reason</td><td>%s</td>
)=====";

const char txt_free_heap[] PROGMEM = R"=====(
<td>Free Heap</td><td>%.2f KB</td>
)=====";

const char txt_max_free_block[] PROGMEM = R"=====(
<td>Max Free Block</td><td>%.2f KB</td>
)=====";

const char txt_heap_fragmentation[] PROGMEM = R"=====(
<td>Heap Fragmentation</td><td>%d%%</td>
)=====";

const char txt_esp_chip_id[] PROGMEM = R"=====(
<td>ESP Chip ID</td><td>%06X</td>
)=====";

const char txt_cpu_freq[] PROGMEM = R"=====(
<td>CPU frequency</td><td>%d MHz</td>
)=====";

const char txt_flash_chip_id[] PROGMEM = R"=====(
<td>Flash Chip ID</td><td>%06X</td>
)=====";

const char txt_flash_freq[] PROGMEM = R"=====(
<td>Flash frequency</td><td>%d MHz</td>
)=====";

const char txt_used_flash_size[] PROGMEM = R"=====(
<td>Used flash size</td><td>%d KB</td>
)=====";

const char txt_real_flash_size[] PROGMEM = R"=====(
<td>Flash size</td><td>%d KB</td>
)=====";

const char back_button[] PROGMEM = R"=====(
<br><br><form action='/'><input type='submit' value='Back'></form>
)=====";