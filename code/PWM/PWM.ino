

void setup() {
  pinMode(4,INPUT);   //D4 设置为输入
  Serial.begin(9600);

}
void loop() {
    
    Serial.println(receiver5CH());

}
