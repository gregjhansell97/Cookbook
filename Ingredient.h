#include <string>
#include <fstream>
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
#define FLAVORS 6 //number of flavors used in the taste array

enum Flavor{ SALTY, SWEET, SAVORY, SOUR, BITTER, SPICY }; //count should match FLAVORS

class Ingredient{
public:
  //constructors
  /*NOTE:
  constructors are used internally only. The static function create_ingredient
  is used otherwise. The constructors are locked with assertions so any misuse
  cannot be made without an assertion being called
  */
  Ingredient(); //name is zero, taste array is 0;
  Ingredient(string nm); //name is no longer zero, taste is zero

  //getters
  string get_name() const{ return name; }
  const float* get_taste() const{ return taste; }
  const float get_salt() const{ return taste[0]; }
  const float get_sweet() const{ return taste[1]; }
  const float get_savory() const{ return taste[2]; }
  const float get_sour() const{ return taste[3]; }
  const float get_bitter() const{ return taste[4]; }
  const float get_spicy() const{ return taste[5]; }

  //setters
  void set_salt(float f){ taste[0] = f; }
  void set_sweet(float f){ taste[1] = f; }
  void set_savory(float f){ taste[2] = f; }
  void set_sour(float f){ taste[3] = f; }
  void set_bitter(float f){ taste[4] = f; }
  void set_spicy(float f){ taste[5] = f; }


  //static functions
  //given a name either creates a new ingredient or returns the address of
  //the ingredient with that name
  static Ingredient* create_ingredient(string nm);

  //taking a file name, it inititializes all the ingredients currently save,
  //and their preferences
  static void create_ingredients(const char* fn);

  //saves ingredients
  static void save_ingredients(const char* fn);


private:
  //Variables
  string name; //like broth, pasta
  float taste[FLAVORS]; //SALTY, SWEET, SAVORY, SOUR, BITTER, SPICY
  static bool locked; //prevents an object from being made unless it's from the static factory
  static map<string, Ingredient*> ingredients; //map of all the ingredients and their pointers
};

#endif
