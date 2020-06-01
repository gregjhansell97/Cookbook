#include <string>
#include <map>

#include "Item.h"

using namespace std;

#ifndef Product_h
#define Product_h

class Product : Item{
public:

  static Item* create_product(string _name);

private:
  static map<string, Item*> products;
  Product();
  Product(string _name);
};

#endif
