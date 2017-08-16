#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include "Measurement.h"

using namespace std;



int main(){
  Measurement m("10.6750000:cups:Q");
  cout << m.get_amount() << endl;
  cout << m.get_unit() << endl;
  cout << m.get_style() << endl;
  cout << m.get_signature() << endl;
}
