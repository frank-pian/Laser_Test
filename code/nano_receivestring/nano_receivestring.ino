#include <SoftwareSerial.h>

SoftwareSerial senSerial(8,9); //软串口RX,TX

void setup() {
  //打开串口调试
  Serial.begin(9600);//调试串口
  while(!Serial){
    ;//等待调试串口连接
  }
  senSerial.begin(9600);//传感器串口

}

void loop() {
  int count[6]={0};
  while (senSerial.available()>0){
    for(int i=0;i<=6;i++){
      count[i]=senSerial.read();
      delay(2);
    }
    Serial.print("size of ");
    Serial.println(senSerial.available());
     for(int a=0;a<=6;a++){
       Serial.print(a);
       Serial.print(' ');
       Serial.print(count[a]);
       Serial.print(' ');
      }
  }

}
