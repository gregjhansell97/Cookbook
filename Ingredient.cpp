#include "./interface/Ingredient.h"

map<string, Item*> Ingredient::ingredients;

Item* Ingredient::create_ingredient(string _name){
  map<string, Item*>::iterator itr = ingredients.find(_name); //attemps to find name
  if(itr == ingredients.end()){ //key does not exist
    //making new key
    Item* ingr = new Ingredient(_name); //allocating memory to use
    ingredients.insert(pair<string, Item*>(_name, ingr));
    return ingr; //returns the newly allocated pointer that was added to the map
  }
  return itr->second;
}

Ingredient::Ingredient():Item(){}

Ingredient::Ingredient(string _name):Item(_name){}
