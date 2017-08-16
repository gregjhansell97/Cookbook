#include "Measurement.h"

Measurement::Measurement(){
  unit = "";
  amount = 0.0;
  style = UNKNOWN;
}

string Measurement::get_signature() const{
  char t = 'K'; //for unknown...

  if(style == DRY){
    t = 'D';
  }else if(style == WET){
    t = 'W';
  }else if(style == QUANTITY){
    t = 'Q';
  }

  return to_string(amount) + ":" + unit + ":" + t;
}

//Format: <Amount>:<Unit>:<Style>
void Measurement::split(const string &s){
  float dec = 1; //used to track decimals
  amount = 0.0;
  unit = "";
  unsigned int i; //current index in for loop
  style = UNKNOWN;

  //iterating through every character in the input string s
  for(i = 0; i < s.size(); i++){
    char c = s[i];
    if(c == ':') break;
    if((c - '0' < 10 && c - '0' >= 0 )|| c == '.'){
      if(c == '.' || dec != 1){
        if(c != '.') amount += (c-'0')*dec;
        dec /= 10.0;
      }else{
        amount *= 10;
        amount += (c-'0');
      }
    }
  }
  i++; //goes past the semicolon
  for(; i < s.size(); i++){
    char c = s[i];
    if(c == ':') break;
    unit = unit + c;
  }
  i++;
  if(s[i] == 'D'){
    style = DRY;
  }else if(s[i] == 'W'){
    style = WET;
  }else if(s[i] == 'Q'){
    style = QUANTITY;
  }
}
