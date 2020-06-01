#include "./interface/Product.h"

map<string, Item*> Product:: products;

Item* Product::create_product(string _name){
  map<string, Item*>::iterator itr = products.find(_name);
  if(itr == products.end()){ //key does not exist
    //making new key
    Item* prod = new Product(_name); //allocating memory to use
    products.insert(pair<string, Item*>(_name, prod));
    return prod; //returns the newly allocated pointer that was added to the map
  }
  return itr->second;
}

Product::Product():Item(){}

Product::Product(string _name):Item(_name){}
