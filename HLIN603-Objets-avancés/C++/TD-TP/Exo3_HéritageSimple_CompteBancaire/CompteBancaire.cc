#include <iostream>
using namespace std;
#include "CompteBancaire.h"

CompteBancaire::CompteBancaire() { solde = 0; }
CompteBancaire::CompteBancaire(int _solde) : solde(_solde) {}
CompteBancaire::~CompteBancaire() { cout << "solde = " << solde << endl; }
void CompteBancaire::deposer(int montant) { solde += montant; }