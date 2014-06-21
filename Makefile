CC=g++
CFLAGS=-g -Wall
LDFLAGS=
SOURCES=ParagraphFormattingTestDrive.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=ParagraphFormattingTestDrive

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) -c $< -o $@

clean: 
	$(RM) $(EXECUTABLE) *.o

