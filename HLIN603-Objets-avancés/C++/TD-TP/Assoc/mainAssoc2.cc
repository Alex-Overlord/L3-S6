using namespace std;
#include <iostream>
#include <string>
#include "Assoc.cc"

int main() {
  Assoc<char,float> a;
  Assoc<string,float>* pass = new Assoc<string,float>("citron",12);
  cout << *pass << endl;
}