
#include <map>
#include <vector>
#include <string>
#include <iostream>

#include "Amount.h"

using namespace std;

#ifndef Component_h
#define Component_h

class Component{
public:
  //getters
  string get_name(){ return name; }
  virtual void print(){cout << "HELLO WOrld" << endl; }

protected:
  Component();
  Component(const string& nm);
  Component(const Component& c); //copy constructor
  string name;

private:

};

#endif
