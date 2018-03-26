#include "./interface/Product.h"

map<string, Item*> Product:: products;

Item* Product::create_product(string nm){
  map<string, Item*>::iterator itr = products.find(nm);
  if(itr == products.end()){ //key does not exist
    //making new key
    Item* prod = new Product(nm); //allocating memory to use
    products.insert(pair<string, Item*>(nm, prod));
    return prod; //returns the newly allocated pointer that was added to the map
  }
  return itr->second;
}

Product::Product():Item(){}

Product::Product(string nm):Item(nm){}
