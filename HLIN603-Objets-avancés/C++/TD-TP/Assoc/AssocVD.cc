#include "Assoc.h"

template<typename TypeCle, typename TypeValeur, const TypeCle vdc, const TypeValeur vdv>
Assoc<TypeCle, TypeValeur, vdc, vdv>::Assoc() { 
  cle = vdc; 
  valeur = vdv;
} 