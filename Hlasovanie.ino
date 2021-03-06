#define set1(R,b) R|=1<<b
#define set0(R,b) R&=~(1<<b)
#define test(R,b) (R&=(1<<b))

volatile int uzivatel1 = 0;
volatile int uzivatel2 = 0;
volatile int uzivatel3 = 0;
volatile int uzivatel4 = 0;
volatile int uzivatel5 = 0;
volatile int lastPind = 255;
volatile int lastPind2 = 255;

boolean a = true;
void setup() {
  Serial.begin(9600);
  set0(DDRD,2);
  set1(PORTD,2);

  set0(DDRD,3);
  set1(PORTD,3);

  set0(DDRD,4);
  set1(PORTD,4);

  set0(DDRD,5);
  set1(PORTD,5);

  set0(DDRD,6);
  set1(PORTD,6);

  DDRB = 255;
  DDRC = 255;
  
  set1(PCICR, PCIE2);   //PCICR |= 1<<PCIE2;
  set1(SREG,7);  //SREG |= 1<<7;

  set1(PCMSK2, PCINT22);   //PCMSK2 |= 1<<PCINT22;
  set1(PCMSK2, PCINT21);   
  set1(PCMSK2, PCINT20);   
  set1(PCMSK2, PCINT19);   
  set1(PCMSK2, PCINT18);   
}

void loop() {
  if(a == true){
  if(test(PIND,2) == 0 || test(PIND,3) == 0 || test(PIND,4) == 0 || test(PIND,5) == 0 || test(PIND,6) == 0){
    
  a=false;
  Serial.println("----------------");
  Serial.print("uzivatel 1: ");
  Serial.println(uzivatel1);
  Serial.print("uzivatel 2: ");
  Serial.println(uzivatel2);
  Serial.print("uzivatel 3: ");
  Serial.println(uzivatel3);
  Serial.print("uzivatel 4: ");
  Serial.println(uzivatel4);
  Serial.print("uzivatel 5: ");
  Serial.println(uzivatel5);

  PORTB = 0;
  PORTC = 0;

  if(uzivatel1 == 1){
    set1(PORTB, 0);}
   else if(uzivatel1 == 2){
     set1(PORTB, 1);}
     
   if(uzivatel2 == 1){
    set1(PORTB, 2);}
   else if(uzivatel2 == 2){
     set1(PORTB, 3);}

   if(uzivatel3 == 1){
    set1(PORTB, 4);}
   else if(uzivatel3 == 2){
     set1(PORTB, 5);}

    if(uzivatel4 == 1){
    set1(PORTC, 0);}
   else if(uzivatel4 == 2){
     set1(PORTC, 1);}

   if(uzivatel5 == 1){
    set1(PORTC, 2);}
   else if(uzivatel5 == 2){
     set1(PORTC, 3);}
  }
  }
  else if(a == false){
    if(test(PIND,2) != 0 && test(PIND,3) != 0 && test(PIND,4) != 0 && test(PIND,5) != 0 && test(PIND,6) != 0){
   a = true;}
}
}
ISR( PCINT2_vect )
{
   if( test(PIND,2) == 0  && test(PIND,2) != test(lastPind, 2) ){
    if(uzivatel1 == 2){
      uzivatel1 = 0;}
    uzivatel1++;
    }
    
    if( test(PIND,3) == 0  && test(PIND,3) != test(lastPind, 3) ){
    if(uzivatel2 == 2){
      uzivatel2 = 0;}
    uzivatel2++;
    }

    if( test(PIND,4) == 0  && test(PIND,4) != test(lastPind, 4) ){
    if(uzivatel3 == 2){
      uzivatel3 = 0;}
    uzivatel3++;
    }
    
    if( test(PIND,5) == 0  && test(PIND,5) != test(lastPind, 5) ){
    if(uzivatel4 == 2){
      uzivatel4 = 0;}
    uzivatel4++;
    }

    if( test(PIND,6) == 0  && test(PIND,6) != test(lastPind, 6) ){
    if(uzivatel5 == 2){
      uzivatel5 = 0;}
    uzivatel5++;
    }
    
    lastPind = PIND;
}


// https://imgur.com/a/i5noNYR
