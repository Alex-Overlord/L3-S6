#include <iostream>
using namespace std;
#include "CompteBancaire.h"
#include "CompteRemunere.h"
#include "CompteRemunereAvecCarteCredit.h"

CompteRemunereAvecCarteCredit::CompteRemunereAvecCarteCredit() {}

CompteRemunereAvecCarteCredit::CompteRemunereAvecCarteCredit(float s) 
	: CompteRemunere(s) {}

CompteRemunereAvecCarteCredit::~CompteRemunereAvecCarteCredit() {
	solde -= 5;
}

void CompteRemunereAvecCarteCredit::deposer(float m) {
	cout << "avant : " << solde << endl;
	cout << "deposer(" << m << ")" << endl;
	solde += m;
	cout << "après : " << solde << endl;
}