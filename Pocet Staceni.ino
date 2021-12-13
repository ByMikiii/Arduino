#include <LiquidCrystal.h>
LiquidCrystal lcd(13,12,11,10,9,8);

int stlacenia = 0;       
int val;                       
int stlaceneTlacitko;                      

void setup() {
  pinMode(A2, INPUT_PULLUP);    
  Serial.begin(9600);    
  lcd.begin(16, 2);     
  stlaceneTlacitko = digitalRead(A2);   
}

void loop(){
  val = digitalRead(A2);   
  if (val != stlaceneTlacitko) {         
    if (val == LOW) {                
      stlacenia++;        
      Serial.println(stlacenia);
      lcd.print(stlacenia);
      lcd.home();
    }
  }
  stlaceneTlacitko = val;                
}


https://ctrlv.link/V0Ru
https://ctrlv.link/shots/2021/11/01/V0Ru.png
