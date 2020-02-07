#include <iostream>
using namespace std;
#include "CompteBancaire.h"
#include "CompteDepot.h"

CompteDepot::CompteDepot() {}

CompteDepot::CompteDepot(int s) : CompteBancaire(s) {}

CompteDepot::~CompteDepot() {
	solde -= 100;
}

void CompteDepot::deposer(int m) {
	if (m >= 1000) {
		m += 10;
	}
	m -= 1;
	solde += m;
}