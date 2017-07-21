#include "Measurement.h"

Measurement::Measurement(){
  amount = 0;
  type = "";
}

Measurement::Measurement(const string &s){
  amount = 0;
  type = "";
  float dec = 1;
  for(int i = 0; i < s.size(); i++){
    char c = s[i];
    if((c - '0' < 10 && c - '0' >= 0 )|| c == '.'){
      if(c == '.' || dec != 1){
        amount += (c-'0')*dec;
        dec /= 10.0;
      }else{
        amount *= 10;
        amount += (c-'0');
      }
    }else{
      if(!(type.size() == 0 && c == ' ')){
        cout << "d" << c << 'G' << endl;
        type = type + c;
      }else{
        cout << "H" << c << "KK" << endl;
      }
    }
    cout << type << endl;
  }


  stringstream ss(s);
  if(!(ss >> amount)) amount = 0;
  getline(ss, type);


}
