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
void Recipe_Collection::print_recipes(){
  string current_book_name =  "";
  string indentation = "  ";
  map<string, Recipe>::iterator i = recipes.begin();
  for(; i != recipes.end(); i++){
    string book_name = (i->second).get_book_name();
    if(book_name != current_book_name){
      cout << book_name << ":" << endl;
      current_book_name = book_name;
    }
    cout << "  " << (i->second).get_name() << ": " << (i->second).get_page_number() << endl;
  }
}
void Recipe_Collection::print_data(){
  map<string, Recipe>::iterator i = recipes.begin();
  for(; i != recipes.end(); i++){
    (i->second).print_data();
    cout << endl;
  }
}
