GPP = g++
SRC = mainExo3.cc CompteBancaire.cc CompteRemunere.cc CompteDepot.cc CompteRemunereAvecCarteCredit.cc CompteDepotRemunere.cc
OBJ = $(SRC:%.cc=%.o)
EXE = main

all: $(OBJ)
	$(GPP) -o $(EXE) $(OBJ)

clean:
	rm -f *~ *.o $(EXE)

.SUFFIXES: .cc .o

%.o: %.cc
	$(GPP) -c $<