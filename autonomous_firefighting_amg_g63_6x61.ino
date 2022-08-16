#include <Servo.h>
#define RMS 5    //RMS - RIGHT MOTOR SPEED
#define RMP 6    //RMP - RIGHT MOTOR POSITIVE
#define RMN 7    //RMS - RIGHT MOTOR NEGATIVE
#define LMS 3    //LMS - LEFT MOTOR SPEED
#define LMP 2    //LMP - LEFT MOTOR POSITIVE
#define LMN 4    //LMN - LEFT MOTOR NEGATIVE
#define Buzzer 8


const int trigPin = 10;
const int echoPin = 11;

float duration, distance;
Servo LOKI;
void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  LOKI.attach(9);
  pinMode(RMS, OUTPUT);
  pinMode(RMP, OUTPUT);
  pinMode(RMN, OUTPUT);
  pinMode(LMS, OUTPUT);
  pinMode(LMP, OUTPUT);
  pinMode(LMN, OUTPUT);
  pinMode(A0,INPUT);
  pinMode(A1,INPUT);
  pinMode(8,OUTPUT);
  pinMode(12,OUTPUT);
  digitalWrite(RMS, HIGH);
  digitalWrite(LMS, HIGH);
  
  Serial.begin(9600);
}

void loop() {
  sense();
  if(distance>50)
  {
     forward();
     LOKI.write(180);
  }
  else
  {
      stops();
      delay(2000);
      LOKI.write(0);
      backward();
      delay(500);
      LOKI.write(180);
      left();
      delay(2500);
      LOKI.write(180);
  }
  
  int smoke = analogRead(A0);
  int temp = analogRead(A1);
  
  Serial.print("The intensity of smoke is ");
  Serial.println(smoke);
  Serial.print("Temparature: ");
  Serial.println(temp);
  
  if(smoke>360 || temp>240)
  {
    digitalWrite(Buzzer,HIGH);
    digitalWrite(12,HIGH);
  }

  else
  {
    digitalWrite(Buzzer, LOW);
    digitalWrite(12, LOW);
  }
}

void sense() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = (duration*.0343)/2;
  Serial.print("Distance: ");
  Serial.println(distance);
  delay(100);
}

void forward()
{
  digitalWrite(RMP, HIGH);
  digitalWrite(RMN, LOW);
  digitalWrite(LMP, HIGH);
  digitalWrite(LMN, LOW);
}

void stops()
{
  digitalWrite(RMP, LOW);
  digitalWrite(RMN, LOW);
  digitalWrite(LMP, LOW);
  digitalWrite(LMN, LOW);
}

void backward()
{
  digitalWrite(RMP, LOW);
  digitalWrite(RMN, HIGH);
  digitalWrite(LMP, LOW);
  digitalWrite(LMN, HIGH);
}

void left()
{
  digitalWrite(RMP, HIGH);
  digitalWrite(RMN, LOW);
  digitalWrite(LMP, LOW);
  digitalWrite(LMN, LOW);
}

void right()
{
  digitalWrite(RMP, LOW);
  digitalWrite(RMN, LOW);
  digitalWrite(LMP, HIGH);
  digitalWrite(LMN, LOW);
}