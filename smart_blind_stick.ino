// Smart Blind Stick Code
// Author: Your Name
// Platform: Arduino Uno

#define trigPin 9
#define echoPin 10
#define buzzer 6
#define motor 5

long duration;
int distance;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(motor, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;

  Serial.print("Distance: ");
  Serial.println(distance);

  if (distance > 0 && distance <= 50) {
    digitalWrite(buzzer, HIGH);
    digitalWrite(motor, HIGH);
  } else {
    digitalWrite(buzzer, LOW);
    digitalWrite(motor, LOW);
  }

  delay(200);
}
