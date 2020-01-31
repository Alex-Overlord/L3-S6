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
	cout << *s2;
	cin >> *s2;

	// // test de l'oparateur d'affectation
	Strophe* s3 = new Strophe();
	*s3 = *s2;
	// s1->affiche(cout);
	// s2->affiche(cout);
	// s3->affiche(cout);

}