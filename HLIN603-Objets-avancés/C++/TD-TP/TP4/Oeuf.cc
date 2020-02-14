class Oeuf {
  private:
    Oeuf* cases[6];

  public:
    Oeuf();
    virtual ~Oeuf();

    virtual void range(Oeuf* oeuf, int index);
  
};