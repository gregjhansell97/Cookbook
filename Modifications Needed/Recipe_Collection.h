#include "Recipe.h"
#include "Ingredient_Collection.h"
#include <map>
#include <string>
#include <iostream>

using namespace std;
#ifndef Recipe_Collection_h
#define Recipe_Collection_h

class Recipe_Collection{
public:
  Recipe_Collection();

  //setters
  Recipe* add_recipe(Recipe r){  return &(recipes[r.get_key()] = r); }
  void remove_recipe(const string &key){ recipes.erase(key); };
  void have_ingredients(Ingredient_Collection& input, Recipe_Collection& output);


  //getters
  void get_recipe(Recipe& output);


  //other
  void print_data();
  void print_recipes();
  void write_to_file(ofstream& ofs);

private:
  map<string, Recipe> recipes;

};

#endif
