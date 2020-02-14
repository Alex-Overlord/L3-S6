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
};

#endif