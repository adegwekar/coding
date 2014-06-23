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
	cout << p;
	cout << endl;
	cout << "Word 1, Line 1: ";
	(p.PrintLineNumber(1) == 1) ? cout << "Pass" : cout << "Fail";
	cout << endl;
	cout << p;
	cout << endl;
	cout << "Word 2, Line 1: ";
	(p.PrintLineNumber(2) == 1) ? cout << "Pass" : cout << "Fail";
	cout << endl;
	cout << endl;
	cout << "Replace word 2, new length: 3" << endl;
	p.ReplaceWord(2, 3);
	cout << p;
	cout << endl;
	cout << "Word 2, Line 2: ";
	(p.PrintLineNumber(2) == 2) ? cout << "Pass" : cout << "Fail";
	cout << endl;
	cout << endl;
	cout << "Replace word 2, new length: 1" << endl;
	p.ReplaceWord(2, 1);
	cout << p;
	cout << endl;
	cout << "Word 2, Line 1: ";
	(p.PrintLineNumber(2) == 1) ? cout << "Pass" : cout << "Fail";
	cout << endl;
	cout << endl;
	cout << "Replace word 1, new length: 3" << endl;
	p.ReplaceWord(1, 3);
	cout << p;
	cout << endl;
	cout << "Word 1, Line 1: ";
	(p.PrintLineNumber(1) == 1) ? cout << "Pass" : cout << "Fail";
	cout << endl;
	cout << p;
	cout << endl;
	cout << "Word 2, Line 2: ";
	(p.PrintLineNumber(2) == 2) ? cout << "Pass" : cout << "Fail";
	cout << endl;
	cout << endl;
	cout << "Replace word 1, new length: 2" << endl;
	p.ReplaceWord(1, 2);
	cout << p;
	cout << endl;
	cout << "Word 1, Line 1: ";
	(p.PrintLineNumber(1) == 1) ? cout << "Pass" : cout << "Fail";
	cout << endl;
	cout << p;
	cout << endl;
	cout << "Word 2, Line 1: ";
	(p.PrintLineNumber(2) == 1) ? cout << "Pass" : cout << "Fail";
	cout << endl;
	cout << endl;
	cout << "Replace word 1, new length: 1" << endl;
	p.ReplaceWord(1, 1);
	cout << p;
	cout << endl;
	cout << "Word 1, Line 1: ";
	(p.PrintLineNumber(1) == 1) ? cout << "Pass" : cout << "Fail";
	cout << endl;
	cout << p;
	cout << endl;
	cout << "Word 2, Line 1: ";
	(p.PrintLineNumber(2) == 1) ? cout << "Pass" : cout << "Fail";
	cout << endl;
	cout << endl;
	cout << "Replace word 2, new length: 2" << endl;
	p.ReplaceWord(2, 2);
	cout << p;
	cout << endl;
	cout << "Word 1, Line 1: ";
	(p.PrintLineNumber(1) == 1) ? cout << "Pass" : cout << "Fail";
	cout << endl;
	cout << p;
	cout << endl;
	cout << "Word 2, Line 1: ";
	(p.PrintLineNumber(2) == 1) ? cout << "Pass" : cout << "Fail";
	cout << endl;
	cout << endl;
	cout << "Replace word 2, new length: 3" << endl;
	p.ReplaceWord(2, 3);
	cout << p;
	cout << endl;
	cout << "Word 1, Line 1: ";
	(p.PrintLineNumber(1) == 1) ? cout << "Pass" : cout << "Fail";
	cout << endl;
	cout << p;
	cout << endl;
	cout << "Word 2, Line 2: ";
	(p.PrintLineNumber(2) == 2) ? cout << "Pass" : cout << "Fail";
	cout << endl;


	int WordLengths2[] = {1, 5, 4, 5, 6};

	Paragraph p1(6, 5, WordLengths2);
	cout << "Test 2:" << endl
		<< "\tMaxchars: 6" << endl
		<< "\tNumWords: 5" << endl
		<< "\tWordLengths: 1, 5, 4, 5, 6" << endl;
	cout << p1;
	cout << endl;
	cout << "Word 1, Line 1: ";
	(p1.PrintLineNumber(1) == 1) ? cout << "Pass" : cout << "Fail";
	cout << endl;
	cout << p1;
	cout << endl;
	cout << "Word 2, Line 2: ";
	(p1.PrintLineNumber(2) == 2) ? cout << "Pass" : cout << "Fail";
	cout << endl;
	cout << p1;
	cout << endl;
	cout << "Word 4, Line 4: ";
	(p1.PrintLineNumber(4) == 4) ? cout << "Pass" : cout << "Fail";
	cout << endl;
	cout << p1;
	cout << endl;
	cout << "Word 5, Line 5: ";
	(p1.PrintLineNumber(5) == 5) ? cout << "Pass" : cout << "Fail";
	cout << endl;
	cout << endl;
	cout << "Replace word 4, new length: 1" << endl;
	p1.ReplaceWord(4, 1);
	cout << p1;
	cout << endl;
	cout << "Word 4, Line 3: ";
	(p1.PrintLineNumber(4) == 3) ? cout << "Pass" : cout << "Fail";
	cout << endl;
	cout << p1;
	cout << endl;
	cout << "Word 5, Line 4: ";
	(p1.PrintLineNumber(5) == 4) ? cout << "Pass" : cout << "Fail";
	cout << endl;
	cout << endl;
	cout << "Replace word 2, new length: 1" << endl;
	p1.ReplaceWord(2, 1);
	cout << endl;
	cout << p1;
	cout << "Replace word 3, new length: 2" << endl;
	p1.ReplaceWord(3, 2);
	cout << endl;
	cout << p1;
	cout << "Replace word 5, new length: 4" << endl;
	p1.ReplaceWord(5, 4);
	cout << p1;
	cout << endl;
	cout << "Word 5, Line 2: ";
	(p1.PrintLineNumber(5) == 2) ? cout << "Pass" : cout << "Fail";
	cout << endl;
	cout << p1;
	cout << endl;
	cout << "Word 3, Line 1: ";
	(p1.PrintLineNumber(3) == 1) ? cout << "Pass" : cout << "Fail";
	cout << endl;

	return 0;
}
