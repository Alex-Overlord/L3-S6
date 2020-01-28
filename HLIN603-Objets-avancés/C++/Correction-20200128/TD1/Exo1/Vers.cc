// $Id$

#include<iostream>
#include<string>
using namespace std;
#include"Vers.h"

Vers::Vers () {}//Vers

Vers::Vers (string sm) {
  suiteMots=sm;
}//Vers

Vers::Vers (string sm, string r) {
  suiteMots=sm;
  rime=r;
}//Vers

Vers::~Vers () {
  cout <<"destructeur vers" <<endl;
}//~Vers

string Vers::getSuiteMots () const {
  return suiteMots;
}//getSuiteMots

void Vers::setSuiteMots (string sm) {
  suiteMots=sm;
}//setSuiteMots

string Vers::getRime () const {
  return rime;
}//getRime

void Vers::setRime (string r) {
  rime=r;
}//setRime

void Vers::saisie (istream& is) {
  cout <<"Vers, puis rime :" <<endl;
  is>>suiteMots>>rime;
}//saisie

void Vers::affiche (ostream& os) const {
  os<<"<<"<<suiteMots<<">>";
}//affiche

// on retourne un flot pour pouvoir enchaîner des écritures en cascade
// cout << unVers << 4 << unAutreVers << "fin" <<endl;
ostream& operator<< (ostream& flotSortie, const Vers& v) {
  v.affiche(flotSortie);
  return flotSortie;
}//<<

// on retourne un flot pour pouvoir enchaîner des lectures en cascade
// cin >> unVers >> i >> unAutreVers;
istream& operator>> (istream& flotEntree, Vers& v) {
  v.saisie(flotEntree);
  return flotEntree;
}//>>
