/**
 * this file is show how the Sparkfun Openlog Artemis read the data from Serial 1 and write it to the SD card
 * Author: Fei Xue
 * date: 2024-05-17
*/

#include <Arduino.h>
#include <SD.h>
#include <SPI.h>

String receivedData = ""; // use string to store the data received from Serial1
const int chipSelect = 5; // Chip select pin for the SD card module

const byte BREAKOUT_PIN_TX = 12; // Define the breakout board pin number for TX
const byte BREAKOUT_PIN_RX = 13; // Define the breakout board pin number for RX

/**
 * function for configure the Serial1 TX and RX pin
*/
void configureSerial1TxRx(void) {
  am_hal_gpio_pincfg_t pinConfigTx = g_AM_BSP_GPIO_COM_UART_TX;
  pinConfigTx.uFuncSel = AM_HAL_PIN_12_UART1TX;
  pin_config(PinName(BREAKOUT_PIN_TX), pinConfigTx);
  
  am_hal_gpio_pincfg_t pinConfigRx = g_AM_BSP_GPIO_COM_UART_RX;
  pinConfigRx.uFuncSel = AM_HAL_PIN_13_UART1RX;
  pinConfigRx.ePullup = AM_HAL_GPIO_PIN_PULLUP_WEAK; // Put a weak pull-up on the Rx pin
  pin_config(PinName(BREAKOUT_PIN_RX), pinConfigRx);
}


void setup() {
  // init serial communication
    Serial.begin(115200);

    // config serial1 tx and rx pin
    configureSerial1TxRx();

    // init serial1 communication
    Serial1.begin(115200);

    // print the setup complete message
    Serial.println("Setup complete.");

    // load the SD card
    if (!SD.begin(chipSelect)) {
        Serial.println("SD card initialization failed!");
        return;
    }
    Serial.println("SD card initialized.");
}


void loop() {

  // check if there is data available in the serial1
  if (Serial1.available()) {
    char c = Serial1.read();
    receivedData += c; // add the received character to the receivedData string

    // if the received character is a newline character, print the received data to the serial monitor
    if (c == '\n') {
        Serial.print("Received data: ");
        Serial.println(receivedData); // output the received data to the serial monitor

        // process the received data
        processData(receivedData);

        // clear the received data string
        receivedData = "";
    }
  }
}

void processData(const String &data) {
  // save the data to the SD card
  File dataFile = SD.open("data.txt", FILE_WRITE);
  if (dataFile) {
    dataFile.println(data);
    dataFile.close();
    Serial.println("Data written to SD card.");
  } else {
    Serial.println("Error opening datalog.txt");
  }
}