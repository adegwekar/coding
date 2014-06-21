#include <iostream>
#include "ParagraphFormatting.hpp"

using namespace std;

int main(int argc, char* argv[])
{
	int WordLengths1[] = {1, 2};

	Paragraph p(4, 2, WordLengths1);
	(p.PrintLineNumber(1) == 1) ? cout << "Pass" : cout << "Fail";
	cout << endl;
	(p.PrintLineNumber(2) == 1) ? cout << "Pass" : cout << "Fail";
	cout << endl;
	p.ReplaceWord(2, 3);
	(p.PrintLineNumber(2) == 2) ? cout << "Pass" : cout << "Fail";
	cout << endl;

	return 0;
}
