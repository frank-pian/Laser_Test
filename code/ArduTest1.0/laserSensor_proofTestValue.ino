//*****校验count中校验位是否正确，校验通过返回true，未通过返回false

bool Proof_Test(){
  uint8_t prooftest=0x00; //初始化存储计算后的校验值

  //计算前10个数组的和，存入prootest
  for(int i=0;i<=9;i++){
    prooftest +=count[i];
  }
  //计算补码
  prooftest=~prooftest + 1;
  //判断count[10]校验位是否与计算的一致
  if (count[10]==prooftest){
      return true;
  }
  else{
      //Serial.write(prooftest);   //*********调试打印*********
      //Serial.write(count[10]);   //*********调试打印*********

      return false;
  }
}

