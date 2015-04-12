/*
Flex Glove (For PowerGlove)
Created by Nick Petro
*/

int ResThumb   = A4;
int ResIndex   = A3;
int ResMiddle  = A2;
int ResAnnular = A1;
int ResPinky   = A0;

int OpenedThumb   =0;
int OpenedIndex   =0;
int OpenedMiddle  =0;
int OpenedAnnular =0;
int OpenedPinky   =0;

int ClosedThumb;
int ClosedIndex;
int ClosedMiddle;
int ClosedAnnular;
int ClosedPinky;

int thumb   =0;
int index   =0;
int middle  =0;
int annular =0;
int pinky   =0;


void setup()
{
  Serial.begin(9600);
  
  pinMode(ResThumb,   INPUT);
  pinMode(ResIndex,   INPUT);
  pinMode(ResMiddle,  INPUT);
  pinMode(ResAnnular, INPUT);
  pinMode(ResPinky,   INPUT);

  ClosedThumb   = analogRead(ResThumb);
  ClosedIndex   = analogRead(ResIndex);  
  ClosedMiddle  = analogRead(ResMiddle); 
  ClosedAnnular = analogRead(ResAnnular);
  ClosedPinky   = analogRead(ResPinky);  
}

void loop()
{
  thumb   = analogRead(ResThumb);  
  index   = analogRead(ResIndex);  
  middle  = analogRead(ResMiddle); 
  annular = analogRead(ResAnnular);
  pinky   = analogRead(ResPinky);  
  
  if(thumb   > OpenedThumb)
  OpenedThumb   = thumb;
  if(index   > OpenedIndex)
  OpenedIndex   = index;
  if(middle  >  OpenedMiddle)
  OpenedMiddle  = middle;
  if(annular > OpenedAnnular)
  OpenedAnnular = annular;
  if(pinky   > OpenedPinky)
  OpenedPinky   = pinky;
  
  if(thumb   < ClosedThumb)
  ClosedThumb   = thumb;
  if(index   < ClosedIndex)
  ClosedIndex   = index;
  if(middle  < ClosedMiddle)
  ClosedMiddle  = middle;
  if(annular < ClosedAnnular)
  ClosedAnnular = annular;
  if(pinky   < ClosedPinky)
  ClosedPinky   = pinky;
  
  thumb   = map(thumb  ,ClosedThumb  ,OpenedThumb  ,0,100);  
  index   = map(index  ,ClosedIndex  ,OpenedIndex  ,0,110);
  middle  = map(middle ,ClosedMiddle ,OpenedMiddle ,0,140); 
  annular = map(annular,ClosedAnnular,OpenedAnnular,0,120);
  pinky   = map(pinky  ,ClosedPinky  ,OpenedPinky  ,0,110);
  
  /*thumb   = map(thumb  ,ClosedThumb  ,OpenedThumb  ,0,180);  
  index   = map(index  ,ClosedIndex  ,OpenedIndex  ,0,180);
  middle  = map(middle ,ClosedMiddle ,OpenedMiddle ,0,180); 
  annular = map(annular,ClosedAnnular,OpenedAnnular,0,180);
  pinky   = map(pinky  ,ClosedPinky  ,OpenedPinky  ,0,180);*/
  
  Serial.write("<");
  Serial.write(thumb);
  Serial.write(index); 
  Serial.write(middle);
  Serial.write(annular);
  Serial.write(pinky);
  
  delay(30);
}
