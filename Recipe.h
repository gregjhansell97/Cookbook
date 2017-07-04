#include <string>
#include <vector>
#include <fstream>
#include "Ingredient.h"
#include "Ingredient_Collection.h"

using namespace std;
#ifndef Recipe_h
#define Recipe_h

class Recipe{
public:
  Recipe(const string& bn = "", string pn = "", const string& n = "");
  //getters
  string get_book_name() const{ return book_name;}
  string get_page_number() const{ return page_number;}
  string get_name() const{ return name; }
  string get_key() const{ return name + page_number + book_name; }

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

bool operator==(const Recipe& lhs, const Recipe& rhs);
#endif
