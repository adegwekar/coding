CC=g++
CFLAGS=-g -Wall
LDFLAGS=
SOURCES=ParagraphFormattingTestDrive.cpp ParagraphFormatting.cpp
#LIBSOURCES=ParagraphFormatting.hpp
OBJECTS=$(SOURCES:.cpp=.o)
#LIBOBJECTS=$(LIBSOURCES:.cpp=.o)
EXECUTABLE=ParagraphFormattingTestDrive
#LIBRARYNAME=ParagraphFormatting
#LIBRARY=$(LIBRARYNAME).a
LIBRARY=

all: $(SOURCES) $(EXECUTABLE) $(LIBRARY)

$(EXECUTABLE): $(OBJECTS) $(LIBRARY)
	$(CC) $(LDFLAGS) $(OBJECTS) $(LIBRARY) -o $@

#$(LIBRARY): $(LIBSOURCES)
#	ar rc $@ $(LIBOBJECTS)
#	ranlib $@

.cpp.o:
	$(CC) $(CFLAGS) -c $< -o $@

clean: 
	$(RM) $(EXECUTABLE) $(LIBRARY) *.o

