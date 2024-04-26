
# Smart Plant Caring

This project builds a smart plant care system using IoT for urban environments. ESP32 microcontroller with sensors monitor soil moisture and temperature, automatically controlling a water pump based on user-defined soil threshold setting. The Blynk IoT platform allows remote monitoring and control via a mobile app, displaying real-time data and enabling manual pump control and threshold slider. Users can receive alerts and see emoji-based plant health indicators. This system automates plant care and merges technology with traditional practices, promoting user engagement.





## Installation

Install Arduino IDE:

Download and install the latest version of the Arduino IDE on your computer.

Open the Arduino IDE and navigate to File > Preferences.
In the "Additional Boards Manager URLs" field, add the following URL: https://raw.githubusercontent.com/espressif/arduino-esp32/gh-pages/package_esp32_index.json.
Click "OK" to save the changes.

Go to Tools > Board > Boards Manager, search for "ESP32 Dev Module", and select it.

Install Blynk Library:

In the Arduino IDE, go to Sketch > Include Library > Manage Libraries.

Search for "Blynk" and install the latest version of the Blynk library.

Install Other Required Libraries:

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

Connect Hardware:

Connect the soil moisture sensor, DHT11 sensor, TFT screen and water pump to the ESP32 board using jumper wires.
Refer to the code for the pin assignments.

Configure the Project:

Open the project code in the Arduino IDE.

Update the Wi-Fi SSID, password, and Blynk authentication token in the code.

Upload the Code:

Plug the ESP32 into the computer and upload the code by pressing the upload button in the IDE. This process compiles and uploads the code to the microcontroller.

Set up the Blynk App:

Download the Blynk app from the Google Play Store (for Android) or the App Store (for iOS).

Open the Blynk app and create a new account or log in to an existing one.

Add a new project and select the "ESP32" board type.





    


## Results



