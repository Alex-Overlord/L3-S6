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

	virtual Item& operator=(const Item& i);
};
ostream& operator<<(ostream& os, const Item& i);
// istream& operator>>(istream& is, const Item& i);

#endif