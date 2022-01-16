#include <LiquidCrystal.h>
#include <EEPROM.h>

LiquidCrystal lcd(13, 12, 11, 10, 9, 8);

int cislo1;
int cislo2;
int skore1;
int skore2;
int pskore1;
int pskore2;
bool a = true;

void setup() {
  lcd.begin(16, 2);
  pinMode(2, INPUT_PULLUP);
  pinMode(3, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(3), kocka1, FALLING);
  attachInterrupt(digitalPinToInterrupt(2), kocka2, FALLING);
  
   pskore1 = EEPROM.read(100);
   pskore2 = EEPROM.read(200);
   randomSeed(pskore1);
   randomSeed(pskore2);
 
}

void loop() {
  skore1 = pskore1;
  skore2 = pskore2;
  lcd.setCursor(0, 0);
  lcd.print(cislo1);
  lcd.setCursor(12, 0);
  lcd.print(skore1);
  lcd.setCursor(0, 1);
  lcd.print(cislo2);
  lcd.setCursor(12, 1);
  lcd.print(skore2);

}

void kocka1() {
  if(a == false){
  cislo1 = random(1, 7);
  if(cislo1>cislo2){
    skore1++;
    }
    else if(cislo1<cislo2){
      skore2++;
    }
    
      pskore1 = skore1;
      pskore2 = skore2;
    
EEPROM.write(100, pskore1);
EEPROM.write(200, pskore2);}

else a = false;  
  }

void kocka2() {
  if(a == false){
  cislo2 = random(1, 7);
  if(cislo1>cislo2){
    skore1++;
   }
    else if(cislo1<cislo2){
      skore2++;
    }
    
    pskore1 = skore1;
    pskore2 = skore2;
      
EEPROM.write(100, pskore1);
EEPROM.write(200, pskore2);}

else a = false;
    }

https://imgur.com/a/jBom9lE
