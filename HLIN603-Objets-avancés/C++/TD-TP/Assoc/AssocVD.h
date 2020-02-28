#ifndef AssocVD_h
#define AssocVD_h

template<typename TypeCle, typename TypeValeur, const TypeCle vdc, const TypeValeur vdv>
class Assoc {
private:
  TypeCle cle;
  TypeValeur valeur;
public:
  Assoc();
  Assoc(TypeCle, TypeValeur);
  virtual ~Assoc();
  virtual TypeCle getCle() const;
  virtual void setCle(TypeCle);
  virtual TypeValeur getValeur() const;
  virtual void setValeur(TypeValeur);
  virtual void affiche(ostream&) const;   
};
template<typename Typecle, typename TypeValeur, const TypeCle vdc, const TypeValeur vdv>
ostream& operator<<(ostream&, const Assoc<TypeCle, TypeValeur, vdc, vdv>&);

#endif