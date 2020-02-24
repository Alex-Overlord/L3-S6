#ifndef Casier6_h
#define Casier6_h

template<typename P>
class Casier6 {
  protected:
    P* cases[6];

  public:
    Casier6();
    virtual ~Casier6();
    virtual void range(P* produit, int index);
    virtual void affiche(ostream& os) const;
};
template<typename P>
ostream& operator<<(ostream& os, const Casier6<P>& c);

#endif