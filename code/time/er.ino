//*********时间函数，返回一个字符串，格式[HH:mm:ss:SSS]*********
String currentTime(){

    unsigned long cutime;//暂存
    unsigned int milliseconds=0; //毫秒
    unsigned int seconds=0; //秒
    unsigned int minutes=0; //分钟
    unsigned int hours=0; //小时
    String retime=""; 

    cutime = millis(); //获取当前程序运行时间
    //换算为时分秒
    if (cutime<1000){
        milliseconds = cutime; //毫秒小于1000时直接存入
    }
    else{                      //毫秒大于1000时
        seconds = cutime / 1000;
        milliseconds = cutime % 1000;  //取模
        if (seconds<60){     //秒小于60
            ;
        }
        else{                 //秒大于60
            minutes = seconds / 60;
            seconds = seconds % 60;
            if (minutes<60){ //分小于60
              ;
            }
            else{             //分大于60
                hours = minutes / 60;
                minutes = minutes % 60;
            }
        }
    }
    //Serial.print(seconds);              //调试打印
    //Serial.println(minutes);            //调试打印
    retime =retime + "[" + String(hours) + ":" + String(minutes) + ":" + String(seconds) + ":" + String(milliseconds) + "]";
    return retime;
}

    
