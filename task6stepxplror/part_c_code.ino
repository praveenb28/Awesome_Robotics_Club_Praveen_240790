// Modified Arduino code for Part C: Servo Control System

#include <Servo.h>
#include <LiquidCrystal.h>

// Servo objects
Servo servoA;
Servo servoB;

// Pin assignments
const int potPin = A0;
const int buttonPin = 2;
const int servoAPin = 3;
const int servoBPin = 5;

// LCD pins: RS, E, D4, D5, D6, D7
LiquidCrystal lcd(7, 8, 9, 10, 11, 12);

// Variables for state tracking
bool controlServoA = true;
int previousButtonState = LOW;

void setup() {
  servoA.attach(servoAPin);
  servoB.attach(servoBPin);

  pinMode(buttonPin, INPUT);

  lcd.begin(16, 2);
  lcd.print("Initializing...");
  delay(1000);
  lcd.clear();
}

void loop() {
  int currentButtonState = digitalRead(buttonPin);

  // Check for button press to toggle servos
  if (currentButtonState == HIGH && previousButtonState == LOW) {
    controlServoA = !controlServoA;
    delay(200); // Debounce delay
  }
  previousButtonState = currentButtonState;

  // Read potentiometer value and map it to servo angle
  int potValue = analogRead(potPin);
  int angle = map(potValue, 0, 1023, 0, 180);

  // Move the selected servo
  if (controlServoA) {
    servoA.write(angle);
  } else {
    servoB.write(angle);
  }

  // Update LCD display
  lcd.setCursor(0, 0);
  lcd.print("Servo: ");
  lcd.print(controlServoA ? "A " : "B ");

  lcd.setCursor(0, 1);
  lcd.print("Angle: ");
  lcd.print(angle);
  lcd.print("   "); // Clear trailing characters

  delay(100); // Short delay for display stability
}