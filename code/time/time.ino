

void setup() {
  Serial.begin(9600);
   while(!Serial){
      ;//等待调试串口连接
    }

}

void loop() {
Serial.println(currentTime());
}
