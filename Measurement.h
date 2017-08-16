#include <string>
#include <sstream>
#include <iostream>

using namespace std;
//need to add this comment to repush
#ifndef Measurement_h
#define Measurement_h

enum Measurement_Type{ DRY = 0, WET = 1, QUANTITY = 2, UNKNOWN = 3 };

class Measurement{
public:
  Measurement();
  Measurement(const string &s){ split(s); }

  //getters
  float get_amount() const{ return amount; }
  string get_unit() const{ return unit; }
  Measurement_Type get_style() const{ return style; }
  string get_signature() const;

  //setters
  void set_amount(float a){ amount = a; }
  void set_unit(const string& u){ unit = u; }
  void set_style(Measurement_Type s){ style = s; }

  //other

private:
  //variables
  string unit; //cups, pounds, grams
  float amount; //1.24 (not 1/4)
  Measurement_Type style; //DRY, WET or QUANTITY

  //functions
  void split(const string &s);
};

#endif
