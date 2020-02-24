#include "Casier6.h"
#include <cstddef>

template<typename P>
Casier6<P>::Casier6() {
  for (int i; i<6; i++) {
    cases[i] = nullptr;
  }
}

template<typename P>
Casier6<P>::~Casier6() {}

template<typename P>
void Casier6<P>::range(P* produit, int index) {
  cases[index] = produit;
}

template<typename P>
void Casier6<P>::affiche(ostream& os) const {
  for(int i=0; i<6; i++){
    os << cases[i]; 
  } 
} 

template<typename P>
ostream& operator<<(ostream& os, const Casier6<P>& c) {
  c.affiche(os);
  return os;
} 