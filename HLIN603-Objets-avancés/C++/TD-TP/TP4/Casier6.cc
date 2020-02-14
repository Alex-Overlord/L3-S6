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