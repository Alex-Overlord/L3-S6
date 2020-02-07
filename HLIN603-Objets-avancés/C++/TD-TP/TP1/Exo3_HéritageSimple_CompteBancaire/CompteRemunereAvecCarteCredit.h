#ifndef CompteRemunereAvecCarteCredit_h
#define CompteRemunereAvecCarteCredit_h

class CompteRemunereAvecCarteCredit : public virtual CompteRemunere {
protected:

public:
	CompteRemunereAvecCarteCredit();
	CompteRemunereAvecCarteCredit(int s);
	virtual ~CompteRemunereAvecCarteCredit();

	virtual void deposer(int m);
};

#endif