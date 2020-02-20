GPP = g++
SRC = Assoc.cc mainAssoc1.cc 
OBJ = $(SRC:%.cc=%.o)
EXE = exec

all: $(OBJ)
	$(GPP) -o $(EXE) $(OBJ)

clean:
	rm -f *~ *.o $(EXE)

.SUFFIXES: .cc .o

%.o: %.cc
	$(GPP) -c $<
