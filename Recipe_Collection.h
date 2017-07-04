#include "Recipe.h"
#include <map>
#include <string>

using namespace std;
#ifndef Recipe_Collection_h
#define Recipe_Collection_h

class Recipe_Collection{
public:
  Recipe_Collection();

  //setters
  void add_recipe(Recipe r);
  void remove_recipe(string key);


  //other
  void write_to_file(ofstream& ofs);

private:
  map<string, Recipe> recipes;

};

#endif
