#include "Ingredient.h"


bool Ingredient::locked = true;
map<string, Ingredient*> Ingredient::ingredients;



Ingredient& Ingredient::create_ingredient(string nm){
  locked = false;
  Ingredient* i;
  i = ingredients[nm];
  if(!i){
    i = ingredients[nm] = new Ingredient;
  }
  return *i;
}


Ingredient::Ingredient(){
  assert(!locked); //ensures that an ingredient object is only made through the factory function
  name = "";
  cout << "object created" << endl;
  locked = true;
}
