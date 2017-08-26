#include <vector>
#include <map>
#include <string>
#include <iostream>
#include <fstream>
#include "Ingredient.h"
#include "Measurement.h"

using namespace std;
#ifndef Recipe_h
#define Recipe_h

typedef pair<Ingredient*, Measurement> Recipe_Component;
typedef vector<Recipe_Component> Recipe_Components;

class Recipe{
public:
  //constructors
  Recipe();
  Recipe(string nm, string des);
  Recipe(ifstream &raw_data);

  //getters
  string get_name() const{ return name; }
  string get_description() const{ return description; }

  //setters
  void add_ingredient(Ingredient *i, const Measurement& m){ ingredients.push_back(make_pair(i, m)); }
  void print_recipe();




private:
  string name; //the name of the recipe
  string description; //description could be book name and page number
  float serving_size; //how many people does it serve

  Recipe_Components ingredients;


  //private functions

};

#endif
