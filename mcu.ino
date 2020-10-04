#include <WiFi.h>

const char* ssid = "COMTECO-95158360";
const char* password = "70415428";

const uint16_t port = 10000;
const char* host = "192.168.1.72";
String mensaje = " ";
int size;
int LED = 2;

const int Trigger = 22;   //Pin digital 0 para el Trigger del sensor
const int Echo = 23;   //Pin digital 4 para el Echo del sensor

void setup()
{
  pinMode(Echo, INPUT);  //pin como entrada
  pinMode(Trigger, OUTPUT); //pin como salida
  digitalWrite(Trigger, LOW);//Inicializamos el pin con 0
  pinMode(LED, OUTPUT);
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
    long tiempo; //tiempo que demora en llegar el eco
    long distancia; //distancia en centimetros
    digitalWrite(Trigger, HIGH);
    delayMicroseconds(10);          //Enviamos un pulso de 10us
    digitalWrite(Trigger, LOW);
    tiempo = pulseIn(Echo, HIGH); //obtenemos el ancho del pulso
    distancia = tiempo/59;             //escalamos el tiempo a una distancia en cm

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
      if (millis() - timeout > 20000) {
        Serial.println("Client timeout!");
        client.stop();
        return;
      }
    }
    client.println("Distancia: ");
    client.println(distancia);      //Enviamos serialmente el valor de la distancia
    client.println("cm");
    client.println();
    delay(1000);          //Hacemos una pausa de 100ms

    while(client.available() > 0){

      String line = client.readStringUntil('\r');
      if(line == "ON"){
          digitalWrite(LED, HIGH);
      }  
      else{
        if(line == "OFF"){
          digitalWrite(LED,LOW);
        }
      }
      Serial.println("recibido");
      Serial.println(line);

    }
 
    
    
 
}

void readSensor(){
  
}