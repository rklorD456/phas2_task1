#include <Wire.h>
#define ledPin 11  
int x = 0;

void setup()
{
  Wire.begin(8);             
  Wire.onReceive(receiveEvent); 
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void receiveEvent(int bytes)
{
  x = Wire.read();  // Assign the received value to the global variable x
}

void loop()
{
  int ledIntensity = 0;
  String message = "No message";
    
  if (x == 2)
  {
    ledIntensity = 128;  // 50% intensity
    message = "Vector focused";
  } 
  else if (x == 3) 
  {
    ledIntensity = 192;  // 75% intensity
    message = "Vector distracted";
  }
  else if (x == 1)
  {
    ledIntensity = 255;  // 100% intensity
    message = "Glitch";
  }
    
  analogWrite(ledPin, ledIntensity);
  Serial.println(message);
}