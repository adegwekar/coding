CC=g++
CFLAGS=-g -Wall
LDFLAGS=
SOURCES=indexer.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=indexer

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) -c $< -o $@

clean: 
	$(RM) $(EXECUTABLE) *.o

