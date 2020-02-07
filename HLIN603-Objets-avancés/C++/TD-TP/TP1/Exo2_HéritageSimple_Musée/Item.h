#ifndef Item_h
#define Item_h

class Item {
private:
	string descriptif;
	int reference;

public:
	Item();
	Item(string d, int r);
	Item(const Item& i);
	virtual ~Item();

	virtual string getDescriptif();
	virtual int getReference();
	virtual void setDescriptif(string d);
	virtual void setReference(int r);

	virtual void saisie(istream& is);
	virtual void affiche(ostream& os) const;

	virtual Item& operator=(const Item& i);
};
ostream& operator<<(ostream& os, const Item& i);
istream& operator>>(istream& is, Item& i);

#endif