#include <iostream>
#include <string>
using namespace std;
#include "Vers.h"
#include "Strophe.h"

int main() {
/*
  Vers* v1 = new Vers();
  
  cout << "Saisi d'un vers\n";
  cin >> *v1; // les espaces posent problèmes
  cout << (*v1).getSuiteMots() << endl << (*v1).getRime() << endl;
  cout << *v1 << endl;
*/
	Strophe* s1 = new Strophe();
	cin >> *s1;
	cout << *s1;

	// test constructeur par copie
	Strophe* s2 = new Strophe(*s1);
	cout << "-- 1\n";
	cout << *s2;
	cout << "-- 2\n";
	cin >> *s2;
	cout << "-- 3\n";
	cout << *s2;

	cout << "-- 4\n";
	// // test de l'oparateur d'affectation
	Strophe* s3 = new Strophe();
	cout << "-- 5\n";
	s3 = s2;
	cout << "-- 6\n";
	cout << *s1;
	cout << "-- 7\n";
	cout << *s2;
	cout << "-- 8\n";
	cout << *s3;
	cout << "-- 9\n";
}