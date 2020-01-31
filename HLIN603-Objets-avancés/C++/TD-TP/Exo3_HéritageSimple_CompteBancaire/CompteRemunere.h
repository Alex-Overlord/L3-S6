#ifndef CompteRemunere_h
#define CompteRemunere_h

class CompteRemunere : public virtual CompteBancaire {
public:
	virtual ~CompteRemunere();

	virtual void deposer(int montant);
}

#endif