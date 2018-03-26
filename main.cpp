#include <iostream>
#include <stdint.h>

#include "./interface/Item.h"
#include "./interface/Ingredient.h"
#include "./interface/Product.h"

using namespace std;

typedef unsigned __int128 uint128_t;
int main(){

  cout << "Hello world" << endl;
  Item *i = Ingredient::create_ingredient("bread");
  Item *j = Product::create_product("bread");
  Item *c = Product::create_product("salt");
  i->print();
  if(i == j){
    cout << "Hey we're equivalent" << endl;
  }
  c->print();
  uint128_t x = 0;
  //i.test();
}
