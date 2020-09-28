#include <WiFi.h>

const char* ssid = "COMTECO-95158360";
const char* password = "70415428";

const uint16_t port = 8090;
const char* host = "192.168.1.72";
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
    delay(5000)
    WiFiClient client;

    if (!client.connect(host, port)) {
 
        Serial.println("Connection to host failed");
 
        delay(1000);
        return;
    }
    unsigned long timeout = millis();
    while (client.available() == 0) 
    {
      if (millis() - timeout > 2000) {
        Serial.println("Client timeout!");
        Serial.println("Connected to server successful!");
        client.print("Hello from ESP32! jojojoj");
        client.stop();
        return;
      }
    }


    if(client.available() > 0){
      String line = client.readStringUntil('\n');
      Serial.print("recibido")
      Serial.print(line);

    }
 
    
    Serial.println("Disconnecting...");
    client.stop();
 
}