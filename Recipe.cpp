
#include "Recipe.h"

using namespace std;

unordered_map<string, list< Recipe* > > Recipe::recipes;

Recipe::Recipe(const string& bn, string pn, const string& n){
  book_name = bn;
  page_number = pn;
  name = n;
}

void Recipe::add_ingredient(const string& n, const string& m){
  recipes[n].push_back(this); //keeps track of what recipes need each ingredient
  ingredients.add_ingredient(Ingredient(n, m));
}

void Recipe::print() const{
  cout << "book name: " <<book_name << endl;
  cout << "page number: "<< page_number << endl;
  cout << "name: " << name << endl;
  cout << "ingredients: " << endl;
  ingredients.print();
}

void Recipe::write_to_file(ofstream& ofs) const{
  ofs << book_name << endl;
  ofs << page_number << endl;
  ofs << name << endl;
  ingredients.write_to_file(ofs);
  ofs << "----------" << endl;
}
