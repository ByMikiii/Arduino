// 1. Arduino
void setup () {
  
 pinMode(A0, INPUT);
 Serial.begin (9600);
}

void loop () 
{
     int a = analogRead(A0);
     int percenta = map(a,0,1023,0,100);
     if(percenta < 50){
     Serial.write(1);
     }else {
      Serial.write(0);}
     
}

// 2. Arduino
#include <LiquidCrystal.h>
LiquidCrystal lcd(13,12,11,10,9,8);

void setup() {
  lcd.begin(16,2);
  Serial.begin(9600);
}

void loop() {
  if(Serial.available()){
    byte a = Serial.read();
    lcd.home();
    if(a == 1){
      lcd.print("pomaly");
      }else{
     lcd.print("rychlo");}
  }
    }

https://ctrlv.link/3YXT
https://ctrlv.link/shots/2021/11/01/3YXT.png
