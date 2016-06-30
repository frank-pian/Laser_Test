#include <SoftwareSerial.h>

SoftwareSerial senSerial(8,9); //软串口RX,TX
String Atl="";
const uint8_t CONT_MEASURE[4]={0x80,0x06,0x03,0x77}; //定义发送连续测量命令
uint8_t count[11]={0}; //接收传感器11位数据
  
void setup() {
  //打开串口调试
  Serial.begin(9600);//调试串口
  while(!Serial){
    ;//等待调试串口连接
  }
  senSerial.begin(9600);//传感器串口

  //*****命令发送与数据接收*****
  //判断串口是否有数据，如果没有发送连续测量命令
  while (senSerial.available()==0){
      for (int i=0;i<4;i++){
      senSerial.write(CONT_MEASURE[i]);
      //Serial.print("1");                   //*******调试打印*********
      }
      delay (2000);                          //********调试延时*********
  }
  
  //接收一组11位数据，并负责纠错
   for(int i=0;i<=10;){
      count[i]=senSerial.read();
      //判断是否第0帧
      if (i==0){
          if (count[0]==0x80){
            i++; //第0帧是0x80，后续数据正常接收
          }
          else{
            ;  //第0帧不是0X80，后续数据仍然赋给第0帧
            }
      }
      else{
          //非0帧数据正常接收
          i++;
      }
      //Serial.print("2");                   //*******调试打印*********
      delay(2);
    }
    
  

    if (Proof_Test()){
        //*****调试打印*****
        //显示这组数据
        for(int a=3;a<=10;a++){
           //Serial.print(char(count[a]));    //*******调试打印*********
           Atl += char(count[a]);
         }
         Serial.print(Atl);
    }
    else {
         Serial.print("err");
    }
}

void loop() {
}
