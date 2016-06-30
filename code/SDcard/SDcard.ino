#include <SD.h>
#include <SPI.h>

//****** 用于SD卡设置******
const int chipSelect = 10;//设置片选CS，MEGA 53，NANO 10


String logname = "";

void setup() {
  //打开串口调试
    Serial.begin(9600);//打开调试串口
    while(!Serial){
      ;//等待调试串口连接
    }
  //******SD卡初始化******
    Serial.print("Initializing SD card...");
    //判断SD卡是否正常
    if (!SD.begin(chipSelect)){
        Serial.println("Card failed, or not present");
        return;
    }
    Serial.println("card initialized.");
    logname = fileName();
    

}

void loop() {
  String dataString = "";

  // read three sensors and append to the string:
  for (int analogPin = 0; analogPin < 3; analogPin++) {
    int sensor = analogRead(analogPin);
    dataString += String(sensor);
    if (analogPin < 2) {
      dataString += ",";
    }
  }
  Serial.println(logname);
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
        Serial.println("error opening "+logname);
    }

}
