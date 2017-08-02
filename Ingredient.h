#include "Measurement.h"
#include <iostream>
#include <string>

using namespace std;

#ifndef Ingredient_h
#define Ingredient_h

class Ingredient{
public:
  //constructors
  //n = name, m = measurement
  Ingredient();
  Ingredient(const string& n, const string& m);

  //getters
  string get_name() const{ return name; }
  string get_measurement() const{ return measurement.get_name(); }

  //setters
  void set_name(const string& n){ name = n; }
  void set_measurement(const string& m){ measurement = m; }

  //other
  void print_data() const;

private:
  string name; //the name of the ingredient
  Measurement measurement; //the how much of the ingredient
};

#endif
