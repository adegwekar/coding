#ifndef __PARGRAPHFORMATTING_HPP__
#define __PARGRAPHFORMATTING_HPP__

#include <string>
#include <iostream>

struct WordPosition {
	int LineNumber;
	int CharacterNumber;
	int WordLength;
};

class Paragraph
{
friend std::ostream& operator<<(std::ostream &os, const Paragraph &p)
{
	//for (int i = 0; i < p._numwords; ++i)
	{
		//if (i == p._paragraph[i].LineNumber)
		//	os << std::endl;

		//for (int j = 0; j < p._paragraph[i].WordLength; ++j) {
		//	os << i + 1;
		//}

		os << "0";
	}
}

public:
	Paragraph(int MaxChars, int NumWords, int WordLengths[]);

	int PrintLineNumber(int Word)
	{
		return _paragraph[Word - 1].LineNumber+1;
	}

	void ReplaceWord(int Word, int NewLength);

	~Paragraph()
	{
		delete [] _paragraph;
	}

private:
	int _maxchars;
	int _numwords;
	WordPosition *_paragraph;

	Paragraph(const Paragraph&) {};
	Paragraph& operator=(const Paragraph &) {};
};

#endif //__PARGRAPHFORMATTING_HPP__