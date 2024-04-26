
# Smart Plant Caring

In this project a smart plant caring system using Internet of Things (IoT) technology was developed. The system leverages ESP32-based microcontroller integrated with sensors to monitor critical plant health parameters such as soil moisture and temperature. It automatically controls a water pump based on user-defined soil mositure threshold to maintain optimal plant health. The plant's well being can be visualized by the emojis displayed on the TFT screen.
The system utilizes the Blynk IoT platform to enable remote monitoring and control through a mobile app. Users can view real-time sensor data, adjust settings like soil moisture thresholds,manually control the water pump  and receive alerts for specific plant conditions. The application uses Wi-Fi for communication, providing a convenient way to manage plant care.




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



