#include <string>

struct WordPosition {
	int LineNumber;
	int CharacterNumber;
};

class Paragraph
{
public:
	Paragraph(int MaxChars, int NumWords, int WordLengths[]):
		_maxchars(MaxChars),
		_numwords(NumWords),
		_wordlengths(0),
		_paragraph(0)
	{
		_wordlengths = new int[_numwords];
		_paragraph = new WordPosition[_numwords];
	}

	int PrintLineNumber(int Word)
	{
		return 1;
	}

	void ReplaceWord(int Word, int NewLength)
	{
		return;
	}

	~Paragraph()
	{
		delete [] _wordlengths;
		delete [] _paragraph;
	}

private:
	int _maxchars;
	int _numwords;
	int *_wordlengths;
	WordPosition *_paragraph;

	Paragraph(const Paragraph&) {};
	Paragraph& operator=(const Paragraph &) {return 0;};
};