#include <assert.h>
#include <string>
#include <fstream>
#include <iostream>
#include <map>

using namespace std;
//need to add this comment to repush
#ifndef Measurement_h
#define Measurement_h

enum Measurement_Type{ DRY, LIQUID, MASS, QUANTITY, UNKNOWN };

class Measurement{
public:
  Measurement();
  Measurement(const string& u, float a, Measurement_Type s);
  Measurement(const Measurement& m);
  Measurement(const Measurement& m1, const Measurement& m2);
  Measurement(const string &s){ split(s); }

  //getters
  float get_amount() const{ return amount; }
  string get_unit() const{ return unit; }
  Measurement_Type get_style() const{ return style; }
  string get_signature() const;

  //setters
  void set_amount(float a){ amount = a; }
  void set_unit(const string& u){ unit = u; }
  void set_style(Measurement_Type s){ style = s; }

  //operators
  Measurement operator/(float den){  return Measurement(unit, amount/den, style); }
  Measurement operator+(Measurement m);
  bool operator<(Measurement m);
  bool operator==(Measurement m);
  bool operator<=(Measurement m){ return ((*this) < m || (*this) == m); }
  bool operator>(Measurement m){ return !(*this <= m); }
  bool operator>=(Measurement m){ return !(*this < m); }

  //static
  static void create_conversion_table(const char* fn);
  static int measurement_type_to_index(Measurement_Type mt);
  static Measurement_Type char_to_measurement_type(char c);

  static map<string, float> conversion_table[3];

private:
  //variables
  string unit; //cups, pounds, grams
  float amount; //1.24 (not 1/4)
  Measurement_Type style; //DRY, WET or QUANTITY


  //functions
  void split(const string &s);
};

#endif
