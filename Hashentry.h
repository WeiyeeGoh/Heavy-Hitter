#ifndef HASHENTRY_H
#define HASHENTRY_H

#include <string>
#include "Node.h"

class Hashentry {
public:
	Hashentry();

	void changeWord(std::string word);
	void deleteEntry();
	void addEntry(std::string word, Node* node);

	bool isDeleted();
	std::string getWord();
	Node* getNode();

	std::string toString();
	void printWord();


private:
	Node* node_ptr;
	std::string word;
	bool deleted;

};



#endif