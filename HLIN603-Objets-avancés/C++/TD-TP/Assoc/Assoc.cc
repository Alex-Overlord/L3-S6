using namespace std;
#include <iostream>
#include "Assoc.h"

template<typename TypeCle, typename TypeValeur>
Assoc<TypeCle, TypeValeur>::Assoc() {} 

template<typename TypeCle, typename TypeValeur>
Assoc<TypeCle, TypeValeur>::Assoc(TypeCle c, TypeValeur v) : cle(c), valeur(v) {} 

template<typename TypeCle, typename TypeValeur>
Assoc<TypeCle, TypeValeur>::~Assoc() {}  

template<typename TypeCle, typename TypeValeur>
TypeCle Assoc<TypeCle, TypeValeur>::getCle() const { return cle; } 

template<typename TypeCle, typename TypeValeur>
void Assoc<TypeCle, TypeValeur>::setCle(TypeCle c) { cle = c; } 

template<typename TypeCle, typename TypeValeur>
TypeValeur Assoc<TypeCle, TypeValeur>::getValeur() const { return valeur; } 

template<typename TypeCle, typename TypeValeur>
void Assoc<TypeCle, TypeValeur>::setValeur(TypeValeur v) { valeur = v; } 

template<typename TypeCle, typename TypeValeur>
void Assoc<TypeCle, TypeValeur>::affiche(ostream& os) const {
  os << getCle() << ", " << getValeur();
} 

template<typename TypeCle, typename TypeValeur>
ostream& operator<<(ostream& os, const Assoc<TypeCle, TypeValeur>& a) {
  a.affiche(os);
  return os;
} 