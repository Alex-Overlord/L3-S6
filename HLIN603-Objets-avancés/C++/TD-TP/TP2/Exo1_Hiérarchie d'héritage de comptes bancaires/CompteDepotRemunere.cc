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
	solde += m * 1.01;
}