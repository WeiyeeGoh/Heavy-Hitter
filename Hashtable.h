#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <string>
#include "Hashentry.h"

class Hashtable { 

public: 
	Hashtable();
	void insertWord(std::string word, Node* node);
	void deleteWord(std::string word);
	void changeWord(int index, std::string word);
	int searchWord(std::string word); //return word index
	Hashentry getHashEntry(int index);
	void printHashTable();

private:
	int cur_size;
	int max_size;
	Hashentry* entry_list;

	int hash(std::string str);
};

#endif
