#include <iostream>
#include <fstream>
#include <string>
#include <ctype.h>

class IndexBST;

class IndexNode {
	friend class IndexBST;

public:
	IndexNode():indexword(0),filename(0),linenumber(0),left(0),right(0) {}
	IndexNode(const std::string &s, const std::string f,
				const int l):indexword(s),filename(f),linenumber(l),left(0),right(0) {}

private:
	std::string indexword;
	std::string filename;
	int linenumber;
	IndexNode *left;
	IndexNode *right;
};

class IndexBST
{
public:
	IndexBST():root(0) {}
	~IndexBST()
	{
	}

	void AddIndex(const std::string &word,
					const std::string &filename,
					int linenumber);

	void Print() {PrintTree(root, 0, "", "");}
private:
	void CompareAndInsert(IndexNode *node, IndexNode * &currentRoot)
	{
		if (currentRoot == 0) {
			currentRoot = node;
			return;
		}

		// First compare the index word
		int comparison = currentRoot->indexword.compare(node->indexword);

		if (comparison == 0) {
			//std::cout << "Same index words:" << currentRoot->indexword << " " << node->indexword << std::endl;
			// Next compare the filename
			comparison = currentRoot->filename.compare(node->filename);
			if (comparison == 0) {
				// Next compare the line number
				if (currentRoot->linenumber > node->linenumber) {
					//Insert left
					CompareAndInsert(node, currentRoot->left);
				} else {
					//Insert right
					CompareAndInsert(node, currentRoot->right);
				}
			} else if (comparison > 0) {
				//std::cout << "Smaller filename" << currentRoot->filename << node->filename << std::endl;
				//Insert left
				CompareAndInsert(node, currentRoot->left);
			} else {
				std::cout << "Larger filename" << currentRoot->filename << node->filename << std::endl;
				//Insert right
				CompareAndInsert(node, currentRoot->right);
			}
		} else if (comparison > 0) {
			//std::cout << "Smaller index word:" << currentRoot->indexword << " " << node->indexword << std::endl;
			//Insert left
			CompareAndInsert(node, currentRoot->left);
		} else {
			//std::cout << "Larger index word:" << currentRoot->indexword << " " << node->indexword << std::endl;
			//Insert right
			CompareAndInsert(node, currentRoot->right);
		}
	}

	void PrintTree(IndexNode *currentRoot, IndexNode *lastVisited, std::string currentWord, std::string prevFile)
	{
		if (currentRoot) {
			std::string prevword = currentRoot->left? currentRoot->left->indexword:" ";
			std::string filename = currentRoot->left? currentRoot->left->filename:" ";
			PrintTree(currentRoot->left, lastVisited, prevword, filename);

			//std::cout << "currentWord: " << currentWord << std::endl;
			//std::cout << "prevword: " << prevword << std::endl;
			//std::cout << "currentRoot->indexword: " << currentRoot->indexword << std::endl;
			if (!lastVisited) {		
				if (!currentRoot->left) {
					std::cout << currentRoot->indexword << std::endl;
					std::cout << "\t" << currentRoot->filename << " "
								<< currentRoot->linenumber << std::endl;
				}
			} else if (lastVisited->indexword != currentRoot->indexword) {
				std::cout << currentRoot->indexword << std::endl;
				//std::cout << currentRoot->indexword << std::endl;
			}

			//if (lastVisited && lastVisited->filename != currentRoot->filename) {
				std::cout << "\t" << currentRoot->filename << " "
						<< currentRoot->linenumber << std::endl;
			//}
			lastVisited = currentRoot;
			//}
			//prevword = currentRoot->indexword;

			//prevword = currentRoot->right? currentRoot->right->indexword:"";
			//filename = currentRoot->right? currentRoot->right->filename:"";
			PrintTree(currentRoot->right, lastVisited, prevword, filename);
		}
	}

	IndexNode *root;
	//IndexNode *lastVisited;
};

void IndexBST::AddIndex(const std::string &word,
					const std::string &filename,
					int linenumber)
{
	IndexNode *node = new IndexNode(word, filename, linenumber);
	CompareAndInsert(node, root);
}


static void ParseWords(std::ifstream &file, const char *filename, IndexBST &index)
{
	int LineNumber = 0;

	while (file.good()) {
		std::string str;
		char c = ' ';
		while (!file.eof()) {
			// Eat leading characters
			while (!file.eof() && !isalnum(c)) {
				if (c == '\n') {
					++LineNumber;
				}
				c = file.get();
			}

			// Read words
			while (!file.eof() && isalnum(c)) {
				str.push_back(c);
				c = file.get();
			}

			if (file.eof())
				break;

			index.AddIndex(str, filename, LineNumber+1);
			str.erase();
		}
	}
}

int main(int argc, char *argv[])
{
	IndexBST index;

	for (int i = 1; i < argc; ++i) {
		std::ifstream file(argv[i], std::ifstream::in);

		ParseWords(file, argv[i], index);

		file.close();
	}

	index.Print();

	return 0;
}