#include <WiFi.h>

const char* ssid = "COMTECO-95158360";
const char* password = "70415428";

const uint16_t port = 8090;
const char * host = "192.168.1.72";
String mensaje = " ";
int size;

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
    client.print("Hello from ESP32! jojojoj");
    Serial.println("Disconnecting...");
    client.stop();
 
    delay(10000);
}