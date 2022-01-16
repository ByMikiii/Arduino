#include <LiquidCrystal.h>
#include <EEPROM.h>

LiquidCrystal lcd(13,12,11,10,9,8);

int cislo;
int posledna;
bool a = true;


void setup() {
  posledna = EEPROM.read(100);
  randomSeed(posledna);
  lcd.begin(16,2);
  pinMode(3, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(3),generuj,FALLING);
  
}

void loop() {
  lcd.setCursor(0,0);
  lcd.print(cislo);
  lcd.setCursor(0,1);
  lcd.print (posledna);
}

void generuj(){
  if(a==false){
  cislo = random(0,100);
  posledna = cislo;
  EEPROM.write(100,posledna);
  }
  else (a = false);
}

https://imgur.com/a/ixYFDdX
