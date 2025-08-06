#include <Servo.h>

Servo myServo;

const int doorOpen = 13;
const int doorClose = 12;
const int buzzerPin = 10;

void setup()
{
  pinMode(doorOpen, OUTPUT);
  pinMode(doorClose, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  Serial.begin(9600);
  myServo.attach(9);
  Serial.println("enter a command to unlock or lock the door.");
}

void loop()
{
  if (Serial.available()) {
    String input = Serial.readStringUntil('\n');
    input.trim();
    int angle = input.toInt();
    if (input == "lock") {
      digitalWrite(doorOpen, LOW);
      digitalWrite(doorClose, HIGH);
      tone(buzzerPin, 1500);
      delay(500);
      noTone(buzzerPin);
      myServo.write(0);
      Serial.print("Moved to: ");
      Serial.println(angle);
    } else if (input == "unlock") {
      digitalWrite(doorClose, LOW);
      digitalWrite(doorOpen, HIGH);
      tone(buzzerPin, 1500);
      delay(500);
      noTone(buzzerPin);
      myServo.write(90);
      Serial.print("Moved to: ");
      Serial.println(angle);
      } else {
      Serial.println("Invalid command.");
    }
  }
}