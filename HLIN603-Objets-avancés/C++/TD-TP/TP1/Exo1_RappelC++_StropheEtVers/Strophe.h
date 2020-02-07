#ifndef Strophe_h
#define Strophe_h

class Strophe {
  private:
    Vers** suiteVers;
    // attribut de type tableau de pointeurs vers des Vers
    // implémente l'agrégation "une strophe se compose de vers"
    int nbVers;
    // on pourrait faire des méthodes d'accès en lecture
    // mais surtout pas de modification

  public:
    Strophe();
    Strophe (const Strophe&); // constructeur par copie
    virtual ~Strophe();

    virtual void saisie(istream& is); // rempli la strophe de vers que l'on saisi
    virtual Vers* vers(int i) const; // retourne le vers d'indice i
    virtual void affiche(ostream& os) const; // affiche les vers de la strophe

    virtual Strophe& operator=(const Strophe& s);
    virtual Vers*& operator[](int i);
};
ostream& operator<< (ostream& os, const Strophe& s);
istream& operator>> (istream& is, Strophe& s);

#endif