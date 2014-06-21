CC=g++
CFLAGS=-g -Wall
LDFLAGS=
SOURCES=ParagraphFormattingTestDrive.cpp
LIBSOURCES=ParagraphFormatting.hpp
OBJECTS=$(SOURCES:.cpp=.o)
LIBOBJECTS=$(LIBSOURCES:.cpp=.o)
EXECUTABLE=ParagraphFormattingTestDrive
LIBRARY=ParagraphFormatting.a

all: $(SOURCES) $(EXECUTABLE) $(LIBRARY)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

$(LIBRARY): $(LIBSOURCES)
	ar rc $@ $(LIBOBJECTS)
	ranlib $@

.cpp.o:
	$(CC) $(CFLAGS) -c $< -o $@

clean: 
	$(RM) $(EXECUTABLE) $(LIBRARY) *.o

