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

    randomSeed(analogRead(0));  // inicializacia nahodneho generatora

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

    /* Ukaz UID na serial monitore
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
*/
    // Nahodne cislo od 1 do 100:
    int randNumber = random(1,101);

    lcd.clear();
    
    if (randNumber >= 15){
        lcd.setCursor(0, 0);
        lcd.print("Access Approved!");
        digitalWrite(GREEN_RELAY, HIGH);
        digitalWrite(GREEN_LED, HIGH);

        // buzzer:
        tone(BUZZER, 1300);
        delay(200);
        noTone(BUZZER); // Stop the buzzer
        delay(20);

        tone(BUZZER, 1300);
        delay(200);
        noTone(BUZZER); // Stop the buzzer
        delay(50);

        tone(BUZZER, 1500);
        delay(200);
        noTone(BUZZER); // Stop the buzzer
        delay(30);

        tone(BUZZER, 1500);
        delay(600);
        noTone(BUZZER); // Stop the buzzer
        delay(200);

        digitalWrite(GREEN_RELAY, LOW);
        digitalWrite(GREEN_LED, LOW);
    } else{
        lcd.setCursor(0, 0);
        lcd.print("Access Denied !");
        digitalWrite(RED_RELAY, HIGH);
        digitalWrite(RED_LED, HIGH);
        
        // buzzer:
        tone(BUZZER, 2000); // Sound the buzzer at 500 Hz
        delay(800);
        noTone(BUZZER); // Stop the buzzer
        delay(300);

        tone(BUZZER, 2000); // Sound the buzzer at 500 Hz
        delay(1000);
        noTone(BUZZER); // Stop the buzzer
        delay(300);

        tone(BUZZER, 2000); // Sound the buzzer at 500 Hz
        delay(800);
        noTone(BUZZER); // Stop the buzzer
        delay(100);
        
        digitalWrite(RED_RELAY, LOW);
        digitalWrite(RED_LED, LOW);
    }

    // Reset
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Scan card !");
    delay(1000);

   // lcd.noBacklight();
}
