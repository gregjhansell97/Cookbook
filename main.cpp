#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include "Recipe.h"
#include "Recipe_Collection.h"

using namespace std;

Recipe_Collection recipes;

/*Objective: opens the data file, and writes all the recipes into
the file.
Parameters: takes in a file name and a reference variable that
acts as the write value named rs(recipes)*/
void save_data(const char* file_name);

/*Objective: opens the data file, and makes all the recipes
into programable objects
Parameters: takes in a file name and a reference variable that
acts as the return value, named rs (recipes)*/
void retrieve_data(const char* file_name);

/*Objective: used in the retrieve_data function, to break up the
ingrediants into the measurement and type
Parameters: takes in a file stream and two referennce variables,
s1 : s2 is how the string is split*/
bool splitline(ifstream& data, string& s1, string& s2);

void add_recipe();

void remove_recipe();

void recipes_with();

void save_data(const char* file_name){
	ofstream data;
  data.open(file_name);
	recipes.write_to_file(data);
	data.close();
}

void recipes_with(){
	string x = "";
	cout << "Ingredient:";
	getline(cin, x);
	//cout << Recipe::recipes[x].size() << endl;
	list<Recipe*> r = Recipe::recipes[x];
	list<Recipe*>::iterator i = r.begin();
	for(; i != r.end(); i ++){
		cout << (*i)->get_name() << endl;
	}
}

void retrieve_data(const char* file_name){
	ifstream data(file_name);
	string temp1, temp2, temp3; //three string variables used for text parsing
	while(getline(data, temp1)){ //cookbook name
		getline(data, temp2); //page number
		getline(data, temp3); //recipe name
		Recipe* r = recipes.add_recipe(Recipe(temp1, temp2, temp3));
		while(splitline(data, temp1, temp2)){
	  	r->add_ingredient(temp1, temp2);
		}
	}
	data.close();
}

bool splitline(ifstream& data, string& s1, string& s2){
	string temp;
	s1 = s2 = "";
	while(data >> temp){
		if(temp == ":") break;
		if(temp == "----------") return getline(data, s2) && false;
		if(s1 != "") s1 += " ";
		s1 += temp;
	}
	data >> temp;
	if(!getline(data, s2)) return false;
	s2 = temp + s2;
	return true;
}

void add_recipe(){
  string book_name, page_number, name, ingr, meas;
	cout << "book name: ";
	getline(cin, book_name);
	cout << "page_number: ";
	getline(cin, page_number);
	cout << "name: ";
	getline(cin, name);
	cout << "ingredients:" << endl;
	Recipe r(book_name, page_number, name);
	while(meas != "recipe complete"){
		cout << "ingredient: ";
		getline(cin, ingr);
		if(ingr == "recipe complete") break;
		cout << "measurement: ";
		getline(cin, meas);
		r.add_ingredient(ingr, meas);
	}
	recipes.add_recipe(r);
}

void remove_recipe(){
	string book_name, page_number, name;
	cout << "book name: ";
	getline(cin, book_name);
	cout << "page_number: ";
	getline(cin, page_number);
	cout << "name: ";
	getline(cin, name);
	recipes.remove_recipe(name + page_number + book_name);
}

int main(){
	string cmd = "";
	cout << "Getting file data" << endl;
  retrieve_data("data.txt");
	while(cmd != "exit"){
		getline(cin, cmd);
		if(cmd == "save"){
		  save_data("data.txt");
		}else if(cmd == "add"){
			add_recipe();
		}else if(cmd == "rm"){
			remove_recipe();
		}else if(cmd == "exit"){
			break;
		}else if(cmd == "ingredient"){
			recipes_with();
		}else{
			cout << "COMMAND NOT FOUND" << endl;
		}
	}
	cout << "Saving file data" << endl;
	save_data("data.txt");
}
