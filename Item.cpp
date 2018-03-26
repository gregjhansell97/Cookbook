#include "./interface/Item.h"

Item::Item():Component(){}

Item::Item(string nm):Component(nm){
  cout << "Im here!" << endl;
}

void Item::print(){
  cout << name << endl;
}
