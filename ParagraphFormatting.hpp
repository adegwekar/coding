#include <string>

struct WordPosition {
	int LineNumber;
	int CharacterNumber;
	int WordLength;
};

class Paragraph
{
public:
	Paragraph(int MaxChars, int NumWords, int WordLengths[]):
		_maxchars(MaxChars),
		_numwords(NumWords),
		_paragraph(0)
	{
		_paragraph = new WordPosition[_numwords];

		// First word always goes to line 0, character 0
		_paragraph[0].LineNumber = 0;
		_paragraph[0].CharacterNumber = 0;
		_paragraph[0].WordLength = WordLengths[0];

		for (int i = 1; i < _numwords; ++i) {
			// Check if previous line has enough space for this word
			if (_paragraph[i - 1].CharacterNumber +
				_paragraph[i - 1].WordLength + 1
				+ WordLengths[i] > _maxchars) {
				_paragraph[i].LineNumber = _paragraph[i - 1].LineNumber+1;
				_paragraph[i].CharacterNumber = 0;
			} else {
				_paragraph[i].LineNumber = _paragraph[i - 1].LineNumber;
				_paragraph[i].CharacterNumber =
					_paragraph[i - 1].CharacterNumber +
					_paragraph[i - 1].WordLength + 1;
			}
			_paragraph[i].WordLength = WordLengths[i];
		}
	}

	int PrintLineNumber(int Word)
	{
		return _paragraph[Word - 1].LineNumber+1;
	}

	void ReplaceWord(int Word, int NewLength)
	{
		return;
	}

	~Paragraph()
	{
		delete [] _paragraph;
	}

private:
	int _maxchars;
	int _numwords;
	WordPosition *_paragraph;

	Paragraph(const Paragraph&) {};
	Paragraph& operator=(const Paragraph &) {/*return 0;*/};
};