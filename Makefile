CC = g++
CFLAGS  = -g -Wall

all: ParagraphFormattingTestDrive

ParagraphFormattingTestDrive: ParagraphFormattingTestDrive.o 
	$(CC) -o ParagraphFormattingTestDrive ParagraphFormattingTestDrive.o 

ParagraphFormattingTestDrive.o: ParagraphFormattingTestDrive.cpp
	$(CC) $(CFLAGS) ParagraphFormattingTestDrive.cpp

clean: 
	$(RM) ParagraphFormattingTestDrive *.o *~

