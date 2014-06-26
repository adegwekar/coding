CC=g++
CFLAGS=-g -Wall
LDFLAGS=
SOURCES=GasStationTestDrive.cpp
LIBSOURCES=GasStation.cpp GasStation.hpp
OBJECTS=$(SOURCES:.cpp=.o)
LIBOBJECTS=$(LIBSOURCES:.cpp=.o)
EXECUTABLE=GasStationTestDrive
LIBRARYNAME=GasStation
LIBRARY=lib$(LIBRARYNAME).a

all: $(SOURCES) $(EXECUTABLE) $(LIBRARY)

$(EXECUTABLE): $(OBJECTS) $(LIBRARY)
	$(CC) $(LDFLAGS) $(OBJECTS) -L . -l$(LIBRARYNAME) -o $@

$(LIBRARY): $(LIBOBJECTS)
	ar rc $@ $(LIBOBJECTS)
	ranlib $@

.cpp.o:
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: clean

clean: 
	$(RM) $(EXECUTABLE) $(LIBRARY) *.o

