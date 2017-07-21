#include <string>
#include <sstream>
#include <iostream>

using namespace std;

#ifndef Measurement_h
#define Measurement_h

class Measurement{
public:
  Measurement();
  Measurement(const string &s);

  //getters
  float get_amount() const{ return amount; }
  string get_type() const{ return type; }

  //setters

  //other

private:
  float amount;
  string type;
  float base_amount;
};

#endif
