#include <iostream>
using namespace std;
#include "CompteBancaire.h"

CompteBancaire::CompteBancaire() { 
	solde = 0; 
}

CompteBancaire::CompteBancaire(int s) : solde(s) {}

CompteBancaire::~CompteBancaire() { 
	cout << "solde = " << solde << endl; 
}

void CompteBancaire::deposer(int m) { 
	solde += m; 
}