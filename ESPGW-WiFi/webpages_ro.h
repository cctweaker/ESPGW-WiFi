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
<a href="https://3dstar.ro/proiecte/esplights">ESPlights</a> -
<a href="https://github.com/cctweaker/ESPlights">GitHub</a>
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
<br><br><h3>Pagina nu a fost găsită<br><br>Apasa Inapoi sau asteapta ca pagina sa se reincarce.</h3><br><br>
)=====";

const char page_content_restart[] PROGMEM = R"=====(
<br><br><h3>Repornire dispozitiv<br><br>Apasa Inapoi sau asteapta ca pagina sa se reincarce.</h3><br><br>
)=====";

const char page_content_erase_settings[] PROGMEM = R"=====(
<br><br><h3>Configuratia a fost stearsa!<br><br>
Configuratia actuala este inca in memorie, inainte de repornire salveaza cel putin datele WiFi pentru a pastra conectivitatea.<br><br>
Apasa Inapoi sau asteapta ca pagina sa se reincarce.</h3><br><br>
)=====";

const char page_content_update[] PROGMEM = R"=====(
<br><br><h3>Actualizare firmware...<br><br>
Apasa Inapoi sau asteapta ca pagina sa se reincarce.</h3>
Actualizarea dureaza aproximativ 30-40 secunde.<br><br>
)=====";

const char page_content_main_menu_button[] PROGMEM = R"=====(
<form action="/"><input type="submit" value="Meniu principal"></form>
)=====";

const char form_buttons[] PROGMEM = R"=====(
<input type="submit" value="Aplica"><br><br><input type="submit" name="save" value="Salveaza configuratia"></form>
<br><form action="/"><input type="submit" value="Inapoi"></form><br>
)=====";

const char save_to_config[] PROGMEM = R"=====(
<hr>Salvare configuratie: 
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
%s<br><select name="%s"><option value="1" %s>da</option><option value="0" %s>nu</option></select><br><br>
)=====";

const char form_add_del_field[] PROGMEM = R"=====(
<input type="submit" name="%sadd" value="Adauga"><input type="submit" name="%sdel" value="Scade"><br><br>
)=====";

const char form_light_field[] PROGMEM = R"=====(
Lumini canal %d: <input type="text" name="light%d" value="%d" minlength="1" size="1"><br>
)=====";

const char form_simple_field[] PROGMEM = R"=====(
Normale canal %d: <input type="text" name="simple%d" value="%d" minlength="1" size="1"><br>
)=====";

const char form_shutter_up_field[] PROGMEM = R"=====(
canal SUS: <input type="text" name="shup%d" value="%d" minlength="1" size="1"><br>
)=====";

const char form_shutter_down_field[] PROGMEM = R"=====(
canal JOS: <input type="text" name="shdw%d" value="%d" minlength="1" size="1"><br>
)=====";

const char form_shutter_tmt_field[] PROGMEM = R"=====(
temporizare: <input type="text" name="shtmt%d" value="%d" minlength="1" size="1"><br>
)=====";

const char form_timed_field[] PROGMEM = R"=====(
Canal: <input type="text" name="timed%d" value="%d" minlength="1" size="1"><br>
)=====";

const char form_timed_tmt_field[] PROGMEM = R"=====(
temporizare: <input type="text" name="timedtmt%d" value="%d" minlength="1" size="1"><br>
)=====";

const char form_timeout_select[] PROGMEM = R"=====(
Units: <select name="%s%d">
<option value="1" %s>millisecunde</option>
<option value="1000" %s>secunde</option>
<option value="60000" %s>minute</option>
<option value="3600000" %s>ore</option>
<option value="86400000" %s>zile</option>
</select><br><br>
)=====";

const char form_expander_field[] PROGMEM = R"=====(
Canal %d catre: <input type="text" name="exp%d" value="%d" minlength="1" size="1"><br>
)=====";

const char form_end[] PROGMEM = R"=====(
</form>
)=====";

const char menu_entry[] PROGMEM = R"=====(
<form action="%s"><input type="submit" value="%s" %s></form><br>
)=====";

const char menu_entry_scan_wifi[] PROGMEM = R"=====(
<form><input type="submit" name="scan" value="Scanare WiFi"></form><br>
)=====";

const char menu_entry_reload_page[] PROGMEM = R"=====(
<form><input type="submit" value="Reincarcare pagina"></form><br>
)=====";

const char menu_entry_check_restart[] PROGMEM = R"=====(
onSubmit="if(!confirm(\'Confirmi repornirea dispozitivului?\')){return false;}"
)=====";

const char menu_entry_check_erase[] PROGMEM = R"=====(
onSubmit="if(!confirm(\'Confirmi stergerea configurarilor?\')){return false;}"
)=====";

