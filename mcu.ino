#include <WiFi.h>

const char* ssid = "COMTECO-95158360";
const char* password = "70415428";

const uint16_t port = 10000;
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
    delay(5000);
    WiFiClient client;
    Serial.println("Connected to");
    client.println(host);
    if (!client.connect(host, port)) {
 
        Serial.println("Connection to host failed");
 
        delay(1000);
        return;
    }
    unsigned long timeout = millis();
    while (client.available() == 0) 
    {
      if (millis() - timeout > 10000) {
        Serial.println("Client timeout!");
        client.stop();
        return;
      }
    }


    while(client.available() > 0){
      String line = client.readStringUntil('\r');
      Serial.println("recibido");
      Serial.println(line);

    }
 
    
    Serial.println("Disconnecting...");
    client.stop();
 
}