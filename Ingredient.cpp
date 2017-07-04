#include "Ingredient.h"
#include <iostream>

using namespace std;

Ingredient::Ingredient(const string& n, const string& m){
  prime_attachment = 1;
  name = n;
  measurement = m;
}

void Ingredient::print() const{
  cout << name << " : " << measurement << endl;
}
