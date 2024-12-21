#include <Servo.h>

Servo servo;
const int trigPin = 9;
const int echoPin = 10;

void setup() {
  servo.attach(6);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  servo.write(0);
}

void loop() {
  long duration, distance;
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = (duration / 2) / 29.1;

  if (distance <= 10) {
    servo.write(90);
    delay(3000);
    servo.write(0);
  }
  delay(100);
}