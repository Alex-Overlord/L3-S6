#include <iostream>
using namespace std;
#include "CompteBancaire.h"
#include "CompteRemunere.h"
#include "CompteRemunereAvecCarteCredit.h"

CompteRemunereAvecCarteCredit::CompteRemunereAvecCarteCredit() {}

CompteRemunereAvecCarteCredit::CompteRemunereAvecCarteCredit(int s) 
	: CompteBancaire(s) {}

CompteRemunereAvecCarteCredit::~CompteRemunereAvecCarteCredit() {
	cout << "_2\n";
	solde -= 5;
}

void CompteRemunereAvecCarteCredit::deposer(int m) {
	cout << "_1\n";
	solde += m;
	cout << "Montant du solde : " << solde << endl;
}