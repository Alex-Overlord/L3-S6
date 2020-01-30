#include <iostream>
#include <string>
using namespace std;
#include "Vers.h"
#include "Strophe.h"

int main() {
  Vers* v1 = new Vers();
  (*v1).saisie(cin);
  (*v1).affiche(cout);
}