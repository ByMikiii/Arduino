#define SET0(REG,BIT) REG &= ~(1<<BIT)
#define SET1(REG,BIT) REG |= (1<<BIT)
#define TEST(REG,BIT) (REG&(1<<BIT))

#include <LiquidCrystal.h>
LiquidCrystal disp(8,9,10,11,12,13);

int vysledok;

void setup() 
{
   SET0(ADMUX,REFS1); // voľba Aref
   SET0(ADMUX,REFS0);
   SET1(ADMUX,ADLAR); // zarovnanie nahor
   SET1(ADMUX,MUX0); // voľba kanála ADC1
   SET0(ADMUX,MUX1);
   SET0(ADMUX,MUX2);
   SET0(ADMUX,MUX3);
   SET1(ADCSRA,ADEN); // zapnutie ADC
   SET0(ADCSRA,ADATE); // spúšťanie príkazom
   SET0(ADCSRA,ADIE); // negenerovanie prerušenia
   SET1(ADCSRA,ADPS2); // voľba preddeličky 128 
   SET1(ADCSRA,ADPS1);
   SET1(ADCSRA,ADPS0);
   disp.begin(16,2);
}


void loop() 
{
   SET1(ADCSRA,ADSC); // začatie konverzie
   while( TEST(ADCSRA,ADIF)==0 ); // testovanie dokončenia
   vysledok = ADCH; // načítanie len horného
   disp.clear();
   disp.print(vysledok);
   delay(10);
}

// https://imgur.com/a/1ja4a1O
// https://easyupload.io/m/m27r6h
