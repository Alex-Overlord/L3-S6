GPP = g++
SRC = mainExo3.cc CompteBancaire.cc CompteRemunere.cc CompteDepot.cc CompteDepotRemunere.cc CompteRemunereAvecCarteCredit.cc CompteDepotAvecCarteCredit.cc
OBJ = $(SRC:%.cc=%.o)
EXE = exec

all: $(OBJ)
	$(GPP) -o $(EXE) $(OBJ)

clean:
	rm -f *~ *.o $(EXE)

.SUFFIXES: .cc .o

%.o: %.cc
	$(GPP) -c $<