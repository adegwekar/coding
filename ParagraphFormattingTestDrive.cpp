#include <iostream>
#include "ParagraphFormatting.hpp"

using namespace std;

int main(int argc, char* argv[])
{
	int WordLengths1[] = {1, 2};

	Paragraph p(4, 2, WordLengths1);
	cout << "Test 1:" << endl
		<< "\tMaxchars: 4" << endl
		<< "\tNumWords: 2" << endl
		<< "\tWordLengths: 1, 2" << endl;
	cout << endl;
	cout << "Word 1, Line 1: ";
	(p.PrintLineNumber(1) == 1) ? cout << "Pass" : cout << "Fail";
	cout << endl;
	cout << "Word 2, Line 1: ";
	(p.PrintLineNumber(2) == 1) ? cout << "Pass" : cout << "Fail";
	cout << endl;
	cout << "Replace word 2, new length: 3" << endl;
	p.ReplaceWord(2, 3);
	cout << "Word 2, Line 2: ";
	(p.PrintLineNumber(2) == 2) ? cout << "Pass" : cout << "Fail";
	cout << endl;
	cout << "Replace word 2, new length: 1" << endl;
	p.ReplaceWord(2, 1);
	cout << "Word 2, Line 1: ";
	(p.PrintLineNumber(2) == 1) ? cout << "Pass" : cout << "Fail";
	cout << endl;
	cout << "Replace word 1, new length: 3" << endl;
	p.ReplaceWord(1, 3);
	cout << "Word 1, Line 1: ";
	(p.PrintLineNumber(1) == 1) ? cout << "Pass" : cout << "Fail";
	cout << endl;
	cout << "Word 2, Line 2: ";
	(p.PrintLineNumber(2) == 2) ? cout << "Pass" : cout << "Fail";
	cout << endl;
	cout << "Replace word 1, new length: 2" << endl;
	p.ReplaceWord(1, 2);
	cout << "Word 1, Line 1: ";
	(p.PrintLineNumber(1) == 1) ? cout << "Pass" : cout << "Fail";
	cout << endl;
	cout << "Word 2, Line 1: ";
	(p.PrintLineNumber(2) == 1) ? cout << "Pass" : cout << "Fail";
	cout << endl;
	cout << "Replace word 1, new length: 1" << endl;
	p.ReplaceWord(1, 1);
	cout << "Word 1, Line 1: ";
	(p.PrintLineNumber(1) == 1) ? cout << "Pass" : cout << "Fail";
	cout << endl;
	cout << "Word 2, Line 1: ";
	(p.PrintLineNumber(2) == 1) ? cout << "Pass" : cout << "Fail";
	cout << endl;

	return 0;
}
