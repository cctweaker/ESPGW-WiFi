# ESPGW-WiFi

is half of a gateway to receive packets using the ESP-Now fast communication solution.
It runs on any ESP8266 device and is designed to receive json packets from the ESP-Now half of the gateway using the serial port then send them out through MQTT.

The other half of the software is <a href="https://github.com/cctweaker/ESPGW-Now">ESPGW-Now</a>, it will pick up json messages from ESP-Now buttons, environment sensors, door or window sensors etc.

ESP-Now devices are able to send a message in about 60ms then go back to sleep. The same sensor, using secure MQTT, takes 10-20 seconds to power up, connect to a secure MQTT server and send a message. This translates to more than 10 fold power savings and the self discharge rate of the battery becomes more important now.

ESP-Now is great for battery operated sensors, especially if you have a bunch of them. The gateway is always on and mains powered so it can route messages to MQTT instantly. Messages are easily dealt with and can be separated by type, name and device ID.

From tests I can estimate that a 2500mAh battery can support a SI7021 sensor with ESP-Now transmission for about 3 years at a message rate of 1 per 5 minutes. This will vary depending of the self-discharge rate of the used battery.


# Features
- perfect for infrequent small data transmissions
- no need for full blown WiFi on each device, ESP-Now devices connect and transmit data instantly (50-100ms per message)
- much faster than other solutions that rely on Wifi (secure MQTT time to first message is 15-20 seconds)
- lower total power consumption, great for battery operated sensors/buttons
- creates a parallel network for IoT without hoarding your DHCP leases or WiFi (just the gateway is connected)


# Build
Clone in PlatformIO or download archive and extract main source folder to your Arduino projects folder.

# Setup
Edit config.h to your liking.

# Hardware
Roll your own by cross-connecting RX and TX from two ESP8266 devices. GND pin must be common if not powered from the same source.
See the hardware folder for the current version.

# Libraries
<a href="https://github.com/256dpi/arduino-mqtt">MQTT library by Joel Gaehwiler</a>