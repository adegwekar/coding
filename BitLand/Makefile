CC=g++
CFLAGS=-g -Wall
LDFLAGS=
SOURCES=BitLandTestDrive.cpp BitLand.hpp BitLand.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=BitLandTestDrive

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) -c $< -o $@

clean: 
	$(RM) $(EXECUTABLE) *.o

