#include <iostream>
#include "ParagraphFormatting.hpp"

using namespace std;

int main(int argc, char* argv[])
{
	int Test1[] = {1, 2};

	Paragraph p(4, 2, Test1);
	(p.PrintLineNumber(2) == 1) ? cout << "Pass" : cout << "Fail";
	cout << endl;
	p.ReplaceWord(2, 3);
	(p.PrintLineNumber(2) == 2) ? cout << "Pass" : cout << "Fail";
	cout << endl;

	return 0;
}

