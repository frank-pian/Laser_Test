#ifndef ARDUTEST_H_
#define ARDUTEST_H_

void setup();
void loop();


//****** 用于SD卡设置******
const int chipSelect = 10;//设置片选CS，MEGA 53，NANO 10
String logname = ""; //用于存储日志文件名


#endif