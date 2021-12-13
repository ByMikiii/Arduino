#include < LiquidCrystal.h >
LiquidCrystal lcd(13, 12, 11, 10, 9, 8);

int suradnica = 0;
int doba = 0;

void setup()
{
lcd.begin(16, 2);
pinMode(7, OUTPUT);
pinMode(A5, INPUT);
doba = millis();
}

void loop()
{
if (millis() >= doba)
{


int a = analogRead(A5); // 0-1023

lcd.setCursor(suradnica, 0); // 0-15
lcd.print(" ");

suradnica = map(a, 0, 1023, 0, 15);

lcd.setCursor(suradnica, 0); // 0-15
lcd.print("X");

if (suradnica == 0 || suradnica == 15)
{
digitalWrite(7, HIGH);
}
else
digitalWrite(7, LOW);


doba = millis() + 100;
}
}
