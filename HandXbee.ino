/*
Robot Hand (For PowerGlove)
Created by Nick Petro
*/

#include <Servo.h>
#include <SoftwareSerial.h>
SoftwareSerial XBee(2, 3);
Servo ServoThumb, ServoIndex,
ServoMiddle, ServoAnnular, ServoPinky;
byte startPackage; 

int AngThumb   = 0;
int AngIndex   = 0;
int AngMiddle  = 0;
int AngAnnular = 0;
int AngPinky   = 0;


void setup()
{
  XBee.begin(9600);
  Serial.begin(9600); 
  
  ServoThumb.attach(9);
  delay(300);
  ServoIndex.attach(8);   
  delay(300);
  ServoMiddle.attach(7);
  delay(300);
  ServoAnnular.attach(6);
  delay(300);
  ServoPinky.attach(5);
  delay(300);
  
  Serial.println("Ready to recieve");
}

void loop(){   
  /*if (Serial.available()) { // If data comes in from serial monitor, send it out to XBee
    XBee.write(Serial.read());
  }
  if (XBee.available()) { // If data comes in from XBee, send it out to serial monitor
    Serial.write(XBee.read());
  }*/
  
  if(XBee.available()) {
  
    startPackage = XBee.read();
    AngThumb   = XBee.read();       
    AngIndex   = XBee.read();       
    AngMiddle  = XBee.read();
    AngAnnular = XBee.read();
    AngPinky   = XBee.read();
    //AngPinky   = 180-AngPinky;
    
    if(startPackage == '<') {
    
      if(AngThumb!=-1){ServoThumb.write(AngThumb);}
      if(AngIndex!=-1){ServoIndex.write(AngIndex);}
      if(AngMiddle!=-1){ServoMiddle.write(AngMiddle);}
      if(AngAnnular!=-1){ServoAnnular.write(AngAnnular);}
      if(AngPinky!=-1){ServoPinky.write(180-AngPinky);}
      
      /*if(AngThumb!=-1){
        if(AngThumb > 100){AngThumb = 100;}
         ServoThumb.write(AngThumb);}
      if(AngIndex!=-1){
        if(AngIndex > 110){AngIndex = 110;}
        ServoIndex.write(AngIndex);}
      if(AngMiddle!=-1){
        if(AngMiddle > 130){AngMiddle = 130;}
        ServoMiddle.write(AngMiddle);}
      if(AngAnnular!=-1){
        if(AngAnnular > 125){AngAnnular = 125;}
        ServoAnnular.write(AngAnnular);}
      if(AngPinky!=-1 && AngPinky < 180){
        if(AngPinky > 110){AngPinky = 110;}
        ServoPinky.write(180-AngPinky);}*/
        
    Serial.print(AngThumb);
    Serial.print("\t");
    Serial.print(AngIndex);
    Serial.print("\t");
    Serial.print(AngMiddle);
    Serial.print("\t");
    Serial.print(AngAnnular);
    Serial.print("\t");
    Serial.print(AngPinky);
    Serial.print("\t");
    Serial.print("\n");
      
    }
  }
  delay(30);
}            
