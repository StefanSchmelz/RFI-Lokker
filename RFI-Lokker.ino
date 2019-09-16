#include <SPI.h> 
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <MFRC522.h>
// Tag=56 5C 1F F8 Karte= 79 3C A3 55

#define SS_PIN 10 // SDA an Pin 10 (bei MEGA anders)
#define RST_PIN 9 // RST an Pin 9 (bei MEGA anders)

LiquidCrystal_I2C lcd(0x27, 16, 2);// LCD init
MFRC522 mfrc522(SS_PIN, RST_PIN); // RFID init

void setup(){
  // setup pins
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  // init librarys
  lcd.begin();
  lcd.clear();
  lcd.backlight();
  SPI.begin();
  mfrc522.PCD_Init();
}

void loop(){
  if (mfrc522.PICC_IsNewCardPresent()){ // Wenn karte erkannt
    if (mfrc522.PICC_ReadCardSerial() == {0x56, 0x5C, 0x1F 0xF8}){
      lcd.clear();
      lcd.setCursor(0,0);
      for(byte i = 0; i < mfrc522.uid.size; i++){
        lcd.print(mfrc522.uid.uidByte[i], HEX);
        lcd.print(" ");
      }
      lcd.setCursor(0,1);
      lcd.print("Hallo Joel");
      digitalWrite(3, HIGH);
      delay(5000);
      digitalWrite(3, LOW);
  }
}
