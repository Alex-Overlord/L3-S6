#include <iostream>
using namespace std;
#include "CompteBancaire.h"
#include "CompteDepot.h"

CompteDepot::~CompteDepot() {
	solde -= 100;
	CompteBancaire::~CompteBancaire();
}