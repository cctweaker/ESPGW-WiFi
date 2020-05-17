# MODS

The default PCB allow for a few different options, please see below what needs to be populated/modded.

- ESP-01 vs ESP-01S: For ESP-01 CH_EN and RESET are bridged, eliminating the need for a resistor. ESP-01S has that resistor on the board so you can cut the trace between CH_EN and RESET pins if there are any problems.
- HLK-PM01 as power source: If powering via HLK-PM01 then Q1 (BA033CC) needs to be populated.
- HLK-PM03 as power source: A strap has to be made between 3.3V and 4-12V pins on the bottom of the PCB.
- 3.3V power source: populate the screw terminal and connect to 3.3V and GND
- 4-12V DC power source: populate the screw terminal and Q1 (BA033CC). Make sure the PCB is well ventilated if the voltage used is above 6V.

<img src="https://github.com/cctweaker/ESPGW-Now/raw/master/Hardware/ESPGW%20top.png">&nbsp;<img src="https://github.com/cctweaker/ESPGW-Now/raw/master/Hardware/ESPGW%20bottom.png">&nbsp;<img src="https://github.com/cctweaker/ESPGW-Now/raw/master/Hardware/mods.png">
