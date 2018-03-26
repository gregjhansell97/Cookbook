#include <string>

#include "Composite.h"

using namespace std;

#ifndef Recipe_h
#define Recipe_h

class Recipe : Composite{
public:
  Recipe();
  Recipe(string _name, string _description, float _serving_size);

  //getters
  string get_name(){ return name; }
  string get_description(){ return description; }
  float get_serving_size(){ return serving_size; }

  void set_items(map<Item*, Amount> &items);

private:
  string description;
  float serving_size;
};

#endif
