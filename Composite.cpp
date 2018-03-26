#include "./interface/Composite.h"

Composite::Composite():Component(){
  cout << "COMPOSITE: I'm being initialized" << endl;
}

Composite::Composite(string nm):Component(nm){
  cout << "COMPOSITE: I'm being initialized" << endl;
}

void Composite::print(){
  cout << name << endl;
}
