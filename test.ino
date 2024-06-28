#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2); // Změňte adresu dle výsledku skenování.

void setup() {
  //pinMode(SDA, INPUT_PULLUP);
  //pinMode(SCL, INPUT_PULLUP);
  lcd.begin(16, 2);
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Hello, World!");
}

void loop() {
  lcd.backlight();
  delay(3000);
  lcd.noBacklight();
  delay(3000);
}
