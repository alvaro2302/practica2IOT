#include <WiFi.h>

const char* ssid = "pon ssid de la red ";
const char* password = "contraseña del wifi";

const uint16_t port = 8090;
const char * host = "192.168.1.83";


void setup()
{
 
  Serial.begin(115200);
 
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.println("...");
  }
 
  Serial.print("WiFi connected with IP: ");
  Serial.println(WiFi.localIP());
 
}

void loop()
{
    WiFiClient client;
 
    if (!client.connect(host, port)) {
 
        Serial.println("Connection to host failed");
 
        delay(1000);
        return;
    }
 
    Serial.println("Connected to server successful!");
 
    client.print("Hello from ESP32!");
 
    Serial.println("Disconnecting...");
    client.stop();
 
    delay(10000);
}