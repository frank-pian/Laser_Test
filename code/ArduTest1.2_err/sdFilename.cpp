#include <Arduino.h>
#include"sdFilename.h"

//****************返回一个log文件名，比SD卡文件名最大的那个+1**************

String fileName(){
    String relogname="";
    int a=1;
    //判断存在LOG1-200文件，存在就返回+1文件名，不存在从1开始
    for(int i=1;i<=200;i++){
        if(SD.exists("datalog" + String(i) + ".txt")){
            a=i+1;
        }
    }
    relogname = "datalog" + String(a) + ".txt";
    return relogname;
    
}
