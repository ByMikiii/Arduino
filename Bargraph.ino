void setup() {
DDRB &= ~(1<<5);
DDRB &= ~(1<<5);
DDRD= 0b11111111;
PORTB |= 1<<5;
PORTB |= 1<<2;
}

void loop() {
if ( (PINB&(1<<5))==0){
  PORTD = PORTD <<1;
  PORTD |= 1<<0;
  delay(500);
}
if ( (PINB&(1<<2))==0){
  PORTD = PORTD >>1;
  delay(500);
}

}


https://prnt.sc/26m0dnc
