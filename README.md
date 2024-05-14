# JTI_ANKLE

This project aims to design a load scale system that is placed into the bottom of the moonboot to measure the force applied, thereby monitoring the rehabilliation of ankle fractures.

This documentation provides information on the components required to build the system, how to assemble and use them.

# Set Up

## Required Components
The load scale system was designed by using the following components:
* Arduino Nano BLE 33
* SparkFun OpenLog Artemis
* SparkFun Load Cell Amplifer - HX711
* Load Sensor - 50kg
* Mini Buzzer
* Rechargeable Battery
* MicroSD Card
* USB-C Cable
* micro-USB Cable

It is recommanded to flash the code before assembling the components into the case. If you choose to do so, the following is needed:
* Pin Headers
* Breadboard and Jumper Wires
* Soldering Iron

## Firmware
The Arduino IDE must be installed (v1.6.12 or above) before flashing the Arduino programs. 

### OpenLog Artemis
Open the Arduino IDE and do the following:
* Follow the instruction: https://learn.sparkfun.com/tutorials/artemis-development-with-arduino
* Download required libraries
* Select Redboard Artemis ATP
Once the Arduino IDE has been set up, do the following:
* Connect the OpenLog to the computer and select the correct port.
* Open the file and verify. Then press the upload button.

### Arduino Nano BLE 33
Once the Arduino IDE has been set up, do the following:
* Connect the Nano to the computer and press the on board button to reset.
* Install all required libraries.
* Select Arduino Nano 33 BLE as the port
