
#include <string>
#include <list>
#include <vector>
#include <fstream>
#include <iostream>
#include <unordered_map>
#include "Ingredient.h"
#include "Ingredient_Collection.h"

using namespace std;

#ifndef Recipe_h
#define Recipe_h

class Recipe{
public:
  static unordered_map<string, list< Recipe* > >  recipes; //recipes hashed to ingredients
  unsigned int occurence = 0;
  unsigned int match_count = 0;
  //bn = book name  pn = page number  n = name
  Recipe(const string& bn = "", string pn = "", const string& n = "");

  //getters
  string get_book_name() const{ return book_name;}
  string get_page_number() const{ return page_number;}
  string get_name() const{ return name; }
  string get_key() const{ return name + page_number + book_name; } //acts as the objects signature, that makes it easy to alphabetize
  bool match_count_at_max const{ return match_count == ingredients.size(); }
  //setters
  //Add ingredient (n = name, m = measurement)
  void add_ingredient(const string& n, const string& m);

  //other
  void print() const; //useful for debugging
  void write_to_file(ofstream& ofs) const;
  friend bool operator==(const Recipe& lhs, const Recipe& rhs);

private:

  string book_name;
  string page_number;
  string name;
  Ingredient_Collection ingredients;
};

vector<Recipe> find_recipes(vector<string> &s);

#endif
