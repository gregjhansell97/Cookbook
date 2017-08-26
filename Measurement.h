#include <assert.h>
#include <string>
#include <fstream>
#include <map>

#include <iostream> //NOTE DELETE ME!!

using namespace std;
#ifndef Measurement_h
#define Measurement_h

enum Measurement_Type{ DRY, LIQUID, MASS, QUANTITY, UNKNOWN };

class Measurement{
public:
  //constructors
  Measurement(); // unit = "", amount = 0, UNKNOWN
  Measurement(float a, const string& u, Measurement_Type s); //u : unit, a : amount, s : style
  Measurement(const Measurement& m); //copy constructor
  Measurement(const Measurement& m1, const Measurement& m2); //adding two measurements together

  //getters
  float get_amount() const{ return amount; }
  string get_unit() const{ return unit; }
  Measurement_Type get_style() const{ return style; }
  string get_signature() const; //the delimited string used in split(s)

  //setters
  void set_amount(float a){ amount = a; }
  void set_unit(const string& u); //changes the unit and modifies the amount accordingly

  //operators
  Measurement operator*(float v){ return Measurement(amount*v, unit, style); }
  Measurement operator/(float den){  return Measurement(amount/den, unit, style); } //divides the amount
  Measurement operator+(Measurement m); //adds two measurements together
  //comparators that look at the two values with respect to their units
  bool operator<(Measurement m);
  bool operator==(Measurement m);
  bool operator<=(Measurement m){ return ((*this) < m || (*this) == m); }
  bool operator>(Measurement m){ return !(*this <= m); }
  bool operator>=(Measurement m){ return !(*this < m); }

  //static
  //format: <character as style like: M> <factor1> <measurement1> ... END
  static void create_conversion_table(const char* fn); //the conversion table used to go from one unit to another
  static int measurement_type_to_index(Measurement_Type mt); //index used in the conversion table
  static Measurement_Type char_to_measurement_type(char c); //'K' : UNKNOWN, 'D' : DRY, 'L' : LIQUID, 'M' : MASS, 'Q' : QUANTITY


private:
  //variables
  string unit; //cups, pounds, grams
  float amount; //1.24 (not 1/4)
  Measurement_Type style; //DRY, WET or QUANTITY
  static map<string, float> conversion_table[3]; //conversion table used for DRY LIQUID and MASS measurement types
};

#endif
