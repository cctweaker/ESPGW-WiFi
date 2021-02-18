# ESPGW-WiFi

is part of the ESP-Now gateway and runs on any ESP8266 device. It is designed to receive json packets from the ESP-Now half of the gateway using the serial port then then send them out through MQTT.

The other half of the software is <a href="https://github.com/cctweaker/ESPGW-Now">ESPGW-Now</a>, it will pick up json messages from ESP-Now buttons, environment sensors, door or window sensors etc.

ESP-Now devices are able to send a message in about 60ms then go back to sleep. The same sensor, using secure MQTT, takes 10-20 seconds to power up, connect to a secure MQTT server and send a message. This translates to more than 10 fold power savings and the self discharge rate of the battery becomes more important now.
Total power on duration of the ESP8266 to complete one ESP-Now transmission is about 200ms.

ESP-Now is great for battery operated sensors, especially if you have a bunch of them. The gateway is always on and mains powered so it can route messages to MQTT instantly. Messages are easily dealt with and can be separated by type, name and device ID.

From tests I can estimate that a 2500mAh battery can support a SI7021 sensor with ESP-Now transmission for about 3 years at a message rate of 1 per 5 minutes. This will vary depending on the self-discharge rate of the used battery.


# Features
- perfect for infrequent small data transmissions
- no need for full blown WiFi on each device, ESP-Now devices connect and transmit data instantly
- much faster than other solutions that rely on Wifi
- lower total power consumption, great for battery operated sensors/buttons
- creates a parallel network for IoT without hoarding your DHCP leases or WiFi (just the gateway is connected)


# Build
Clone in PlatformIO or download the archive and extract main source folder to your Arduino projects folder.

# Setup
On the first powerup a WiFi access point is presented. If using the default configuration, it is called "ESPGW-WiFi_XXXXXX". Default password is abcd1234. Connect to it and you should arrive at the configuration page. If you are not automagically redirected (it's called a sign in page) then you can point your browser to http://192.168.10.1/

- [Device] menu will allow you to change LOC, TIP, NAME, NAME suffix variables (these make up the MQTT topic), update URL (if you want to set up your own server for updates), MQTT heartbeat on/off and period and if the webserver should be started.
- [WIFI] menu will let you scan for WiFi networks and set up credentials for both primary and secondary networks. The second one is recommended to be set to your phone's hotspot in case you change the main Wifi network credentials.
- [MQTT] menu is used to set up your MQTT connection
- [Gateway] menu is used to start relaying the messages to MQTT and set the RX buffer timeout in ms. The timeout is used to purge the buffer in case an incomplete message is received from ESP-Now. The software checks for <code>{</code> to mark the start of a message and for <code>}</code> to mark the end of a message. You can open as many accolades but you need to close them too for the message to be considered complete. If the last accolade is missing, the buffer will be deleted in "timeout" ms. Use 2000 for a small network and 500-1000 in a busy network.
- [Update firmware] - self explanatory, you can use your own server (defined under Device menu) or the official release channel as defined in the firmware.
- [Erase settings] menu will delete all configuration files stored on the ESP but will not restart the device. Menus will still show the current settings from active memory. Use this trick to save at least the Wifi settings then restart. If you restart without saving WiFi credentials then it will behave like a new device.
- [Restart] - reboots the device
- [System information] - shows some infos about the device

# Hardware
Roll your own by cross-connecting RX and TX from two ESP8266 devices. GND pin must be common if not powered from the same source.
See the hardware folder for the current version.

# Usage
- MQTT topic: <code>LOC/TIP/NAME</code> where LOC, TIP & NAME are user defined. What follows are possible suffixes and they will be added after the mqtt topic.
- command topic: <code>/cmnd/...</code>
    - <code>/update</code>: perform OTA update
    - <code>/reset</code>: restart ESP device
    - <code>/webserver</code>: activate (1)/deactivate (0) the webserver. /reset afterwards for changes to take effect.
- status topic: <code>/stat</code> where the ESP sends periodic updates (heartbeats) with useful information.
- will topic: <code>/will</code> Payload is 1 when device is ON and 0 when powered OFF

# Libraries
- https://github.com/256dpi/arduino-mqtt
- https://github.com/bblanchon/ArduinoJson