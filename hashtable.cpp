#include <iostream>
#include <string>

#include "Hashtable.h"
#include "Hashentry.h"
#include "Node.h"
#include "sha256.h"


Hashtable::Hashtable() {
	cur_size = 0;
	max_size = 16;
	entry_list = new Hashentry[max_size];
}

void Hashtable::insertWord(std::string word, Node* node) {
	int index = hash(word);
	for(int i = index; i < cur_size + 1; i++) {
		if(entry_list[i].isDeleted()) {
			entry_list[i].addEntry(word, node);
			return;
		}
	}

	for(int i = 1; i < index; i++) {
		if(entry_list[i].isDeleted()) {
			entry_list[i].addEntry(word, node);
			return;
		}
	}
}

void Hashtable::changeWord(int index, std::string word) {
	entry_list[index].changeWord(word);
}

void Hashtable::deleteWord(std::string word) {
	int index = searchWord(word);

	//if 0, means word didnt exist so no return. more of a safety check because other func wouldn't delete unless word exists
	if (index == 0) {
		return;
	}

	entry_list[index].deleteEntry();
}

int Hashtable::searchWord(std::string word) {
	int index = hash(word);

	//check hashed location and automatically linear probe to end of array
	for(int i = index; i < cur_size + 1; i++) {
		if(entry_list[i].getWord() == word) {
			return i;
		}
	}

	//once you reach end of array, start from beginning again and go to hashed index
	for(int i = 1; i < index; i++) {
		if(entry_list[i].getWord() == word) {
			return i;
		}
	}

	return 0;
}

Hashentry Hashtable::getHashEntry(int index) {
	return entry_list[index];
}


int Hashtable::hash(std::string str) {
	//TODO
	return sha256(str) % max_size;
}


void Hashtable::printHashTable() {
	std::cout << "Printint out Hash Table" << std::endl;
	std::cout << "-----------------------" << std::endl;
	for(int i = 0; i < cur_size; i++) {
		std::cout << "index: " << i << " | " << entry_list[i].toString() << std::endl;
	}
	std::cout << "-----------------------" << std::endl;	
}
