#include <iostream>
#include <string>
using namespace std;
#include "Vers.h"
#include "Strophe.h"

Strophe::Strophe() { suiteVers = NULL; nbVers = 0; }
Strophe::Strophe(const Strophe& autreStrophe) { 
  nbVers = autreStrophe.nbVers;  
  suiteVers = new Vers*[nbVers];
  for (int i = 0; i < nbVers; i++) 
    suiteVers[i] = autreStrophe.suiteVers[i];
}
Strophe::~Strophe() { if (suiteVers) delete[] suiteVers; }
// on ne détruit que le tableau, pas les vers.

Vers* Strophe::vers(int i) const {
  if (i >= 0 && i < nbVers) return suiteVers[i];
  else return NULL;
}

void Strophe::saisie(istream& is) {
  if (suiteVers) delete[] suiteVers;
  cout << "Entrer le nombre de vers :\n";
  is >> nbVers;
  suiteVers = new Vers* [nbVers];
  for (int i = 0; i < nbVers; i++) {
    Vers* v = new Vers();
    v->saisie(is);
    suiteVers[i] = v;
  }
}

void Strophe::affiche(ostream& os) const {
  for (int i = 0; i < nbVers; i++) {
    suiteVers[i]->affiche(os);
    os << endl;
  }
}

Strophe& Strophe::operator=(const Strophe& s) {
  cout << "passage par affectation\n";
  if (this != &s) { // on compare les adresses
    if (suiteVers) delete[] suiteVers;
    nbVers = s.nbVers;
    for (int i = 0; i < nbVers; i++)
      suiteVers[i] = s.suiteVers[i];
    return *this;
  }
}
Vers*& Strophe::operator[](int i) { 
  return suiteVers[i]; 
}

ostream& operator<<(ostream& flotSortie, const Strophe& s) {
  s.affiche(flotSortie);
  return flotSortie;
}

istream& operator>>(istream& flotEntree, Strophe& s) {
  s.saisie(flotEntree);
  return flotEntree;
}