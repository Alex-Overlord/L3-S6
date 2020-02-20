#ifndef Oeuf_H
#define Oeuf_H

class Oeuf {
  private:
    Oeuf* cases[6];

  public:
    Oeuf();
    virtual ~Oeuf();

    virtual void range(Oeuf* oeuf, int index);
  
};

#endif