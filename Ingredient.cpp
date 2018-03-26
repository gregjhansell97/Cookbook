#include "./interface/Ingredient.h"

map<string, Item*> Ingredient::ingredients;

Item* Ingredient::create_ingredient(string nm){
  map<string, Item*>::iterator itr = ingredients.find(nm); //attemps to find name
  if(itr == ingredients.end()){ //key does not exist
    //making new key
    Item* ingr = new Ingredient(nm); //allocating memory to use
    ingredients.insert(pair<string, Item*>(nm, ingr));
    return ingr; //returns the newly allocated pointer that was added to the map
  }
  return itr->second;
}

Ingredient::Ingredient():Item(){}

Ingredient::Ingredient(string nm):Item(nm){}
