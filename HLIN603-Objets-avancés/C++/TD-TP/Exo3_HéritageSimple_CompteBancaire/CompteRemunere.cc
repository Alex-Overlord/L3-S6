#include <iostream>
using namespace std;
#include "CompteBancaire.h"
#include "CompteRemunere.h"

CompteRemunere::CompteRemunere() : CompteBancaire() {}

CompteRemunere::CompteRemunere(int s) : CompteBancaire(s) {}

// CompteRemunere::CompteRemunere(int s, int b) : CompteBancaire(s) {
// 	bonus = b;
// }

CompteRemunere::~CompteRemunere() {
	cout << "_3\n";
	solde *= 1.1;
}

void CompteRemunere::deposer(int m) {
	solde += m * 1.01;
}