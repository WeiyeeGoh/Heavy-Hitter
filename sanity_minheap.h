#ifndef MINHEAP_H
#define MINHEAP_H

#include <string>
#include "Node.h"
#include "Hashentry.h"

class Minheap {

public:
	Minheap();
	void add(std::string word);
	int search(std::string word);
	int insertWord(std::string word, Node* node);
	void replaceMin(std::string word);

	void printHeap();
	void printHashTable();
	void swap(Node* n1, Node* n2);
	void heapify(int index = 1);
	int hash(std::string word, int max_size);

	Node* getRoot();
	int getParent(int child_index);
	int getLeftChild(int parent_index);
	int getRightChild(int parent_index);

	void expandTree();
	void printHeap15();
	void printHashTable15();

private:
	Node** minheap;
	Hashentry* hashtable;
	int max_size;
	int cur_size;

};

#endif