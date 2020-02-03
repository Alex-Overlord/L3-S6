#include <iostream>
using namespace std;
#include "CompteBancaire.h"
#include "CompteDepot.h"
#include "CompteRemunere.h"

int main() {
  CompteBancaire* cb = new CompteBancaire();
  cb->deposer(100);
  cb->~CompteBancaire();
}