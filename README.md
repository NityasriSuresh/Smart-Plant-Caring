
# Smart Plant Caring

In this project a smart plant caring system using Internet of Things (IoT) technology was developed. The system leverages ESP32-based microcontroller integrated with sensors to monitor critical plant health parameters such as soil moisture and temperature. It automatically controls a water pump based on user-defined soil moisture threshold to maintain optimal plant health. The plant's well being can be visualized by the emojis displayed on the TFT screen.
The system utilizes the Blynk IoT platform to enable remote monitoring and control through a mobile app. Users can view real-time sensor data, adjust settings like soil moisture thresholds, manually control the water pump  and receive alerts for specific plant conditions. The application uses Wi-Fi for communication, providing a convenient way to manage plant care.

## Required Components

| Component Name | Amazon link | Specifications |
| --- | --- | --- |
| Soil Moisture Sensor | [https://a.co/d/eYazQ2j](https://a.co/d/eYazQ2j) | Operating voltage 3.3V-5V, Operating Current: 15mA, PCB size:3.2cm*1.4m, weight:7g. |
| Temperature Sensor | [https://amazon.com/HiLetgo-Temperature-Humidity-Digital-3-3V-5V/dp/B01DKC2GQ0](https://amazon.com/HiLetgo-Temperature-Humidity-Digital-3-3V-5V/dp/B01DKC2GQ0) | Operating Voltage: 3.5V to 5.5V, Operating current: 0.3mA, Temperature Range: 0°C to 50°C |
| 1.28inch TFT round LCD Screen Display | [https://www.amazon.com/round-screen-module-240x240-display/dp/B0C2JCQYK2](https://www.amazon.com/round-screen-module-240x240-display/dp/B0C2JCQYK2) | 3-5V diving voltage, Interface mode: SPI;Color: full color RGB, Display size: 32.4mmx32.4mm;Overall dimensions:38mmx45.5mmx3.2mm,Resolution:240x240 |
| Relay | [https://a.co/d/ciPGkgP](https://a.co/d/ciPGkgP) | AC 250V/10A, DC 30V/10A. trigger current 5mA. Two level trigger. |
| Water Pump | [https://a.co/d/ijglNTA](https://a.co/d/ijglNTA) | 100L /H, Diving Type, working voltage:12V DC. |
| Silicone Tube | [https://a.co/d/09qDc6e](https://a.co/d/09qDc6e) | Size: 5x7mm / 0.2"x0.28"(IDxOD); Length: 1M(3.3'); Wall Thickness: 1mm(0.04") |


## Installation

**Install Arduino IDE:**

Download and install the latest version of the Arduino IDE on your computer. https://www.arduino.cc/en/software

Open the Arduino IDE and navigate to File > Preferences.
In the "Additional Boards Manager URLs" field, add the following URL: https://raw.githubusercontent.com/espressif/arduino-esp32/gh-pages/package_esp32_index.json.
Click "OK" to save the changes.

Go to Tools > Board > Boards Manager, search for "ESP32 Dev Module", and select it.

**Install Blynk Library:**

In the Arduino IDE, go to Sketch > Include Library > Manage Libraries.

Search for "Blynk" and install the latest version of the Blynk library.

**Install Other Required Libraries:**

In the Arduino IDE, go to Sketch > Include Library > Manage Libraries.

Search for and install the following libraries:

•	DHT Sensor Library

•	TFT_eSPI

•	PNGdec

Include the following header files along with PNG image header files

•	WiFi.h

•	BlynkSimpleEsp32.h

•	DHT.h

•	TFT_eSPI.h

•	PNGdec.h

•	cold.h

•	happy.h

•	hot.h

•	thirsty.h

**Connect Hardware:**

Connect the soil moisture sensor, DHT11 sensor, TFT screen and water pump to the ESP32 board using jumper wires.
Refer to the code for the pin assignments.

**Configure the Project:**

Open the project code in the Arduino IDE.

Update the Wi-Fi SSID, password, and Blynk authentication token in the code.

**Upload the Code:**

Plug the ESP32 into the computer and upload the code by pressing the upload button in the IDE. This process compiles and uploads the code to the microcontroller.

**Set up the Blynk App:**

Download the Blynk app from the Google Play Store (for Android) or the App Store (for iOS).

https://play.google.com/store/apps/details?id=cloud.blynk&hl=en_US&gl=US

Open the Blynk app and create a new account or log in to an existing one.

Add a new project and select the "ESP32" board type.

To know more about Blynk IOT platform read https://docs.blynk.io/en

## System Architechture

The DHT11 temperature sensor should be connected to the GPIO 14 pin of ESP32.DHT sensors are digital sensors, and they use single data pin for communication. The resistive soil moisture sensor uses analog communication to send data, which must be connected to the GPIO 26 pin of ESP32. The relay module of the pump must be connected to GPIO 32 pin of ESP32. Then VCC and ground of the sensors and relay module must be connected to 5V and ground of ESP32 respectively. The motor pump is connected to the relay with the help of 12 V battery.

The VCC power supply of the TFT display was connected to 5V supply of ESP32, while the TFT ground was connected to ESP32 ground. The DIN/SDA (data/serial data) and CLK/SCK/SCL (clock) pins of the display should be connected to GPIO 23 and GPIO 18 of the ESP32, respectively. The CS (chip select) pin of the display should be connected to GPIO 15 of the ESP32, while the DC (data command) pin should be connected to GPIO 2, and the RST (reset) pin to GPIO 4.The BL (backlight) of TFT display need not be connected.

![sysarchi](https://github.com/NityasriSuresh/Smart-Plant-Caring/assets/142957652/d5368688-6f07-4d5f-a5b9-8f76aed5b976)

## Code Logic 

![flow](https://github.com/NityasriSuresh/Smart-Plant-Caring/assets/142957652/2d8baa45-4d9d-4261-8115-b0f6b32fc8df)


## Result

![results](https://github.com/NityasriSuresh/Smart-Plant-Caring/assets/142957652/f63a1e3b-e954-4dea-b463-9a4d0ec9ce59)

 

