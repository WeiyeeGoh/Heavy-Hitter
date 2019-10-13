#include "Hashentry.h"
#include <string>
#include <iostream>
#include "Node.h"


Hashentry::Hashentry() {
	node_ptr = NULL;
	word = "";
	deleted = true;
}

void Hashentry::changeWord(std::string word) {
	this->word = word;
}

void Hashentry::deleteEntry() { 
	deleted = true; 
}

void Hashentry::addEntry(std::string word, Node* node) {
	this->word = word;
	this->node_ptr = node;
	this->deleted = false;
}


bool Hashentry::isDeleted() { 
	return deleted; 
}

std::string Hashentry::getWord() { 
	return word; 
}

Node* Hashentry::getNode() { 
	return node_ptr; 
}

std::string Hashentry::toString() {
	std::string result = "";
	result += word + " ( " + std::to_string(node_ptr->getFrequency()) + " )";
	return result;
}

void Hashentry::printWord() {
	std::cout << word << std::endl;
}