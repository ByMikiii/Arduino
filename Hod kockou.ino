#include <LiquidCrystal.h>
#include <EEPROM.h>

LiquidCrystal lcd(13, 12, 11, 10, 9, 8);

int cislo1 = 0;
int cislo2 = 0;
int skore1 = 0;
int skore2 = 0;
int posledneSkore1;
int posledneSkore2;

void setup() {
  lcd.begin(16, 2);
  pinMode(2, INPUT_PULLUP);
  pinMode(3, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(3), kocka1, FALLING);
  attachInterrupt(digitalPinToInterrupt(2), kocka2, FALLING);

 skore1 = EEPROM.read(1);
  skore2 = EEPROM.read(2);

}

void loop() {
  lcd.setCursor(0, 0);
  lcd.print(cislo1);
  lcd.setCursor(12, 0);
  lcd.print(skore1);
  lcd.setCursor(0, 1);
  lcd.print(cislo2);
  lcd.setCursor(12, 1);
  lcd.print(skore2);
  skore1 = EEPROM.read(1);
  skore2 = EEPROM.read(2);
}

void kocka1() {
  cislo1 = random(1, 7);
  if(cislo1>cislo2){
    skore1++;
    }
    else if(cislo1<cislo2){
      skore2++;
    }

    EEPROM.write(1, skore1);
    EEPROM.write(2, skore2);

}

void kocka2() {
  cislo2 = random(1, 7);
  if(cislo1>cislo2){
    skore1++;
   }
    else if(cislo1<cislo2){
      skore2++;
    }
    EEPROM.write(1, skore1);
    EEPROM.write(2, skore2);

    }
    
    
    
   // https://imgur.com/oH9NMan
   // https://ctrlv.link/UGui
