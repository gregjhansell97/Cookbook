#include "Ingredient.h"

//static variables:
bool Ingredient::locked = true;
map<string, Ingredient*> Ingredient::ingredients;

Ingredient::Ingredient(){
  assert(!locked); //must use create_ingredient static method
  name = "";
  taste[0] = taste[1] = taste[2] = taste[3] = taste[4] = taste[5] = 0;
  locked = true;
}

Ingredient::Ingredient(string nm){
  assert(!locked);
  name = nm;
  taste[0] = taste[1] = taste[2] = taste[3] = taste[4] = taste[5] = 0;
  locked = true;
}

Ingredient* Ingredient::create_ingredient(string nm){
  locked = false;//allows the constructor to be used
  Ingredient* ing = new Ingredient(nm); //allocating memory to use
  pair<map<string, Ingredient*>::iterator, bool> itr_bol = ingredients.insert(pair<string, Ingredient*>(nm, ing)); //tries to add newly allocated ingredient
  if(!itr_bol.second){ //key already existed
    delete ing; //release potential memory
    return itr_bol.first->second; //returns the pointer to the current ingredient
  }
  return ing; //returns the newly allocated pointer that was added to the map
}

//<name> END 0 0 0 0 0 0 -1 //
void Ingredient::create_ingredients(const char* fn){
  ifstream igr_file(fn); //conversion table file
  assert(igr_file.is_open());

  Ingredient *ing = NULL;
  int flavor_scale = 0;
  string s, nm;

  while(igr_file >> nm){
    int index = 0;
    while(igr_file >> s){
      if(s == "END") break;
      nm = nm + " " + s;
    }
    ing = create_ingredient(nm);

    while(igr_file >> flavor_scale || index > FLAVORS - 1){
      if(flavor_scale < 0) break;
      ing->taste[index] = flavor_scale;
      index++;
    }
  }
  igr_file.close();
}

void Ingredient::save_ingredients(const char* fn){
  ofstream igr_file(fn);
  map<string, Ingredient*>::iterator itr = ingredients.begin();
  for(; itr != ingredients.end(); itr++){
    Ingredient* ing = (itr->second);
    igr_file << ing->name << " END ";
    for(int i = 0; i < FLAVORS; i++){
      igr_file << ing->taste[i] << " ";
    }
    igr_file << "-1\n";
  }

  igr_file.close();
}
