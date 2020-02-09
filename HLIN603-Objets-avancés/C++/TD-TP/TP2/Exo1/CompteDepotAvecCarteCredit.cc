#include <iostream>
using namespace std;
#include "CompteBancaire.h"
#include "CompteDepot.h"
#include "CompteDepotAvecCarteCredit.h"

CompteDepotAvecCarteCredit::CompteDepotAvecCarteCredit() {}

CompteDepotAvecCarteCredit::CompteDepotAvecCarteCredit(float s) : CompteDepot(s) {}

CompteDepotAvecCarteCredit::~CompteDepotAvecCarteCredit() {
	solde -= 100;
}

void CompteDepotAvecCarteCredit::deposer(float m) {
	cout << "avant : " << solde << endl;
	cout << "deposer(" << m << ")" << endl;
	if (m >= 1000) {
		m += 10;
	}
	m -= 1;
	solde += m;
	cout << "après : " << solde << endl;
}