#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2); // RS, E, D4, D5, D6, D7
int buttonPin = 6;
int lastButtonState = LOW; // store previous button state

void setup() {
  lcd.begin(16, 2);
  pinMode(buttonPin, INPUT);
  lcd.print("Press Button");
  randomSeed(analogRead(0)); // ensure random numbers
}

void loop() {
  int buttonState = digitalRead(buttonPin);

  // Detect button press (LOW → HIGH transition)
  if (buttonState == HIGH && lastButtonState == LOW) {
    int num = random(1, 7); // 1–6
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("You rolled:");
    lcd.setCursor(0, 1);
    lcd.print(num);
    delay(200); // simple debounce
  }

  lastButtonState = buttonState; // update last state
}
