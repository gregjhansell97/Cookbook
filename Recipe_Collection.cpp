#include "Recipe_Collection.h"

using namespace std;

Recipe_Collection::Recipe_Collection(){
  //do something
}

//Recipe* Recipe_Collection::add_recipe(Recipe r){}
void Recipe_Collection::write_to_file(ofstream& ofs){
  map<string, Recipe>::iterator i = recipes.begin();
  for(; i != recipes.end(); i++){
    (i->second).write_to_file(ofs);
  }
}

void Recipe_Collection::print(){
  map<string, Recipe>::iterator i = recipes.begin();
  for(; i != recipes.end(); i++){
    (i->second).print();
    cout << endl;
  }
}
