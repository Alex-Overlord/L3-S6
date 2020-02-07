#include <iostream>
using namespace std;
#include "CompteBancaire.h"
#include "CompteRemunere.h"
#include "CompteRemunereAvecCarteCredit.h"

CompteRemunereAvecCarteCredit::CompteRemunereAvecCarteCredit() {}

CompteRemunereAvecCarteCredit::CompteRemunereAvecCarteCredit(float s) 
	: CompteBancaire(s) {}

CompteRemunereAvecCarteCredit::~CompteRemunereAvecCarteCredit() {
	solde -= 5;
}

void CompteRemunereAvecCarteCredit::deposer(float m) {
	solde += m;
	cout << "Montant du solde : " << solde << endl;
}