#ifndef Assoc_h
#define Assoc_h

template<typename TypeCle, typename TypeValeur>
class Assoc {
  private:
    TypeCle cle;
    TypeValeur valeur;
  public:
    Assoc();
    Assoc(TypeCle c, TypeValeur v);
    virtual ~Assoc();
    virtual TypeCle getCle() const;
    virtual void setCle(TypeCle c);
    virtual TypeValeur getValeur() const;
    virtual void setValeur(TypeValeur v);
    virtual void affiche(ostream& os) const;
};

template<typename TypeCle, typename TypeValeur>
ostream& operator<<(ostream& os, const Assoc<TypeCle, TypeValeur>& a);

#endif