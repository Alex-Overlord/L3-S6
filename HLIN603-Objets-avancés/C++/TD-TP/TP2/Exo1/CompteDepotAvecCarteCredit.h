#ifndef CompteDepotAvecCarteCredit_h
#define CompteDepotAvecCarteCredit_h

class CompteDepotAvecCarteCredit : public virtual CompteDepot {

public:
	CompteDepotAvecCarteCredit();
	CompteDepotAvecCarteCredit(float s);
	virtual ~CompteDepotAvecCarteCredit();

	virtual void deposer(float m);
};

#endif