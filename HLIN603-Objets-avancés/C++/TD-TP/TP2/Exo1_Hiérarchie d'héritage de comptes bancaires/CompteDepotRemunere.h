#ifndef CompteDepotRemunere_h
#define CompteDepotRemunere_h

class CompteDepotRemunere : public virtual CompteDepot, CompteRemunere {

public:
	CompteDepotRemunere();
	CompteDepotRemunere(float s);
	virtual ~CompteDepotRemunere();

	virtual void deposer(float m);
};

#endif