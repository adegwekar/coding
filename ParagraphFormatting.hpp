#include <string>

struct WordPosition {
	int LineNumber;
	int CharacterNumber;
	int WordLength;
};

class Paragraph
{
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