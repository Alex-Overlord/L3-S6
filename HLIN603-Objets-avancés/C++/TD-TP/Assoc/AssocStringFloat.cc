using namespace std;
#include <iostream>
#include <string>
#include "Assoc.cc"

template class Assoc<string, float>;
template ostream& operator<<(ostream&, const Assoc<string, float>&);