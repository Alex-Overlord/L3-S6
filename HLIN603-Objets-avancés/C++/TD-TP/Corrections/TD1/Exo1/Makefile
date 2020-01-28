# $Id: 8fa85b35fe5410ba77d3c0e88c78f1db2b4e0e98 $

GPP=g++
SRC=Vers.cc Strophe.cc mainStrophe.cc
OBJ=$(SRC:%.cc=%.o)
EXE=mainStrophe

all: $(OBJ)
	$(GPP) -o $(EXE) $(OBJ)

clean:
	rm -f *~ *.o $(EXE)

.SUFFIXES: .cc .o

%.o: %.cc
	$(GPP) -c $<
