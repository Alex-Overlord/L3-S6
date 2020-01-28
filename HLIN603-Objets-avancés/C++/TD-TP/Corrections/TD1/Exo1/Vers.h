// $Id$

class Vers {
private:
  string suiteMots;
  string rime;
public:
  Vers ();
  Vers (string s);
  Vers (string s, string r);
  virtual ~Vers ();
  virtual string getSuiteMots () const;
  virtual void setSuiteMots (string sm);
  virtual string getRime () const;
  virtual void setRime (string r);
  virtual void saisie (istream& is);
  virtual void affiche (ostream& os) const;
};//Vers

// signature : l'opérande gauche est un ostream et on ne peut pas changer la
// classe ostream
// donc l'opérateur est implémenté comme une fonction.
// appel préfixe :  operator<<(cout, unVers)
// unVers n'est pas modifié, il est passé par référence constante pour éviter
// une copie
ostream& operator<< (ostream&, const Vers&);

// signature : l'opérande gauche est un istream, et on ne peut pas changer la
// classe istream
// donc l'opérateur est implémenté comme une fonction.
// appel préfixe :  operator>>(cin, unVers)
// unVers est modifié, il est passé par référence

istream& operator>> (istream&, Vers&);
