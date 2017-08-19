#include "Measurement.h"

map<string, float> Measurement::conversion_table[2];

Measurement::Measurement(){
  unit = "";
  amount = 0.0;
  style = UNKNOWN;
}

Measurement::Measurement(const string& u, float a, Measurement_Type s){
    unit = u;
    amount = a;
    style = s;
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

Measurement Measurement::operator/(float den){
  return Measurement(unit, amount/den, style);
}


void Measurement::create_conversion_table(const char* fn){
  ifstream ct_file(fn); //conversion table file
  assert(ct_file.is_open());

  char style_indicator;
  string key; //unit like cups, pounds, grams
  int value; //its value with respect to the base unit of its kind
  int style_index = 0;
  while(ct_file >> style_indicator){
    style_index = measurement_type_to_index(char_to_measurement_type(style_indicator));
    while(ct_file >> key){
      if(key == "END") break;
      ct_file >> value;
      conversion_table[style_index][key] = value;
    }
  }

  ct_file.close();
}

int Measurement::measurement_type_to_index(Measurement_Type mt){
  return 1*(mt == WET) + 2*(mt == QUANTITY) + 3*(mt == UNKNOWN);
}

Measurement_Type Measurement::char_to_measurement_type(char c){
  if(c == 'D'){
    return DRY;
  }else if(c == 'W'){
    return WET;
  }else if(c == 'Q'){
    return QUANTITY;
  }else{
    return UNKNOWN;
  }
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
  style = char_to_measurement_type(s[i]);
}
