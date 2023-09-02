//the ultrasound 1 ,2 for 0,180
//the ultrasound 3,4 for 90,270
const int trigPin1 = 2;
const int echoPin1 = 3;
const int trigPin2 = 4;
const int echoPin2 = 5;
const int trigPin3 = 6;
const int echoPin3 = 7;
const int trigPin4 = 8;
const int echoPin4 = 9;
const float Width = 5.0;   
const float Height = 6.0;

void setup() {
  Serial.begin(9600);

  pinMode(trigPin1, OUTPUT);
  pinMode(echoPin1, INPUT);
  pinMode(trigPin2, OUTPUT);
  pinMode(echoPin2, INPUT);
  pinMode(trigPin3, OUTPUT);
  pinMode(echoPin3, INPUT);
  pinMode(trigPin4, OUTPUT);
  pinMode(echoPin4, INPUT);
}
void loop() {
  float distance1 = measureDistance(trigPin1, echoPin1);
  float distance2 = measureDistance(trigPin2, echoPin2);
  float distance3 = measureDistance(trigPin3, echoPin3);
  float distance4 = measureDistance(trigPin4, echoPin4);
  float x = calculateX(distance1, distance2);
  float y = calculateY(distance3, distance4);
  if (x >= 0 && x <= Width && y >= 0 && y <= Height) {
    Serial.print("cookie's location is : ");
    Serial.print(x);
    Serial.print(", ");
    Serial.print(y);
  }
  else
  {
    Serial.println("cookie is out");
  }
  delay(1000); 
}
float measureDistance(int trigPin, int echoPin) {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  long duration = pulseIn(echoPin, HIGH);
  float distance = duration * 0.034 / 2;
  return distance;
}
float calculateX(float distance1, float distance2)
{
  float x = (distance1+ distance2)/2;
  return x;
}
float calculateY(float distance3, float distance4)
{
  float y = (distance3+ distance4)/2;
  return y;
}