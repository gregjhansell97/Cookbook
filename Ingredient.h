#include <string>

using namespace std;

#ifndef Ingredient_h
#define Ingredient_h

class Ingredient{
public:
  Ingredient(const string& n, const string& m);

  //getters
  unsigned int get_prime_attachment(){ return prime_attachment;};
  string get_name() const{ return name; };
  string get_measurement() const{ return measurement; };

  //other
  void print() const;

private:
  //There should be a hashmap of ingredients with corresponding prime numbers
  unsigned int prime_attachment; //a prime number signifiying specific ingredient
  string name;
  string measurement;
};

#endif
