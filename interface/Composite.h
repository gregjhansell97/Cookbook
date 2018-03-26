#include <vector>
#include <map>

#include "Amount.h"
#include "Component.h"
#include "Item.h"

using namespace std;

#ifndef Composite_h
#define Composite_h

typedef pair<Component, Amount> MeasuredComponent;

class Composite : Component{
public:
  Composite();
  Composite(string nm);
  void print();
  virtual void set_items(map<Item*, Amount> &items) = 0;
protected:
  string name;
private:
  vector<MeasuredComponent> components;
};

#endif
