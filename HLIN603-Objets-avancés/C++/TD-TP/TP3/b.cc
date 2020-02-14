class C1 {

private:
	virtual void f() {}

protected: 
	friend class A;
	friend class B;

public:
	virtual void mc1();
};

class C2 : public virtual C1 {

public:
	virtual void mc2();
};

void C1::mc1() {
	C1 *c1; 
	c1->f(); 

	C2 *c2; 
	c2->f(); // fonctionne car c2 utilisable partout dans la hiérarchie et dans C1
}

void C2::mc2() {
	C1 *c1; 
	// c1->f(); // C1 permet à C2 d'utiliser f pour une instance de C2 mais pas de C1

	C2 *c2; 
	// c2->f(); // Ne compile pas car f private
}

class A {

public:
	virtual void ma() {
		C1 *c1; 
		c1->f(); // A étant friend peut utiliser f pour une instance de C1

		C2 *c2; 
		c2->f();
	}
};

class B : public virtual A {

public:
	virtual void mb() {
		C1 *c1; 
		c1->f(); // marche car C1 friend class B

		C2 *c2; 
		c2->f();
	}
};

class D {
public:
	virtual void md() {
		C1 *c1; 
		// c1->f(); 

		C2 *c2; 
		// c2->f();
	}
};