//*************测量遥控器接收机5通道模式，返回字符串“LOW”“MIDDLE”“HIGH”***********

String receiver5CH(){

    unsigned long pulsevalue;

    pulsevalue = pulseIn(4,1); //从D4口读入脉宽
    if (pulsevalue>900 && pulsevalue<=1272){
        return "[LOW]";
    }
    else if(pulsevalue>1274 && pulsevalue<=1651){
        return "[MIDDLE]";
    }
    else if(pulsevalue>1651 && pulsevalue<=2077){
        return "[HIGH]";
    }
    else{
        return "[?]";
    }
}

