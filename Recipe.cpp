#include "Recipe.h"


Recipe::Recipe(){
  name = "";
  description = "";
  serving_size = 0;
}

Recipe::Recipe(string nm, string des){
  name = nm;
  description = des;
}

Recipe::Recipe(ifstream &raw_data){
  string s = "";

  //name
  raw_data >> name;
  while(true){
    if(raw_data >> s && s != "$|$"){
      name = name + " " + s;
    }else break;
  }

  //description
  raw_data >> description;
  while(true){
    if(raw_data >> s && s != "$|$"){
      description = description + " " + s;
    }else break;
  }

  //ingredient
  while(true){
    string ingr_str;
    raw_data >> ingr_str;
    if(ingr_str == "END") return;
    while(true){
      if(raw_data >> s && s != "$|$"){
        ingr_str = ingr_str + " " + s;
      }else break;
    }
    Ingredient* ingr = Ingredient::create_ingredient(ingr_str);


    float amount;
    char style_chr;
    string unit;

    //amount
    raw_data >> amount;

    //unit
    raw_data >> unit;
    while(true){
      if(raw_data >> s && s != "$|$"){
        unit = unit + " " + s;
      }else break;
    }
    raw_data >> style_chr;

    //measurement
    Measurement m(amount, unit, Measurement::char_to_measurement_type(style_chr));

    add_ingredient(ingr, m);

  }
}

void Recipe::print_recipe(){
  cout << name << endl;
  cout << description << endl;
  Recipe_Components::iterator itr;
  itr = ingredients.begin();
  for(; itr != ingredients.end(); itr++){
    cout << "   " << itr->first->get_name() << " " << itr->second.get_signature() << endl;
  }
}
