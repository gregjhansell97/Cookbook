#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include "Ingredient.h"
#include "Measurement.h"
#include "Recipe.h"

using namespace std;

bool recipe_test(){
  ifstream raw_data("test.txt");

  Recipe r(raw_data);
  r.print_recipe();

  Recipe secret_formula(raw_data);
  secret_formula.print_recipe();

  return true;
}

int main(){

  assert(recipe_test());

}
