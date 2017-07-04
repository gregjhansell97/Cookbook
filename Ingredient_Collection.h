#include "Ingredient.h"
#include <vector>
#include <fstream>

using namespace std;
#ifndef Ingredient_Collection_h
#define Ingredient_Collection_h

class Ingredient_Collection{
public:
  Ingredient_Collection();
  //getters

  //setters
  void add_ingredient(Ingredient i);

  //other
  void print() const; //useful for debugging
  void write_to_file(ofstream& ofs) const;

private:
  //Hashmap/ or actual map instead of vector
  vector<Ingredient> ingredients;
};

#endif
