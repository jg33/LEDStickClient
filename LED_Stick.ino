// This #include statement was automatically added by the Spark IDE.
#include "neopixel/neopixel.h"

#define PIXEL_PIN D2
#define PIXEL_COUNT 60
#define PIXEL_TYPE WS2812B

UDP osc;

IPAddress myIP;
int myPort = 8888;

Adafruit_NeoPixel lights = Adafruit_NeoPixel(PIXEL_COUNT, PIXEL_PIN, PIXEL_TYPE);

int idleCount = 0;

IPAddress ledServerIP(192,168,0,1);
int serverPort = 8888;

void setup() {
    //myIP= Network.localIP();
    Serial.begin(9600);
    Serial.println(myIP);
    osc.begin(myPort);

}

void loop() {
    
    if(osc.parsePacket()>0){
        Serial.println("OSC!");
        char msg[osc.available()];
         
        for(int i =0; i<osc.available();i++){
            msg[i] = osc.read();
        }
        
        ledServerIP = osc.remoteIP();
        
        Serial.println(msg);
    } 
    
    
    if (idleCount > 60){
        Serial.println("I am: " + myIP);
        //Serial.println("Server is: " + ledServerIP);
        idleCount = 0;
    } else {
        idleCount++;
    }

        

}