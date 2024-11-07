const int trigPin = 9; 
const int echoPin = 10; 
const int led1Pin = 2; 
const int led2Pin = 3; 
const int led3Pin = 4; 
const int potPin = A0; // Potentiometer connected to A0

unsigned long previousMillis = 0;
const long interval = 500;

void setup() {
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(led1Pin, OUTPUT);
  pinMode(led2Pin, OUTPUT);
  pinMode(led3Pin, OUTPUT);
  pinMode(potPin, INPUT);
}

void loop() {
  long duration, distance;
  int potValue = analogRead(potPin);
  
  // Map the potentiometer value to distance thresholds
  int threshold1 = map(potValue, 0, 1023, 10, 30);
  int threshold2 = threshold1 + 20;
  int threshold3 = threshold2 + 20;

  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.print(" cm, Thresholds: ");
  Serial.print(threshold1);
  Serial.print(", ");
  Serial.print(threshold2);
  Serial.print(", ");
  Serial.println(threshold3);
  
  if (distance < threshold1) {
    digitalWrite(led1Pin, HIGH);
    digitalWrite(led2Pin, HIGH);
    digitalWrite(led3Pin, HIGH);
  } else if (distance >= threshold1 && distance < threshold2) {
    digitalWrite(led1Pin, HIGH);
    digitalWrite(led2Pin, HIGH);
    digitalWrite(led3Pin, LOW);
  } else if (distance >= threshold2 && distance < threshold3) {
    digitalWrite(led1Pin, HIGH);
    digitalWrite(led2Pin, LOW);
    digitalWrite(led3Pin, LOW);
  } else {
    unsigned long currentMillis = millis();
    if (currentMillis - previousMillis >= interval) {
      previousMillis = currentMillis;
      if (digitalRead(led1Pin) == HIGH) {
        digitalWrite(led1Pin, LOW);
        digitalWrite(led2Pin, LOW);
        digitalWrite(led3Pin, LOW);
      } else {
        digitalWrite(led1Pin, HIGH);
        digitalWrite(led2Pin, HIGH);
        digitalWrite(led3Pin, HIGH);
      }
    }
  }
}