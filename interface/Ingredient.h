#include <string>
#include <map>

#include "Item.h"

using namespace std;

#ifndef Ingredient_h
#define Ingredient_h

class Ingredient : Item{
public:

  static Item* create_ingredient(string nm);

private:
  static map<string, Item*> ingredients;
  Ingredient();
  Ingredient(string nm);
};

#endif
