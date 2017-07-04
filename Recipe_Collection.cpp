#include "Recipe_Collection.h"

using namespace std;

Recipe_Collection::Recipe_Collection(){
  //do something
}
void Recipe_Collection::add_recipe(Recipe r){
  recipes[r.get_key()] = r;
}

void Recipe_Collection::remove_recipe(string key){
  recipes.erase(key);
}

void Recipe_Collection::write_to_file(ofstream& ofs){
  map<string, Recipe>::iterator i = recipes.begin();
  for(; i != recipes.end(); i++){
    (i->second).write_to_file(ofs);
  }
}
