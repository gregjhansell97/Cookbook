
#include "Recipe.h"

using namespace std;

unordered_map<string, list< Recipe* > > Recipe::recipes;

Recipe::Recipe(const string& bn, string pn, const string& n){
  book_name = bn;
  page_number = pn;
  name = n;
  occurence = 0;
  match_count = 0;
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

vector<Recipe*> find_recipes(vector<string> &s){
  static unsigned int occurence = 0;
  vector<Recipe*> matched_recipes;
  for(unsigned int i = 0; i < s.size(); i++){
    list<Recipe*> r = Recipe::recipes[s[i]];
  	list<Recipe*>::iterator itr = r.begin();
  	for(; itr != r.end(); itr++){
      if((*itr)->occurence != occurence){
        (*itr)->occurence = occurence;
        (*itr)->match_count = 0;
      } else if((*itr)->match_count_at_max()){
        matched_recipes.push_back(*itr);
      }
      (*itr)->match_count++;
  	}
  }
  occurence++;
  return matched_recipes;
}
