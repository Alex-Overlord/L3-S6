#ifndef Vers_h
#define Vers_h

class Vers {
  private:
		string suiteMots;
		string rime;
		
	public:
		Vers();
		explicit Vers(string s);
		Vers(string s, string r);
		virtual ~Vers();
		virtual string getSuiteMots() const;
		virtual void setSuiteMots(string sm);
		virtual string getRime() const;
		virtual void setRime(string r);
		virtual void saisie(istream& is); // saisi le vers
		virtual void affiche(ostream& os) const; // affiche le vers
};
// ostream& operator<< (ostream&, const Vers&);
// istream& operator>> (istream&, Vers&);

#endif