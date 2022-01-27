bool a = false;
int i = 1;


void setup() {
  DDRB = (0<<5);
  DDRD = 255;

  PORTB |= 1<<5;

}

void loop() {
 
 
 if(a==true){
  if((PINB&(1<<5)) == 0 && i == 1 && a == true){
   PORTD = PORTD <<1;
   PORTD = 1<<0;
   i++;
   a = false;
    }
  if((PINB&(1<<5)) == 0 && i == 2 && a == true){
    PORTD = 1<<1;
    i++;
    a = false;
    }
    if((PINB&(1<<5)) == 0 && i == 3 && a == true){
    PORTD = 1<<2;
    i++;
    a = false;
    }
    
    if((PINB&(1<<5)) == 0 && i == 4 && a == true){
    PORTD = 1<<3;
    i = 1;
    a = false;
    }
  }
  else if((PINB&(1<<5)) != 0 && a == false){
    a = true;
  
  }
}

https://imgur.com/a/FD0YsGR
