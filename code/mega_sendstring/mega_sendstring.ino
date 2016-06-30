

void setup() {
  Serial.begin(9600);
  Serial1.begin(9600);

}

void loop() {
  int a;
  while (Serial.available()>0){
    a=Serial.read();
  Serial.println(a);
  }
  Serial1.write(a);
}
