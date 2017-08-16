#include "Measurement.h"


//need to add this comment to repush

Measurement::Measurement(){
  unit = "";
  amount = 0.0;
  style = DRY;
}

//Format: <Amount>:<Unit>:<Style>
void Measurement::split(const string &s){
  float dec = 1; //used to track decimals
  amount = 0.0;
  unit = "";
  unsigned int i; //current index in for loop

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
  //style = (s[i] == 'W')*(WET) + (s[i] == 'Q')*(QUANTITY);
}
