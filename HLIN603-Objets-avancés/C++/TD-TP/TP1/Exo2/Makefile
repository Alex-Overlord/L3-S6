GPP = g++
SRC = Item.cc main.cc
OBJ = $(SRC:%.cc=%.o)
EXE = main

all: $(OBJ)
	$(GPP) -o $(EXE) $(OBJ)

clean:
	rm -f *~ *.o $(EXE)

.SUFFIXES: .cc .o

%.o: %.cc
	$(GPP) -c $<