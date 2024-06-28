#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <SPI.h>
#include <MFRC522.h>

#define SS_PIN 10
#define RST_PIN 9

#define GREEN_RELAY 4
#define RED_RELAY 5
#define GREEN_LED 6
#define RED_LED 7
#define BUZZER 8

LiquidCrystal_I2C lcd(0x27, 16, 2);
MFRC522 mfrc522(SS_PIN, RST_PIN);

void setup()
{

//    Serial.begin(9600);
    SPI.begin();
    mfrc522.PCD_Init();

    pinMode(SDA, INPUT_PULLUP);
    pinMode(SCL, INPUT_PULLUP);
    lcd.init();

    pinMode(GREEN_LED, OUTPUT);
    pinMode(RED_LED, OUTPUT);
    pinMode(GREEN_RELAY, OUTPUT);
    pinMode(RED_RELAY, OUTPUT);
    pinMode(BUZZER, OUTPUT);

    lcd.backlight();
    lcd.setCursor(0, 0);
    lcd.print("Scan card !");

    digitalWrite(GREEN_RELAY, LOW);
    digitalWrite(RED_RELAY, LOW);
}

void loop()
{

    // Nova Karta
    if (!mfrc522.PICC_IsNewCardPresent())
    {
        return;
    }

    if (!mfrc522.PICC_ReadCardSerial())
    {
        return;
    }

    // Ukaz UID na serial monitore
    Serial.print("UID tag :");
    String content = "";
    for (byte i = 0; i < mfrc522.uid.size; i++)
    {
        Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
        Serial.print(mfrc522.uid.uidByte[i], HEX);
        content.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " "));
        content.concat(String(mfrc522.uid.uidByte[i], HEX));
    }
    Serial.println();
    Serial.print("Message : ");
    content.toUpperCase();

    // Nahodne udel pristup alebo zamietni True or false alebo 0 or 1
    int accessGranted = random(3);

    lcd.clear();
    
    if (accessGranted == 1)
    {
    //    lcd.backlight();
        lcd.setCursor(0, 0);
        lcd.print("PASSED");
        digitalWrite(GREEN_RELAY, HIGH);
        digitalWrite(GREEN_LED, HIGH);
        tone(BUZZER, 1000); // Sound the buzzer at 1000 Hz
        delay(2000);
        digitalWrite(GREEN_RELAY, LOW);
        digitalWrite(GREEN_LED, LOW);
        noTone(BUZZER); // Stop the buzzer
        //beep 2x
    }
    else
    {
    //    lcd.backlight();
        lcd.setCursor(0, 0);
        lcd.print("Access Denied !");
        digitalWrite(RED_RELAY, HIGH);
        digitalWrite(RED_LED, HIGH);
        tone(BUZZER, 500); // Sound the buzzer at 500 Hz
        delay(2000);
        digitalWrite(RED_RELAY, LOW);
        digitalWrite(RED_LED, LOW);
        noTone(BUZZER); // Stop the buzzer
    }

    // Reset
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Scan card !");
    delay(1000);

   // lcd.noBacklight();
}
