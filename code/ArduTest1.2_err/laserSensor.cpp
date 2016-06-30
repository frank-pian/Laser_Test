#include <Arduino.h>
#include <SoftwareSerial.h>
#include"laserSensor.h"
#include"LSprooftest.h"

SoftwareSerial senSerial(8,9); //软串口RX,TX
//***********获取激光传感器数据函数，返回字符串，数据异常返回“ERRVALUE”**************
String strDistance(){
    String Atl="";  //存储返回值变量
  
    //*****命令发送与数据接收*****
    //判断串口是否有数据，如果没有发送连续测量命令
    while (senSerial.available()==0){
        for (int i=0;i<4;i++){
        senSerial.write(CONT_MEASURE[i]);
        //Serial.print("1");                   //*******调试打印*********
        }
        delay (5);                          //********调试延时*********
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

    //*******函数返回值判定*******
    if(Proof_Test()){
        for(int a=3;a<=9;a++){
           //Serial.print(char(count[a]));    //*******调试打印*********
           Atl += char(count[a]);
         }
         return Atl+'\0';
    }
    else{
      return "ERRVALUE";
    }
}
