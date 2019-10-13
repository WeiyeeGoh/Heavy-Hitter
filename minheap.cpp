#include <iostream>
#include <string>
#include "Minheap.h"
#include "Node.h"
#include "Hashentry.h"



Minheap::Minheap() {
	max_size = 15;
	cur_size = 0;
	minheap = new Node*[max_size + 1];
	hashtable = new Hashentry[max_size + 1];
}


void Minheap::add(std::string word) {
	if(int index = search(word)) {
		hashtable[index].getNode()->incFreq();
		heapify();
	} else {
		//when cur_size is 1, there is 1 item. when cur_size is 15, there is 15 items and maxed. 0 is not used
		if(cur_size < max_size) {
			Node* node = new Node();
			cur_size += 1;
			minheap[cur_size] = node;
			int i = insertWord(word, node);
			node->setEntry(hashtable[i]);
			heapify();
		} else {
			replaceMin(word);
		}
	}
}

int Minheap::insertWord(std::string word, Node* node) {
	int index = hash(word);
	for(int i = index; i < cur_size + 1; i++) {
		if(hashtable[i].isDeleted()) {
			hashtable[i].addEntry(word, node);
			return i;
		}
	}

	for(int i = 1; i < index; i++) {
		if(hashtable[i].isDeleted()) {
			hashtable[i].addEntry(word, node);
			return i;
		}
	}

	return 0;
}

int Minheap::search(std::string word) {
	int index = hash(word);

	//check hashed location and automatically linear probe to end of array
	for(int i = index; i < cur_size + 1; i++) {
		if(hashtable[i].getWord() == word) {
			return i;
		}
	}

	//once you reach end of array, start from beginning again and go to hashed index
	for(int i = 1; i < index; i++) {
		if(hashtable[i].getWord() == word) {
			return i;
		}
	}

	return 0;
}

void Minheap::replaceMin(std::string word) {
	std::cout << "replaceMin Run" << std::endl;
	Node* root = getRoot();
	root->getEntry()->deleteEntry();
	int i = insertWord(word, root);
	root->setEntry(hashtable[i]);
}



void Minheap::printHeap() {

	std::cout << "======------PRINTING MINHEAP------======" << std::endl;
	for(int i = 1; i < cur_size + 1; i++) {
		std::cout << "--Node-" << i << "--------------------" << std::endl;
		std::cout << "Word: " << minheap[i]->getEntry()->getWord() << std::endl;
		std::cout << "Frequency: " << minheap[i]->getFrequency() << std::endl << std::endl;
	}
}

void Minheap::printHashTable() {
	std::cout << "======------PRINTING HASH TABLE------======" << std::endl;
	for(int i = 1; i < cur_size + 1; i++) {
		std::cout << "--Entry-" << i << "--------------------" << std::endl;
		std::cout << "Word: " << hashtable[i].getWord() << std::endl;
		std::cout << "Frequency: " << hashtable[i].getNode()->getFrequency() << std::endl << std::endl;
	}
}

//probably not functional rn. figure out later
void swap(Node* n1, Node* n2) {
	Node* temp = n1;
	n1 = n2;
	n2 = temp;
}

void Minheap::heapify(int root_index) {

	if(root_index > cur_size) {
		return;
	}

	int right = getRightChild(root_index);
	int left = getLeftChild(root_index);

	int smallest;

	if(left <= max_size && right <= max_size) {
		if(minheap[left] == NULL) {
			return;
		} else if (minheap[right] == NULL) {
			smallest = left;
		} else {
			if(minheap[left]->getFrequency() <= minheap[right]->getFrequency()) {
				smallest = left;
			} else {
				smallest = right;
			}
		}

		if(minheap[root_index]->getFrequency() > minheap[smallest]->getFrequency()) {
			Node* temp = minheap[root_index];
			minheap[root_index] = minheap[smallest];
			minheap[smallest] = temp;
		}

		if(minheap[left] != NULL)
			heapify(left);

		if(minheap[right] != NULL)
			heapify(right);
	}
}

int Minheap::hash(std::string str) {
	int result;
	for(int i = 0; i < str.length(); i++) {
		int a = (int)str.at(i);
		if(a >= 65 && a <= 90) {
			a += 32;
		}
		result += a;
	}
	return (result % 15) + 1;
}

Node* Minheap::getRoot() {
	return minheap[1];
}


int Minheap::getParent(int child_index) {
	return child_index / 2;
}

int Minheap::getLeftChild(int parent_index) {
	return parent_index * 2;
}

int Minheap::getRightChild(int parent_index) {
	return parent_index * 2 + 1;
}