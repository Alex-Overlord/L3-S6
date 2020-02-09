#include <iostream>
using namespace std;
#include "CompteBancaire.h"
#include "CompteRemunere.h"
#include "CompteDepot.h"
#include "CompteDepotRemunere.h"

CompteDepotRemunere::CompteDepotRemunere() : CompteBancaire() {}

CompteDepotRemunere::CompteDepotRemunere(float s) : CompteBancaire(s) {}

CompteDepotRemunere::~CompteDepotRemunere() {
	solde *= 1.1;
}

void CompteDepotRemunere::deposer(float m) {
	cout << "avant : " << solde << endl;
	cout << "deposer(" << m << ")" << endl;
	solde += m * 1.01;
	cout << "après : " << solde << endl;
}