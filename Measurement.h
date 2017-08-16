#include <string>
#include <sstream>
#include <iostream>

using namespace std;
//need to add this comment to repush
#ifndef Measurement_h
#define Measurement_h

enum Measurement_Type{ DRY = 0, WET = 1, QUANTITY = 2 };

class Measurement{
public:
  Measurement();
  Measurement(const string &s){ split(s); }

  //getters
  float get_amount() const{ return amount; }
  string get_unit() const{ return unit; }


  //setters

  //other

private:
  //Variables
  string unit; //cups, pounds, grams
  float amount; //1.24 (not 1/4)
  Measurement_Type style; //DRY, WET or QUANTITY
  void split(const string &s);
};

#endif
