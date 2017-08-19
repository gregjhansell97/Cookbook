#include <string>
#include <ostream>
#include <vector>
#include <sstream>
#include <iostream>
#include <map>
#include <assert.h>

using namespace std;
//need to add this comment to repush
#ifndef Ingredient_h
#define Ingredient_h

enum Flavor{ SALTY, SWEET, SAVORY, SOUR, BITTER, SPICY };

class Ingredient{
public:
  Ingredient();
  Ingredient(string nm, )

  //getters
  string get_name() const{ return name; }
  vector<Flavor> get_taste() const{ return taste; }

  //setters

  //factory function
  static Ingredient& create_ingredient(string nm);


private:
  //Variables
  string name; //like broth, pasta
  vector<Flavor> taste; //SALTY, SWEET, SAVORY, SOUR, BITTER, SPICY
  static bool locked; //prevents an object from being made unless it's from the static factory
  static map<string, Ingredient*> ingredients;
};

#endif
