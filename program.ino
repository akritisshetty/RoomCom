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
void loop() {
  float temperature = getTemperature();
  if (temperature > 24.0) {
    digitalWrite(LED_PIN, HIGH);  
  } else {
    digitalWrite(LED_PIN, LOW);   
  }
  WiFiClient client = server.available();
  if (client) {
    String htmlPage = generateHTML();
    client.println("HTTP/1.1 200 OK");
    client.println("Content-type:text/html");
    client.println();
    client.println(htmlPage);
    client.println();
    client.stop();
  }
  delay(5000);
}

float getTemperature() {
  float temp = dht.readTemperature();
  return isnan(temp) ? 0.0 : temp;
}

float getHumidity() {
  float humidity = dht.readHumidity();
  return isnan(humidity) ? 0.0 : humidity;
}
String generateHTML() {
  float temperature = getTemperature();
  float humidity = getHumidity();
  String html = "<!DOCTYPE html><html><head>";
  html += "<title>RoomCom Monitor</title>";
  html += "<meta name='viewport' content='width=device-width, initial-scale=1'>";
  html += "<script src='https://kit.fontawesome.com/be133a2ef5.js' crossorigin='anonymous'></script>";
  html += "<link rel='stylesheet' href='https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css'/>";
  html += "<style>";
  html += "body { font-family: Arial; margin: 0; transition: background 0.5s, color 0.5s; }";
  html += ".content { display: none; padding: 20px; transition: opacity 0.5s; }"; // Content hidden initially
  html += ".light { background-color: #ffffff; color: #000000; }";
  html += ".dark { background-color: #000000; color: #ffffff; }";
  html += "#topBtn { position: fixed; bottom: 20px; right: 30px; display: none; padding: 10px; font-size: 18px; }";
  html += ".icon { font-size: 24px; cursor: pointer; margin: 20px; }";
  html += "</style></head><center>";
  html += "<body class='light'>";
  html += "<h1>RoomCom Monitor</h1>";
  html += "<p>Temperature: " + String(temperature) + " &deg;C</p>";
  html += "<p>Humidity: " + String(humidity) + " %</p>";
  html += "<i class='fa fa-sun-o icon' onclick='toggleLightMode()' id='light-icon'></i>";
  html += "<i class='fa fa-moon-o icon' onclick='toggleDarkMode()' id='dark-icon' style='display:none;'></i>";
  html += "<button onclick='topFunction()' id='topBtn'>Go to Top</button>";
  html += "<script>";
  html += "function toggleLightMode() { document.body.classList.add('light'); document.body.classList.remove('dark');";
  html += "document.getElementById('light-icon').style.display = 'none'; document.getElementById('dark-icon').style.display = 'inline'; }";
  html += "function toggleDarkMode() { document.body.classList.add('dark'); document.body.classList.remove('light');";
  html += "document.getElementById('dark-icon').style.display = 'none'; document.getElementById('light-icon').style.display = 'inline'; }";
  html += "</script>";
  html += "</div></center></body></html>";
  return html;
}
