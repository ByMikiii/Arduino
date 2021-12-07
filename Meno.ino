void setup() {

  Serial.begin(9600);
  Serial.println("Zadaj svoje meno ");
}

void loop() {
  if(Serial.available()){
String meno = Serial.readString();/String meno = Serial.readStringUntil('\r');
Serial.println("Vitaj " + meno);
  }
}

