#include "Ingredient.h"
#include <vector>
#include <fstream>

using namespace std;
#ifndef Ingredient_Collection_h
#define Ingredient_Collection_h

class Ingredient_Collection{
public:

  //getters
  unsigned int size(){ return ingredients.size(); }

  //setters
  void add_ingredient(Ingredient i);

  //other
  void print() const; //useful for debugging
  void write_to_file(ofstream& ofs) const; //used in save chain of commands

private:
  vector<Ingredient> ingredients; //the ingredients it's given
};

#endif
