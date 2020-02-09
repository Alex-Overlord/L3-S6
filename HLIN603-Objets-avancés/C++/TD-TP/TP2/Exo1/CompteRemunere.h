#ifndef CompteRemunere_h
#define CompteRemunere_h

class CompteRemunere : public virtual CompteBancaire {

public:
	CompteRemunere();
	CompteRemunere(float s);
	virtual ~CompteRemunere();

	virtual void deposer(float m);
};

#endif