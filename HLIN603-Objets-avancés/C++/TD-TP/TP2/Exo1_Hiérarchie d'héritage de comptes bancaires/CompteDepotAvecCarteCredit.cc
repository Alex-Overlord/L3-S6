#include <iostream>
using namespace std;
#include "CompteBancaire.h"
#include "CompteDepot.h"

CompteDepot::CompteDepot() {}

CompteDepot::CompteDepot(float s) : CompteBancaire(s) {}

CompteDepot::~CompteDepot() {
	// solde -= 100;
}

void CompteDepot::deposer(float m) {
	// cout << solde << " avant" << endl;
	// cout << "deposer(" << m << ")" << endl;
	// if (m >= 1000) {
	// 	m += 10;
	// }
	// m -= 1;
	// solde += m;
	// cout << solde << " après" << endl;
}