const char menu_entry_check_update[] PROGMEM = R"=====(
onSubmit="if(!confirm(\'Confirmi efectuarea actualizarii de firmware?\')){return false;}"
)=====";

const char littlefs_failure[] PROGMEM = R"=====(
Eroare LittleFS!
)=====";

const char file_write_failure[] PROGMEM = R"=====(
Eroare scriere fisier!
)=====";

const char file_write_success[] PROGMEM = R"=====(
Scriere fisier cu succes.
)=====";

const char expander_mcp23017[] PROGMEM = R"=====(
Multiplicator de porturi MCP23017, 16 canale disponibile.<br>
)=====";

const char expander_pca9557[] PROGMEM = R"=====(
Multiplicator de porturi PCA9557, 8 canale disponibile.<br>
)=====";

const char expander_pca9536[] PROGMEM = R"=====(
Multiplicator de porturi PCA9536, 4 canale disponibile.<br>
)=====";

const char light_channels[] PROGMEM = R"=====(
<b>Canale Lumina</b><br>
)=====";

const char simple_channels[] PROGMEM = R"=====(
<b>Canale Normale</b><br>
)=====";

const char shutter_channels[] PROGMEM = R"=====(
<b>Canale Jaluzea</b><br>
)=====";

const char shutter_number[] PROGMEM = R"=====(
Jaluzea %d<br>
)=====";

const char timed_channels[] PROGMEM = R"=====(
<b>Canale Temporizate</b><br>
)=====";

const char timed_number[] PROGMEM = R"=====(
Temporizat %d<br>
)=====";

const char menu_entry_device[] PROGMEM = R"=====(
Dispozitiv
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
Canale
)=====";

const char menu_entry_light_channels[] PROGMEM = R"=====(
Canale lumini
)=====";

const char menu_entry_simple_channels[] PROGMEM = R"=====(
Canale normale
)=====";

const char menu_entry_shutter_channels[] PROGMEM = R"=====(
Canale jaluzele
)=====";

const char menu_entry_timed_channels[] PROGMEM = R"=====(
Canale temporizate
)=====";

const char menu_entry_expander[] PROGMEM = R"=====(
Multiplicator IO
)=====";

const char menu_entry_update[] PROGMEM = R"=====(
Actualizare firmware
)=====";

const char menu_entry_erase[] PROGMEM = R"=====(
Stergere configuratie
)=====";

const char menu_entry_restart[] PROGMEM = R"=====(
Repornire
)=====";

const char menu_entry_sysinfo[] PROGMEM = R"=====(
Informatii sistem
)=====";

const char txt_loc[] PROGMEM = R"=====(
LOC
)=====";

const char txt_tip[] PROGMEM = R"=====(
TIP
)=====";

const char txt_name[] PROGMEM = R"=====(
NUME
)=====";

const char txt_xtra[] PROGMEM = R"=====(
sufix NUME
)=====";

const char txt_mqtt_main_topic[] PROGMEM = R"=====(
Topicul MQTT va fi urmatorul<br><input type="text" disabled" value="%s%s%s%s"><br><br>
)=====";

const char txt_invert_outputs[] PROGMEM = R"=====(
Iesire pentru relee?
)=====";

const char txt_update_url[] PROGMEM = R"=====(
URL actualizare
)=====";

const char txt_heartbeat[] PROGMEM = R"=====(
Informatii periodice
)=====";

const char txt_heartbeat_minutes[] PROGMEM = R"=====(
Perioada (minute)
)=====";

const char txt_start_webserver[] PROGMEM = R"=====(
Pornire server web
)=====";

const char txt_start_espnow[] PROGMEM = R"=====(
Pornire punte ESP-Now
)=====";

const char txt_ssl_supported[] PROGMEM = R"=====(
Acest firmware suporta conexiuni SSL!
)=====";

const char txt_mqtt_host[] PROGMEM = R"=====(
MQTT server/ip
)=====";

const char txt_mqtt_port[] PROGMEM = R"=====(
MQTT port
)=====";

const char txt_mqtt_user[] PROGMEM = R"=====(
MQTT utilizator
)=====";

const char txt_mqtt_pass[] PROGMEM = R"=====(
MQTT parola
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
Pornire MQTT<br>(necesita WiFi)
)=====";

const char txt_enb_max_time[] PROGMEM = R"=====(
Temporizare (ms)<br>pana la respingerea mesajului
)=====";

const char txt_chn_to_expander[] PROGMEM = R"=====(
<b>Numar canal catre<br>pini fizici multiplicator</b><br><br>
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
<br><br><form action='/'><input type='submit' value='Inapoi'></form>
)=====";