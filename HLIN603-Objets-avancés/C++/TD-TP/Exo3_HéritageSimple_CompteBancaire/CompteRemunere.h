#ifndef CompteRemunere_h
#define CompteRemunere_h

class CompteRemunere : public virtual CompteBancaire {
protected:
	// int bonus;

public:
	CompteRemunere();
	CompteRemunere(int s);
	CompteRemunere(int s, int b);
	virtual ~CompteRemunere();

	virtual void deposer(int m);
};

#endif