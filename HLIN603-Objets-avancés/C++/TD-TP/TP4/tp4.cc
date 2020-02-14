#include <string>
#include <iostream>
using namespace std;

template<typename E> 
void echange(E& e1, E& e2) {
	E aux = e1; 
	e1 = e2; 
	e2 = aux;
}

template<typename E> 
void triBulles(E T[], int tailleT) {
	int i = tailleT-2, j; 
	bool ech = true;

	while (i >= 0 && ech) {
		ech = false;
	
		for (j = 0; j <= i; j++) {

			if (T[j] > T[j+1]) {
				echange(T[j], T[j+1]); 
				ech = true;
			}
		}
		i--;
	}
}

int main() {
	string tab1[5] = {"aaa", "eee", "fff", "bbb", "ccc"};

	triBulles<string>(tab1, 5);
	for (int i = 0; i < 5; i++) {
		cout << tab1[i] << " ";
	}

	int tab2[5] = {9, 8, 7, 6, 6};
	triBulles<int>(tab2, 5);

	for (int i = 0; i < 5; i++) {
		cout << tab2[i] << " ";
	}
	cout << endl;
}

// si B hérite de A, vector<B> n'est pas sous-type de vector<A>