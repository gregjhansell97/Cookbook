#include "Ingredient_Collection.h"

using namespace std;

void Ingredient_Collection::add_ingredient(Ingredient i){
  ingredients.push_back(i);
}

void Ingredient_Collection::print_data() const{
  for(unsigned int i = 0; i < ingredients.size(); i++){
    cout << "  ";
    ingredients[i].print_data();
  }
}

void Ingredient_Collection::write_to_file(ofstream& ofs) const{
  for(unsigned int i = 0; i < ingredients.size(); i++){
    ofs << ingredients[i].get_name() << " : " << ingredients[i].get_measurement() << endl;
  }
}
