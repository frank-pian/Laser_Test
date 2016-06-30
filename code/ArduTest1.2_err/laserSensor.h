#ifndef LASERSENSOR_H
#define LASERSENSOR_H

String strDistance();

//******laserSensor模块,strDistance(),Proof_Test()******
const uint8_t CONT_MEASURE[4]={0x80,0x06,0x03,0x77}; //定义发送连续测量命令
uint8_t count[11]={0}; //接收传感器11位数据

#endif
