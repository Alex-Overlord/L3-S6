#ifndef CompteRemunereAvecCarteCredit_h
#define CompteRemunereAvecCarteCredit_h

class CompteRemunereAvecCarteCredit : public virtual CompteRemunere {
	
public:
	CompteRemunereAvecCarteCredit();
	CompteRemunereAvecCarteCredit(float s);
	virtual ~CompteRemunereAvecCarteCredit();

	virtual void deposer(float m);
};

#endif