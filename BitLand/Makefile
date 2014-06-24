CC=g++
CFLAGS=-g -Wall
LDFLAGS=
SOURCES=BitLandTestDrive.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=BitLandTestDrive

all: $(SOURCES) $(EXECUTABLE) $(LIBRARY)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) -c $< -o $@

clean: 
	$(RM) $(EXECUTABLE) *.o

