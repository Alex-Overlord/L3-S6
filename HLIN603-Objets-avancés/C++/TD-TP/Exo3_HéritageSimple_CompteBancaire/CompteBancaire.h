#ifndef CompteBancaire_h
#define CompteBancaire_h

class CompteBancaire {
protected:
	int solde;
public:
	CompteBancaire();
	CompteBancaire(int s);
	virtual ~CompteBancaire();

	virtual void deposer(int montant);
}

#endif