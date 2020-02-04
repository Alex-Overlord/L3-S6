#include <iostream>
#include <string>
using namespace std;
#include "Item.h"

int main() {
	Item* i1 = new Item("Poignée de porte luxueux", 1);
	delete i1;
}