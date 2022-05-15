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
   SET0(ADMUX,ADLAR); // zarovnanie nadol
   SET1(ADMUX,MUX0); // voľba kanála ADC1
   SET0(ADMUX,MUX1);
   SET0(ADMUX,MUX2);
   SET0(ADMUX,MUX3);
   SET1(ADCSRA,ADEN); // zapnutie ADC
   SET1(ADCSRA,ADATE); // spúšťanie automaticky
   SET1(ADCSRA,ADIE); // generovanie prerušenia
   SET1(SREG,7); // globálne povolenie prerušenia
   SET1(ADCSRA,ADPS2); // voľba preddeličky 128 
   SET1(ADCSRA,ADPS1);
   SET1(ADCSRA,ADPS0);
   SET1(ADCSRA,ADSC); // začatie konverzie
   disp.begin(16,2);
}

void loop() 
{
   disp.clear();
   disp.print(vysledok);
   delay(10);
}

ISR(ADC_vect)
{
   vysledok = ADCL; // načítanie dolného registra
   vysledok = vysledok | (ADCH<<8); // pripočítanie horného
}

// https://imgur.com/a/1ja4a1O
