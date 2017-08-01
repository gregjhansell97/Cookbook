#include "Ingredient.h"

Ingredient::Ingredient(){
  name = "";
}

Ingredient::Ingredient(const string& n, const string& m){
  name = n;
  measurement = m;
}

void Ingredient::print() const{
  cout << name << " : " << measurement.get_name() << endl;
}
