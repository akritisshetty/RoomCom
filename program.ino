#include <WiFi.h>
#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <DHT_U.h>
#include <WebServer.h>

const char* ssid = "Nikki"; //your username
const char* password = "raksh178"; //your password
#define DHTPIN 23 
#define DHTTYPE DHT11
#define LED_PIN 2   
DHT dht(DHTPIN, DHTTYPE);
WiFiServer server(80);
void setup() {
  Serial.begin(115200);
  dht.begin();
  delay(100);
  pinMode(LED_PIN, OUTPUT);  
  digitalWrite(LED_PIN, LOW); 
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nConnected to Wi-Fi!");
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());
  server.begin();
}
