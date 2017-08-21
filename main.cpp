#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include "Ingredient.h"
#include "Measurement.h"

using namespace std;



int main(){
  Measurement::create_conversion_table("measurement_conversion_table.txt");
  Ingredient::create_ingredients("ingredients.txt");

  Ingredient* i = Ingredient::create_ingredient("chicken");

  const int* x = i->get_taste();

  cout << x[3] << endl;


  Measurement m1("kilogram", 3, QUANTITY);
  Measurement m2("ounce", 1, QUANTITY);

  Measurement m3(m1, m2);

  cout << m3.get_signature() << endl;
/*
  vector<Flavor> t;
  t.push_back(SALTY);
  t.push_back(SAVORY);

  Ingredient *foo = Ingredient::create_ingredient("chicken");
  //Measurement::create_conversion_table("measurement_conversion_table.txt");
  //Measurement m("10:cups:Q");
  //Measurement k = m/2;

  Ingredient *bar = Ingredient::create_ingredient("chicken", t);

  if(bar == foo){
    cout << "They match!" << endl;
  }
  if(foo->get_taste()[1] == SAVORY) cout << "this actually worked" << endl;

  //cout << m.get_amount() << endl;
  //cout << m.get_unit() << endl;
  //cout << m.get_style() << endl;
  //cout << k.get_signature() << endl;
  */
}
