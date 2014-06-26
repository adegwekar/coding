CC=g++
CFLAGS=-g -Wall
LDFLAGS=
SOURCES=GasStationTestDrive.cpp GasStation.hpp GasStation.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=GasStationTestDrive

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) -c $< -o $@

clean: 
	$(RM) $(EXECUTABLE) *.o

