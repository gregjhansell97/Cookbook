#include "./interface/Component.h"

Component::Component(){
  name = "";
}

Component::Component(const Component& c){
  //TODO: write copy constructor
  name = "";
}

Component::Component(const string& nm){
  cout << "COMPONENT: I'm being constructed!" << endl;
  name = nm;
}
