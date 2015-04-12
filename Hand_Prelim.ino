/*
Robot Hand

Created by Nick Petro
*/

#include <Servo.h>   // Library needed to use function for servomotors
#include <SoftwareSerial.h>
Servo ServoThumb, ServoIndex,
ServoMiddle, ServoAnnular, ServoPinky;
byte startPackage; // Variable that will contain the character of start package set in the GloveTX sketch, "<" 
SoftwareSerial XBee(2, 3);

int AngThumb   = 0;   // Variables with the values for the servomotors (between 0 and 180)
int AngIndex   = 0;
int AngMiddle  = 0;
int AngAnnular = 0;
int AngPinky   = 0;


void setup()
{
  Serial.begin(9600);      // Serial communication is activated at 9600 baud/s.
  XBee.begin(9600);
  ServoThumb.attach(9);  // The servomotors are asigned to the pins of the Arduino UNO board.
  delay(300);              // A delay of 300ms is set for a secure connection (this can be optional)
  ServoIndex.attach(8);   
  delay(300);
  ServoMiddle.attach(7);
  delay(300);
  ServoAnnular.attach(6);
  delay(300);
  ServoPinky.attach(5);
  delay(300);
  
  Serial.println("Ready to receive."); 
}

void loop()
{ 
  Serial.println("Before");
  //clench
  /*ServoThumb.write(20);
  delay(500);
  ServoIndex.write(15);
  delay(500);
  ServoMiddle.write(20);
  ServoAnnular.write(70);
  delay(500);
  ServoAnnular.write(10);
  delay(500);
  ServoPinky.write(160);
  delay(500);
  Serial.println("After");
  //spread
  ServoThumb.write(90);
  delay(500);
  ServoIndex.write(90);
  delay(500);
  ServoMiddle.write(130);
  delay(500);
  ServoAnnular.write(110);
  delay(500);
  ServoPinky.write(90);
  delay(500);
  Serial.println("Finished");*/
  
  if(Serial.available() > 0) {    // Waiting for data incoming from the other XBee module
     Serial.println("After");
    startPackage = Serial.read(); // The first value will be "<", the other are assigned to the finger
    AngThumb   = Serial.read();       
    AngIndex   = Serial.read();       
    AngMiddle  = Serial.read();
    AngAnnular = Serial.read();
    AngPinky   = Serial.read();
    
    Serial.print(AngThumb);
    Serial.print("\t");
    Serial.print(AngIndex);
    Serial.print("\t");
    Serial.print(AngMiddle);
    Serial.print("\t");
    Serial.print(AngAnnular);
    Serial.print("\t");
    Serial.print(AngPinky);
    Serial.print("\n");
    
    if(startPackage == '<'){   // Verifying that the first value is "<"
    
      if(AngThumb!=255)  
      ServoThumb.write(AngThumb);  // The servomotors rotates of the assigned degrees
                                                    
      if(AngIndex!=255)
      ServoIndex.write(AngIndex);
    
      if(AngMiddle!=255)
      ServoMiddle.write(AngMiddle);
    
      if(AngAnnular!=255)
      ServoAnnular.write(AngAnnular);
    
      if(AngPinky!=255)
      ServoPinky.write(AngPinky);    
    }
    
    if(XBee.available() > 0) {    // Waiting for data incoming from the other XBee module
     XBee.println("After");
    startPackage = XBee.read(); // The first value will be "<", the other are assigned to the finger
    AngThumb   = XBee.read();       
    AngIndex   = XBee.read();       
    AngMiddle  = XBee.read();
    AngAnnular = XBee.read();
    AngPinky   = XBee.read();
    
    XBee.print(AngThumb);
    XBee.print("\t");
    XBee.print(AngIndex);
    XBee.print("\t");
    XBee.print(AngMiddle);
    XBee.print("\t");
    XBee.print(AngAnnular);
    XBee.print("\t");
    XBee.print(AngPinky);
    XBee.print("\n");
    
    if(startPackage == '<'){   // Verifying that the first value is "<"
    
      if(AngThumb!=255)  
      ServoThumb.write(AngThumb);  // The servomotors rotates of the assigned degrees
                                                    
      if(AngIndex!=255)
      ServoIndex.write(AngIndex);
    
      if(AngMiddle!=255)
      ServoMiddle.write(AngMiddle);
    
      if(AngAnnular!=255)
      ServoAnnular.write(AngAnnular);
    
      if(AngPinky!=255)
      ServoPinky.write(AngPinky);    
    }
  }
  delay(30); // a delay to make the servomotors working correctly (a lower value could make the system not working, higher value make it slower)
}  
}
