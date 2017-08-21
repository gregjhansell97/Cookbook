#include "Measurement.h"

map<string, float> Measurement::conversion_table[3];

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

Measurement::Measurement(const Measurement& m){
  unit = m.unit;
  amount = m.amount;
  style = m.style;
}

Measurement::Measurement(const Measurement& m1, const Measurement& m2){
  assert(m1.style == m2.style);
  float a = 0;
  if(m1.style == QUANTITY){
    assert(m1.unit == m2.unit);
    a = m1.amount + m2.amount;
  }else{
    int index = measurement_type_to_index(m1.style);
    assert(index < 3);
    map<string, float>::iterator itr_m1 = conversion_table[index].find(m1.unit);
    map<string, float>::iterator itr_m2 = conversion_table[index].find(m2.unit);
    assert(itr_m1 != conversion_table[index].end());
    assert(itr_m2 != conversion_table[index].end());
    float bf_m1 = itr_m1->second; //bf = base factor
    float bf_m2 = itr_m2->second;

    a = m1.amount + m2.amount*(bf_m2/bf_m1);
  }
  unit = m1.unit;
  amount = a;
  style = m1.style;
}

string Measurement::get_signature() const{
  char t = 'K'; //for unknown...

  if(style == DRY){
    t = 'D';
  }else if(style == LIQUID){
    t = 'L';
  }else if(style == MASS){
    t = 'M';
  }else if(style == QUANTITY){
    t = 'Q';
  }

  return to_string(amount) + ":" + unit + ":" + t;
}

Measurement Measurement::operator+(Measurement m){
  return Measurement((*this), m);
}

bool Measurement::operator<(Measurement m){
  assert(style == m.style);
  if(style == QUANTITY){
    assert(unit == m.unit);
    return amount < m.amount;
  }
  int index = measurement_type_to_index(style);
  assert(index < 3);
  map<string, float>::iterator itr_self = conversion_table[index].find(unit);
  map<string, float>::iterator itr_m = conversion_table[index].find(m.unit);
  assert(itr_self != conversion_table[index].end());
  assert(itr_m != conversion_table[index].end());
  float base_factor_self = itr_self->second;
  float base_factor_m = itr_m->second;

  return amount*base_factor_self < m.amount*base_factor_m;
}

bool Measurement::operator==(Measurement m){
  assert(style == m.style);
  if(style == QUANTITY){
    assert(unit == m.unit);
    return amount == m.amount;
  }
  int index = measurement_type_to_index(style);
  assert(index < 3);
  cout << index << endl;
  map<string, float>::iterator itr_self = conversion_table[index].find(unit);
  map<string, float>::iterator itr_m = conversion_table[index].find(m.unit);
  assert(itr_self != conversion_table[index].end());
  assert(itr_m != conversion_table[index].end());
  float base_factor_self = itr_self->second;
  float base_factor_m = itr_m->second;

  return amount*base_factor_self == m.amount*base_factor_m;
}

//M gram 1 ounce 28.3495 pound 453.592 kilogram 1000 END
void Measurement::create_conversion_table(const char* fn){
  ifstream ct_file(fn); //conversion table file
  assert(ct_file.is_open());

  char style_indicator;
  string key; //unit like cups, pounds, grams
  float value; //its value with respect to the base unit of its kind
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
  return 1*(mt == LIQUID) + 2*(mt == MASS) + 3*(mt == QUANTITY) + 4*(mt == UNKNOWN);
}

Measurement_Type Measurement::char_to_measurement_type(char c){
  if(c == 'D'){
    return DRY;
  }else if(c == 'L'){
    return LIQUID;
  }else if(c == 'M'){
    return MASS;
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
