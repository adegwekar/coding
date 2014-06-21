#include <iostream>
#include "ParagraphFormatting.hpp"

using namespace std;

int main(int argc, char* argv[])
{
	int Test1[] = {1, 2};

	CreateParagraph(4, 2, Test1);
	(PrintLineNumber(2) == 1) ? cout << "Pass" : cout << "Fail";
	cout << endl;
	ReplaceWord(2, 3);
	(PrintLineNumber(2) == 2) ? cout << "Pass" : cout << "Fail";
	cout << endl;

	return 0;
}

