#define BLYNK_TEMPLATE_ID "TMPL2TMT9PQCK"
#define BLYNK_TEMPLATE_NAME "Smart Plant Caring"
#define BLYNK_AUTH_TOKEN "63BjSc2GNV9QCtZ9q8etddzqh00zwRZq"

#define BLYNK_PRINT Serial
#include <WiFi.h>
#include <BlynkSimpleEsp32.h>
#include <DHT.h>
#include<TFT_eSPI.h>
#include <PNGdec.h>
#include "cold.h" // Image is stored here in an 8-bit array
#include "happy.h"
#include "hot.h"
#include "thirsty.h"

char auth[] = BLYNK_AUTH_TOKEN;

char ssid[] = "Nityasri's S23+";  // Update with your WiFi name
char pass[] = "nityasri123";  // Update with your WiFi password

BlynkTimer timer;

#define DHTPIN 14 // Connect DHT sensor to GPIO 14 (D5) in ESP32
#define SOIL_MOISTURE_PIN 25 // Connect soil moisture sensor to GPIO 26 in ESP32
#define DHTTYPE DHT11  
#define PUMP_PIN 32

int Relay=0;
int Soil=0;

DHT dht(DHTPIN, DHTTYPE);
PNG png; // PNG decoder instance
#define MAX_IMAGE_WIDTH 240 // Adjust for your images
TFT_eSPI tft = TFT_eSPI();

int16_t xpos = 0;
int16_t ypos = 0;
int16_t tempTextX = 80; // Initialize tempTextX
int16_t tempTextY = 100; // Initialize tempText
int16_t soilMoistureTextX=80;
int16_t soilMoistureTextY=130;

void sendSensor()
{
  int soilMoisture = analogRead(SOIL_MOISTURE_PIN);  // Read from the soil moisture sensor
  float temperature = dht.readTemperature(); // Read temperature

  // Send soil moisture and temperature values to Blynk app
  Blynk.virtualWrite(V6, soilMoisture); // Send soil moisture to V6
  Blynk.virtualWrite(V7, temperature); // Send temperature to V7
}

void setup()
{
  Serial.begin(115200);
  Blynk.begin(auth, ssid, pass);
  dht.begin();
  timer.setInterval(1000L, sendSensor); // Set interval for sending sensor data to Blynk app (1 second)
  
  // Setup TFT display
  tft.begin();
  tft.fillScreen(TFT_BLACK);
 
}



void loop()
{
  Blynk.run();
  timer.run();

  int16_t rc;
  int soilMoisture = analogRead(SOIL_MOISTURE_PIN);
  float temperature = dht.readTemperature();
  Serial.println(soilMoisture);
  Serial.println(temperature);

  // Display soil moisture and temperature readings
  tft.fillScreen(TFT_BLACK); // Clear the screen before displaying readings

  tft.setTextSize(3);
  tft.setTextFont(1); // Replace 1 with your text layer font ID
  tft.setTextColor(TFT_WHITE); // Or a suitable color for text

// Clear the previous soil moisture text
int16_t moistureTextWidth = tft.textWidth("00%"); 
int16_t moistureTextHeight = tft.fontHeight();
tft.fillRect(soilMoistureTextX, soilMoistureTextY, moistureTextWidth, moistureTextHeight, TFT_BLACK);

// Print the new soil moisture text
String moistureString = String(soilMoisture);
tft.setCursor(soilMoistureTextX, soilMoistureTextY);
tft.print(moistureString);

// Clear the previous text 
int16_t textWidth = tft.textWidth("00.00°C"); 
int16_t textHeight = tft.fontHeight(); // Get the height of the text
tft.fillRect(tempTextX, tempTextY, textWidth, textHeight, TFT_BLACK);

// Print the new temperature text
String tempString = String(dht.readTemperature(), 2) + "C"; // Round to 2 decimal places
tft.setCursor(tempTextX, tempTextY);
tft.print(tempString);

delay (5000);

  if (soilMoisture > Soil) {
    rc = png.openFLASH((uint8_t *)thirsty, sizeof(thirsty), pngDraw);
    delay(500);
    Blynk.logEvent("water_alert","Soil is too dry!!");
    controlPump(true);
  }
  else if (temperature > 25) {
    rc = png.openFLASH((uint8_t *)hot, sizeof(hot), pngDraw);
    Blynk.logEvent("temperature_alert","Plant is too hot");
    controlPump(false);
  }
  else if (temperature < 20){
    rc = png.openFLASH((uint8_t *)cold, sizeof(cold), pngDraw);
    Blynk.logEvent("plant_cold","Plant is feeling cold");
    controlPump(false);
  }
  else {
    rc = png.openFLASH((uint8_t *)happy, sizeof(happy), pngDraw);
    controlPump(false);
  }

 if (rc == PNG_SUCCESS)
  {
    Serial.printf("Image specs: (%d x %d), %d bpp, pixel type: %d\n", png.getWidth(), png.getHeight(), png.getBpp(), png.getPixelType());
    tft.startWrite();
    uint32_t dt = millis();
    rc = png.decode(NULL, 0);
    Serial.print(millis() - dt);
    Serial.println("ms");
    tft.endWrite();
    delay(5000);
  }

}

void pngDraw(PNGDRAW *pDraw)
{
  uint16_t lineBuffer[MAX_IMAGE_WIDTH];
  png.getLineAsRGB565(pDraw, lineBuffer, PNG_RGB565_BIG_ENDIAN, 0xffffffff);
  tft.pushImage(xpos, ypos + pDraw->y, pDraw->iWidth, 1, lineBuffer);

}

BLYNK_WRITE(V1) {
  Relay = param.asInt();
  if (Relay == 0) {
    digitalWrite(PUMP_PIN, LOW);
  } else {
    digitalWrite(PUMP_PIN, HIGH);
  }
}

BLYNK_WRITE(V10){
  Soil = param.asInt();
}


void controlPump(bool turnOn)
{
  if (turnOn) {
    digitalWrite(PUMP_PIN, HIGH);
    delay(3000);
    digitalWrite(PUMP_PIN, LOW);
    delay(2000);
  }
  else {
    digitalWrite(PUMP_PIN, LOW);
  }
} 
