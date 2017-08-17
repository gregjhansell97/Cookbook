#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include "Measurement.h"

using namespace std;



int main(){
  Measurement::create_conversion_table("measurement_conversion_table.txt");
  Measurement m("10:cups:Q");
  Measurement k = m/2;

  //cout << m.get_amount() << endl;
  //cout << m.get_unit() << endl;
  //cout << m.get_style() << endl;
  cout << k.get_signature() << endl;
}
