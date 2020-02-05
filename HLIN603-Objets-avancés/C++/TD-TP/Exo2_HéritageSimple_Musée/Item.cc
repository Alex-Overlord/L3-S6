#include <iostream>
#include <string>
using namespace std;
#include "Item.h"

Item::Item() {}
Item::Item(string d, int r) {
	descriptif = d;
	reference = r;
}
Item::Item(const Item& i) {
	descriptif = i.descriptif;
	reference = i.reference;
}
Item::~Item() {}

string Item::getDescriptif() { return descriptif; }
int Item::getReference() { return reference; }
void Item::setDescriptif(string d) { descriptif = d; }
void Item::setReference(int r) { reference = r; }

void Item::saisie(istream& is) {
	cout << "Descriptif puis reference\n";
	is >> descriptif >> reference;
}
void Item::affiche(ostream& os) const {
	os << descriptif << " " << reference;
}

Item& Item::operator=(const Item& i) {
	if (this != &i) {
		descriptif = i.descriptif;
		reference = i.reference;
		return *this;
	}
}

ostream& operator<<(ostream& os, const Item& i) {
	i.affiche(os);
	return os;
}
istream& operator>>(istream& is, Item& i) {
	i.saisie(is);
	return is;
}