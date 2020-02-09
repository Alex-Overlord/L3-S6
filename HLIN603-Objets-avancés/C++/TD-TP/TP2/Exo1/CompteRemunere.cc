#include <iostream>
using namespace std;
#include "CompteBancaire.h"
#include "CompteRemunere.h"

CompteRemunere::CompteRemunere() : CompteBancaire() {}

CompteRemunere::CompteRemunere(float s) : CompteBancaire(s) {}

CompteRemunere::~CompteRemunere() {
	solde *= 1.1;
}

void CompteRemunere::deposer(float m) {
	cout << "avant : " << solde << endl;
	cout << "deposer(" << m << ")" << endl;

	solde += m * 1.01;

	cout << "après : " << solde << endl;
}