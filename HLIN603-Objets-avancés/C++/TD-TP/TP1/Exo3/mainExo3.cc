#include <iostream>
using namespace std;
#include "CompteBancaire.h"
#include "CompteRemunere.h"
#include "CompteDepot.h"
#include "CompteRemunereAvecCarteCredit.h"

#define N 3

int main() {
  // CompteBancaire* cb1 = new CompteBancaire(50);
  // cb1->deposer(100);
  // delete cb1;

  // CompteBancaire* cb2 = new CompteRemunere(50);
  // cb2->deposer(100);
  // delete cb2;

  // CompteBancaire* cb3 = new CompteDepot();
  // cb3->deposer(1000);
  // delete cb3;

	CompteBancaire* ComptesVP[N];

	for (int i = 0; i < N; i++) {
    cout << "\ni = " << i << endl;

		if (i%3 == 0) {
			ComptesVP[i] = new CompteRemunere();
    }
		else if (i%3 == 1) {
			ComptesVP[i] = new CompteDepot();
    }
    else {
      ComptesVP[i] = new CompteRemunereAvecCarteCredit();
    }

		ComptesVP[i]->deposer(250);
    delete ComptesVP[i]; 
	}
}
/* 
Etape pour CompteRemunereAvecCarteCredit :
1. Appel de deposer de la classe CompteRemunereAvecCarteCredit.
2. Appel du destructeur de la classe CompteRemunereAvecCarteCredit.
3. Appel du destructeur de la classe CompteRemunere.
*/