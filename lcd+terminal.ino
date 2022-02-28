boolean a = true;
int smer;

void setup() {
  DDRB = 255;

  DDRD &= ~(1 << 3);
  PORTD |= (1 << 3);

  DDRD &= ~(1 << 4);
  PORTD |= (1 << 4);

  DDRD &= ~(1 << 5);
  PORTD |= (1 << 5);

  PORTB |= (1 << 2);
}

void loop() {
    if ( (PIND & (1 << 5)) == 0 && a == true) {
    for (int j = 2; j <= 5; j++) {
            if ((PINB & (1 << j)) != 0 && j != 5) {
              int y = j + 1;
              PORTB &= ~(1 << j);
              PORTB |= (1 << y);
              j = 10;
            }
            else if (j == 5) {
              PORTB |= (1 << 2);
              PORTB &= ~(1 << 5);
              j = 10;
            }
          }
      a = false;
    }
    if ( (PIND & (1 << 4)) == 0 &&  a == true) {
      for (int j = 5; j >= 2; j--) {
            if ((PINB & (1 << j)) != 0 && j != 2) {
              int z = j - 1;
              PORTB &= ~(1 << j);
              PORTB |= (1 << z);
              j = 0;
            }
            else if (j == 2) {
              PORTB |= (1 << 5);
              PORTB &= ~(1 << 2);
              j = 0;
            }
          }
      a = false;
    }

    if ( (PIND & (1 << 3)) == 0 && a == true) {
      smer = random(0,3);
      if (smer == 1) {
        for (int i = 1; i <= 6; i++) {
          for (int j = 2; j <= 5; j++) {
            if ((PINB & (1 << j)) != 0 && j != 5) {
              int y = j + 1;
              PORTB &= ~(1 << j);
              PORTB |= (1 << y);
              j = 10;
              delay(500);
            }
            else if (j == 5) {
              PORTB |= (1 << 2);
              PORTB &= ~(1 << 5);
              j = 10;
              delay(500);
            }
          }
        }
      } else if (smer == 2) {
        for (int i = 1; i <= 6; i++) {
          for (int j = 5; j >= 2; j--) {
            if ((PINB & (1 << j)) != 0 && j != 2) {
              int z = j - 1;
              PORTB &= ~(1 << j);
              PORTB |= (1 << z);
              j = 0;
              delay(500);
            }
            else if (j == 2) {
              PORTB |= (1 << 5);
              PORTB &= ~(1 << 2);
              j = 0;
              delay(500);
            }
          }
        }
      }
    a = false;
    }
   else if (a == false && (PIND & (1 << 5)) != 0 && (PIND & (1 << 4)) != 0 && (PIND & (1 << 3)) != 0) {
    a = true;
  }
}


https://imgur.com/a/LOljySy
