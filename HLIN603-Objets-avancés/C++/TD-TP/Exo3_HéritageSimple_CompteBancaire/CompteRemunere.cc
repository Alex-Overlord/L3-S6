#include <iostream>
using namespace std;
#include "CompteBancaire.h"
#include "CompteRemunere.h"

CompteRemunere::~CompteRemunere() {
	solde *= 1.1;
	CompteBancaire::~CompteBancaire();
}

void CompteRemunere::deposer(int montant) {
	
}