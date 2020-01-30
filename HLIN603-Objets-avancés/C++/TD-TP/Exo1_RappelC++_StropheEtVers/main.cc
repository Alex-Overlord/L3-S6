#include <iostream>
#include <string>
using namespace std;
#include "Vers.h"
#include "Strophe.h"

int main() {
  Vers* v1 = new Vers();
  
  cout << "Saisi d'un vers\n";
  cin >> *v1; // les espaces posent problèmes
  cout << (*v1).getSuiteMots() << endl << (*v1).getRime() << endl;
  cout << *v1 << endl;
}