int i = 0;
void setup() {
DDRB = 255;

DDRD &= ~(1<<2);
PORTD |= (1<<2);

SREG |= 1<<7; // istic vzdy 7 

EIMSK |= 1<<INT0; //zapina int0

EICRA |= 1<<ISC01;
EICRA &= ~(1<<ISC00); //dobezna hrana

DDRD &= ~(1<<3);
PORTD |= (1<<3);
SREG |= 1<<7;
EIMSK |= 1<<INT1;
EICRA |= 1<<ISC11;
EICRA &= ~(1<<ISC10);

}

void loop() {
  if(i == 1){
    PORTB |= (1<<4);
    delay(1000);
    PORTB &= ~(1<<4);
    i = 0;} 
    else if (i == 2){
    PORTB |= (1<<5);
    delay(1000);
    PORTB &= ~(1<<5);
    i = 0;}
    
}

ISR(  INT0_vect  )
{
      i = 1;
}

ISR(  INT1_vect  )
{
      i = 2;
}

/*
 * naprogramujte na Arduine dve vonkajsie prerusenia cez registre tak, aby sa po stlaceni 
 * prveho tlacidla rozsvietila na 1 sek. prva LED dioda a po stlaceni druheho druha. 
 * Samotny algoritmus svietenia (ONdelayOFF)vykonavajte vo funkcii LOOP, 
 * kedze ide o casovo narocny algoritmus a ten nie je vhodne pisat do obsluhy prerusenia.
 * 
 */


https://imgur.com/a/F1ImyDR
