using namespace std;
#include <iostream>
#include <string>
#include "Assoc.h"

int main() {
  Assoc<char, int*> a;
  Assoc<string, string>* pass = new Assoc<string, string>("citron","jaune");
  cout << *pass;
}