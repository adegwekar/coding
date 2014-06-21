#include "ParagraphFormatting.hpp"

Paragraph::Paragraph(int MaxChars, int NumWords, int WordLengths[]):
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
		// based on previous line's last word's location + wordlength + space
		if (_paragraph[i - 1].CharacterNumber +
			_paragraph[i - 1].WordLength + 1
			+ WordLengths[i] > _maxchars) {
			// Not enough, just move this word to next line
			_paragraph[i].LineNumber = _paragraph[i - 1].LineNumber + 1;
			_paragraph[i].CharacterNumber = 0;
		} else {
			// Enough space, so place the word in the same line
			_paragraph[i].LineNumber = _paragraph[i - 1].LineNumber;
			_paragraph[i].CharacterNumber =
				_paragraph[i - 1].CharacterNumber +
				_paragraph[i - 1].WordLength + 1;
		}
		// wordlength will tell us how much space remains in the line
		_paragraph[i].WordLength = WordLengths[i];
	}
}

void Paragraph::ReplaceWord(int Word, int NewLength)
{
	//No change
	if (_paragraph[(Word - 1)].WordLength == NewLength)
		return ;

	_paragraph[(Word - 1)].WordLength = NewLength;

	// Word 1 (index 0) doesn't need to shift
	if (Word == 1) {
		++Word;
	}

	//Shift the rest of the words
	for (int i = Word - 1; i < _numwords; ++i) {
		//Check if this word can be inserted into or can remain
		// in previous line
		if (_paragraph[i - 1].CharacterNumber +
			_paragraph[i - 1].WordLength + 1 +
			_paragraph[i].WordLength <= _maxchars) {
			//This word can be inserted into previous line
			_paragraph[i].LineNumber = _paragraph[i - 1].LineNumber;
			_paragraph[i].CharacterNumber =
				_paragraph[i - 1].CharacterNumber +
				_paragraph[i - 1].WordLength + 1;
		} else {
			//This word no longer fits in the current line, bump it to next
			_paragraph[i].LineNumber = _paragraph[i - 1].LineNumber + 1;
			_paragraph[i].CharacterNumber = 0;
		}
	}
}