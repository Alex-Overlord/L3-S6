#include <iostream>
using namespace std;
#include "CompteBancaire.h"

CompteBancaire::CompteBancaire() { 
	solde = 0; 
}

CompteBancaire::CompteBancaire(float s) : solde(s) {}

CompteBancaire::~CompteBancaire() { 
	cout << "solde = " << solde << endl; 
}

void CompteBancaire::deposer(float m) { 
	cout << solde << " avant" << endl;
	cout << "deposer(" << m << ")" << endl;
	solde += m; 
	cout << solde << " après" << endl;
}