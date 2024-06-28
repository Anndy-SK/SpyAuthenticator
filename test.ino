#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2); // Změňte adresu dle výsledku skenování.

void setup() {
  pinMode(SDA, INPUT_PULLUP);
  pinMode(SCL, INPUT_PULLUP);
  lcd.init();
  lcd.backlight();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Hello, World!");
}

void loop() {
  // code
}
