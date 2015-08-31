OBJ=program_options.o main.o
CC=g++
CCFLAGS=-Wall -std=c++11
OBJFLAGS=-c
EXE=app

$(VERBOSE).SILENT:

all: $(EXE)
	rm -f *.o

program_options.o: program_options.cpp
	$(CC) $(OBJFLAGS) $(CCFLAGS) program_options.cpp

main.o: main.cpp
	$(CC) $(OBJFLAGS) $(CCFLAGS) main.cpp

$(EXE): $(OBJ)
	$(CC) $(CCFLAGS) $(OBJ) -o $(EXE)

clean:
	rm -f *.o $(EXE)
