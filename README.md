# ESPGW-WiFi

is half of a gateway to receive packets using the ESP-Now fast communication solution.
It runs on any ESP8266 device and is designed to receive json packets from the ESP-Now half of the gateway using the serial port then send them out through MQTT.

The other half of the software is <a href="https://github.com/cctweaker/ESPGW-Now">ESPGW-Nowi</a>, it will pick up json messages from ESP-Now buttons, sensors, etc.


# Features
- perfect for infrequent small data transmissions
- no need for full blown WiFi on each device, connects and transmits data instantly
- much faster than other solutions that rely on Wifi
- lower total power consumption, great for battery operated sensors/buttons
- creates a parallel network for IoT without hoarding your DHCP leases or WiFi (just the gateway is connected)


# Build
Clone in PlatformIO or download archive and extract main source folder to your Arduino projects folder.
It depends on <a href="https://github.com/256dpi/arduino-mqtt">MQTT library by Joel Gaehwiler</a>.

# Setup
Rename example_private.h to private.h and edit to you liking.

# Hardware
Roll your own by cross-connecting RX and TX from two ESP8266 devices. GND pin must be common if not powered from the same source.
See the hardware folder for the current version.
