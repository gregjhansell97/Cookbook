
#include <iostream>
#include <map>
#include <string>

#include "Component.h"

#ifndef Item_h
#define Item_h

using namespace std;

class Item : public Component {
public:
  void print();
protected:
  Item();
  Item(string nm);
};

#endif
