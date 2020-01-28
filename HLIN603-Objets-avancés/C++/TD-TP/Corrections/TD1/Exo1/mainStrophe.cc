// $Id$

#include<iostream>
#include<string>
using namespace std;
#include"Vers.h"
#include"Strophe.h"

int main() {
   Strophe *s = new Strophe();
   cout << "Saisie d'une strophe" <<endl;
   cin >> *s;
   cout << *s;
}//main
