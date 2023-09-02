#include <Wire.h>
#define buttonPin1  2
#define buttonPin2  3

void setup()
{
  Wire.begin();        
  pinMode(buttonPin1, INPUT);
  pinMode(buttonPin2, INPUT);
  Serial.begin(9600);
}

void loop() {
  int buttonState1 = digitalRead(buttonPin1);
  int buttonState2 = digitalRead(buttonPin2);
  
  if (buttonState1 == HIGH && buttonState2 == HIGH)
  {
    int x=1;
    Wire.beginTransmission(8);
    Wire.write(x);    
    Wire.endTransmission();
    Serial.println("Sending 1");
  }
  else if (buttonState1 == HIGH)
  {
    int x=2;
    Wire.beginTransmission(8);
    Wire.write(x);    
    Wire.endTransmission();
    Serial.println("Sending 2");
  }
  else if (buttonState2 == HIGH)
  {
    int x=3;
    Wire.beginTransmission(8);
    Wire.write(x);    
    Wire.endTransmission();
    Serial.println("Sending 3");
  }
  delay(100); 
}
