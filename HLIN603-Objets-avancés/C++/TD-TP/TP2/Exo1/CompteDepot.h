#ifndef CompteDepot_h
#define CompteDepot_h

class CompteDepot : public virtual CompteBancaire {
protected:

public:
	CompteDepot();
	CompteDepot(float s);
	virtual ~CompteDepot();

	virtual void deposer(float m);
};

#endif