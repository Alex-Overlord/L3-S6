// $Id$

class Strophe {
private:
  Vers ** suiteVers;
  int nbVers;
public:
  Strophe ();
  Strophe (const Strophe&);
  virtual ~Strophe ();
  virtual void saisie (istream& is);
  virtual const Vers* vers (int i) const;
  virtual void affiche (ostream& os) const;
  virtual Strophe& operator= (const Strophe&);

// l'opérateur [] ne peut être implémenté que comme une méthode
// exemple d'appel : uneStrophe[2]
// en appel préfixe : uneStrophe.operator[](2)
// si ce doit être en partie gauche d'une affectation, on retourne
// une référence
  virtual Vers*& operator[] (int);
};//Strophe

ostream& operator<< (ostream& flotSortie, const Strophe& s);
istream& operator>> (istream& flotEntree, Strophe& s);
