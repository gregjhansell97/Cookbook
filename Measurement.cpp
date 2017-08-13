#include "Measurement.h"


//need to add this comment to repush

Measurement::Measurement(){
  unit = 0;
  type = "";
  name = "";
}

//Format: <Amount> <type>
void Measurement::split(const string &s){
  name = s;
  float dec = 1;
  amount = 0;
  type = "";
  for(unsigned int i = 0; i < s.size(); i++){
    char c = s[i];
    if((c - '0' < 10 && c - '0' >= 0 )|| c == '.'){
      if(c == '.' || dec != 1){
        if(c != '.') amount += (c-'0')*dec;
        dec /= 10.0;
      }else{
        amount *= 10;
        amount += (c-'0');
      }
    }else{
      if(type.size() == 0 && c == ' ') continue;
      type = type + c;
    }
  }
}
