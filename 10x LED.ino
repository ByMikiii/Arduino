int percenta;
int doba = 0;
void setup() {
pinMode(A0, INPUT);
pinMode(0, OUTPUT);
pinMode(1, OUTPUT);
pinMode(2, OUTPUT);
pinMode(3, OUTPUT);
pinMode(4, OUTPUT);
pinMode(5, OUTPUT);
pinMode(6, OUTPUT);
pinMode(7, OUTPUT);
pinMode(8, OUTPUT);
pinMode(9, OUTPUT);
pinMode(13, OUTPUT);
}

void loop() {

 int x = analogRead(A0);
 percenta = map(x,0,1023,0,100);
 
   if(percenta >= 90){
 digitalWrite(0, HIGH);
 digitalWrite(1, HIGH);
 digitalWrite(2, HIGH);
 digitalWrite(3, HIGH);
 digitalWrite(4, HIGH);
 digitalWrite(5, HIGH);
 digitalWrite(6, HIGH);
 digitalWrite(7, HIGH);
 digitalWrite(8, HIGH);
 digitalWrite(9, HIGH);}
 
 else if(percenta < 90 && percenta > 80 ){
   digitalWrite(0, HIGH);
 digitalWrite(1, HIGH);
 digitalWrite(2, HIGH);
 digitalWrite(3, HIGH);
 digitalWrite(4, HIGH);
 digitalWrite(5, HIGH);
 digitalWrite(6, HIGH);
 digitalWrite(7, HIGH);
 digitalWrite(8, HIGH);
 digitalWrite(9, LOW);}
  
  else if(percenta <= 80 && percenta > 70){
  digitalWrite(0, HIGH);
 digitalWrite(1, HIGH);
 digitalWrite(2, HIGH);
 digitalWrite(3, HIGH);
 digitalWrite(4, HIGH);
 digitalWrite(5, HIGH);
 digitalWrite(6, HIGH);
 digitalWrite(7, HIGH);
 digitalWrite(8, LOW);
 digitalWrite(9, LOW);}

 else if(percenta <= 70 && percenta > 60){
  digitalWrite(0, HIGH);
 digitalWrite(1, HIGH);
 digitalWrite(2, HIGH);
 digitalWrite(3, HIGH);
 digitalWrite(4, HIGH);
 digitalWrite(5, HIGH);
 digitalWrite(6, HIGH);
 digitalWrite(7, LOW);
 digitalWrite(8, LOW);
 digitalWrite(9, LOW);}

  else if(percenta <= 60 && percenta > 50){
  digitalWrite(0, HIGH);
 digitalWrite(1, HIGH);
 digitalWrite(2, HIGH);
 digitalWrite(3, HIGH);
 digitalWrite(4, HIGH);
 digitalWrite(5, HIGH);
  digitalWrite(6, LOW);
 digitalWrite(7, LOW);
 digitalWrite(8, LOW);
 digitalWrite(9, LOW);}

 else if(percenta <= 50 && percenta > 40){
  digitalWrite(0, HIGH);
 digitalWrite(1, HIGH);
 digitalWrite(2, HIGH);
 digitalWrite(3, HIGH);
 digitalWrite(4, HIGH);
 digitalWrite(5, LOW);
  digitalWrite(6, LOW);
 digitalWrite(7, LOW);
 digitalWrite(8, LOW);
 digitalWrite(9, LOW);}

 else if(percenta <= 40 && percenta > 30){
  digitalWrite(0, HIGH);
 digitalWrite(1, HIGH);
 digitalWrite(2, HIGH);
 digitalWrite(3, HIGH);
 digitalWrite(4, LOW);
 digitalWrite(5, LOW);
  digitalWrite(6, LOW);
 digitalWrite(7, LOW);
 digitalWrite(8, LOW);
 digitalWrite(9, LOW);}

 else if(percenta <= 30 && percenta > 20){
  digitalWrite(0, HIGH);
 digitalWrite(1, HIGH);
 digitalWrite(2, HIGH);
 digitalWrite(3, LOW);
 digitalWrite(4, LOW);
 digitalWrite(5, LOW);
  digitalWrite(6, LOW);
 digitalWrite(7, LOW);
 digitalWrite(8, LOW);
 digitalWrite(9, LOW);}

  else if(percenta <= 20 && percenta > 10){
  digitalWrite(0, HIGH);
 digitalWrite(1, HIGH);
 digitalWrite(2, LOW);
 digitalWrite(3, LOW);
 digitalWrite(4, LOW);
 digitalWrite(5, LOW);
  digitalWrite(6, LOW);
 digitalWrite(7, LOW);
 digitalWrite(8, LOW);
 digitalWrite(9, LOW);}

 else if(percenta <= 10 && percenta > 0){
 digitalWrite(0, HIGH);
 digitalWrite(1, LOW);
 digitalWrite(2, LOW);
 digitalWrite(3, LOW);
 digitalWrite(4, LOW);
 digitalWrite(5, LOW);
  digitalWrite(6, LOW);
 digitalWrite(7, LOW);
 digitalWrite(8, LOW);
 digitalWrite(9, LOW);
 }

 else{
  digitalWrite(0, LOW);
 digitalWrite(1, LOW);
 digitalWrite(2, LOW);
 digitalWrite(3, LOW);
 digitalWrite(4, LOW);
 digitalWrite(5, LOW);
  digitalWrite(6, LOW);
 digitalWrite(7, LOW);
 digitalWrite(8, LOW);
 digitalWrite(9, LOW);
  }
}


//https://ctrlv.link/Vkue
//https://ctrlv.link/shots/2021/11/01/Vkue.png
