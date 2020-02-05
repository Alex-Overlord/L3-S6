#include <iostream>
#include <string>
using namespace std;
#include "Item.h"

int main() {
	Item* i1 = new Item("PoignéeDePorteLuxueux", 1);
	Item* i2 = new Item(*i1);

	cout << *i1 << endl;
	cout << *i2 << endl;
	
	cin >> *i2;

	cout << *i1 << endl;
	cout << *i2 << endl;

	delete i1;
}