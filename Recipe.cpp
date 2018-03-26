#include "./interface/Recipe.h"

Recipe::Recipe():Composite(){}

Recipe::Recipe(string _name, string _description, float _serving_size):Composite(_name){
  description = _description;
  serving_size = _serving_size;
}

void Recipe::set_items(map<Item*, Amount> &items){
  cout << "setting items" << endl;
}
