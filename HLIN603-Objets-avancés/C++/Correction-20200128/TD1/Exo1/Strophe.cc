// $Id$

#include<iostream>
#include<string>
using namespace std;
#include"Vers.h"
#include"Strophe.h"

Strophe::Strophe () {
  suiteVers=NULL;
  nbVers=0;
}//Strophe

Strophe::Strophe (const Strophe& autreStrophe) {
  /* Avec copie :
  nbVers=autreStrophe.nbVers;
  suiteVers=new Vers*[nbVers];
  for (int i=0; i<nbVers; i++)
    suiteVers[i]=autreStrophe.suiteVers[i]; */
  // Sans copie
  *this=autreStrophe;
}

Strophe::~Strophe () {
  if (suiteVers) delete[] suiteVers;
}//~Strophe

const Vers* Strophe::vers (int i) const {
  if (i>=0 && i<nbVers)
    return suiteVers[i];
  else
    return NULL;
}//vers

void Strophe::saisie (istream& is) {
  if (suiteVers) delete[] suiteVers;
  cout << "Entrer le nombre de vers : ";
  is>>nbVers; suiteVers = new Vers*[nbVers];
  for (int i=0; i<nbVers; i++) {
    Vers *v=new Vers();
    v->saisie(is);
    suiteVers[i]=v;
  }//for
}//saisie

void Strophe::affiche (ostream& os) const {
  for (int i=0; i<nbVers; i++) {
    suiteVers[i]->affiche(os);
    os << endl;
  }//for
}//affiche

Strophe& Strophe::operator=(const Strophe& s) {
  cout << "passage par affectation" << endl;
  if (this != &s) { //pour le cas x=x
    if (suiteVers) delete[] suiteVers; //effacer l'ancienne strophe
    nbVers=s.nbVers; //copier le champ de type entier
    suiteVers=new Vers*[nbVers]; //copie (profonde) du tableau de vers
    for (int i=0; i<nbVers; i++) //les vers restent partagŽs
      suiteVers[i]=s.suiteVers[i];
  }//if
  return *this; //pour autoriser x=y=z
}//=

Vers*& Strophe::operator[] (int i) {
  return suiteVers[i];
}//[]

ostream& operator<< (ostream& flotSortie, const Strophe& s) {
  s.affiche(flotSortie);
  return flotSortie;
}//<<

istream& operator>> (istream& flotEntree, Strophe& s) {
  s.saisie(flotEntree);
  return flotEntree;
}//>>
