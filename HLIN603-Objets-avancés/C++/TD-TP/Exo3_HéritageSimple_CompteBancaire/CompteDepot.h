#ifndef CompteDepot_h
#define CompteDepot_h

class CompteDepot : public virtual CompteBancaire {
protected:

public:
	CompteDepot();
	CompteDepot(int s);
	virtual ~CompteDepot();

	virtual void deposer(int m);
};

#endif