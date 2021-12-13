int rokNarodenia;
int vek;

void setup() {

  Serial.begin(9600);
  Serial.println("Zadaj rok svojho narodenia ");
}

void loop() {
  if(Serial.available()){

  rokNarodenia = Serial.parseInt();
  vek = 2021-rokNarodenia;
  Serial.print("Tvoj vek je: ");
  Serial.print(vek);
}
}


https://ctrlv.link/wGIt
https://ctrlv.link/shots/2021/11/01/wGIt.png
