#include <Arduino.h>
#include <SoftwareSerial.h>
#include <SPI.h>
#include <SD.h>

#include"laserSensor.h"
#include"number.h"
#include"sdFilename.h"
#include"PWM.h"
#include"time.h"
#include"ArduTest.h"

extern class SoftwareSerial senSerial;

void setup() {
    //******用于PWM******
    pinMode(4,INPUT); //D4设置为输入
    
    //打开串口调试
    Serial.begin(9600);//打开调试串口
    senSerial.begin(9600);//打开传感器串口
    /*
    while(!Serial){
      ;//等待调试串口连接
    }
    */
    //******SD卡初始化******
    Serial.print("Initializing SD card...");
    //判断SD卡是否正常
    if (!SD.begin(chipSelect)){
        Serial.println("Card failed, or not present");
        return;
    }
    Serial.println("card initialized.");
    
    logname = fileName(); //获取文件名
}

void loop() {
  
    //调用模块，序号+PWM+时间+激光高度
    String dataString = "";//用于存储和打印的字符串
    dataString = serialNumber() + receiver5CH() + currentTime() + strDistance();
    
    //打开创建一个文件，因此需要关闭之前打开的另一个
    File dataFile =SD.open(logname,FILE_WRITE);
    //如果文件可用，开始写入
    if(dataFile){
        dataFile.println(dataString);
        dataFile.close();
        //在调试串口打印相同内容
        Serial.println(dataString);
      }
    //如果文件不能打开，提示Erro
    else {
        Serial.println("error opening " + logname);
    }

}
