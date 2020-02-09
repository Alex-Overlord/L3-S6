#ifndef CompteBancaire_h
#define CompteBancaire_h

class CompteBancaire {
protected:
	float solde;

public:
	CompteBancaire();
	CompteBancaire(float solde);
	virtual ~CompteBancaire();

	virtual void deposer(float montant);
};

#endif