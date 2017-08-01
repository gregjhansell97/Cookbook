#include <string>
#include <sstream>
#include <iostream>

using namespace std;

#ifndef Measurement_h
#define Measurement_h

class Measurement{
public:
  Measurement();
  Measurement(const string &s){ split(s); }

  //getters
  string get_name() const{ return name; }
  float get_amount() const{ return amount; }
  string get_type() const{ return type; }

  //setters

  //other

private:
  void split(const string &s);
  float amount;
  string type;
  string name;
  float base_amount;
};

#endif
