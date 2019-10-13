#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>

#include "Hashentry.h"
#include "sanity_minheap.h"
#include "Node.h"

void readAndInsertFileWords(Minheap &heap, std::string filename) {
	std::ifstream myfile;
	myfile.open(filename.c_str());
	std::string word;
	while(!myfile.eof()) {
		myfile >> word;
		if (myfile.eof()) break;
		heap.add(word);
	}
	myfile.close();
}


int main() {

	
	bool run = true;
	Minheap heap;

	/*
	std::string filename = "";
	//getline(std::cin, filename);
	
	std::ifstream myfile;
	myfile.open(filename.c_str());
	std::string word;
	while(!myfile.eof()) {
		myfile >> word;
		std::cout << word << std::endl;
		heap.add(word);
	}
	myfile.close();
	
	*/


	while(run) {
		std::cout << "input a commmand: q is quit, 1 is add a word, 2 adds file, 3 is print heap, 4 is print hash table, 5 is print top 15 heap, 6 is print top 16 hash table" << std::endl << ">> ";
		std::string u_input;
		getline(std::cin, u_input);
		if(u_input == "q") {
			run = false;
		} else if (u_input == "1") {
			std::string word = "";
			std::cout << ">> ";
			getline(std::cin, word);
			heap.add(word);
		} else if (u_input == "2") {
			std::string word = "";
			std::cout << ">> ";
			getline(std::cin, word);
			readAndInsertFileWords(heap, word);		
		} else if (u_input == "3") {
			heap.printHeap();
		} else if (u_input == "4") {
			heap.printHashTable();
		} else if (u_input == "5") {
			heap.printHeap15();
		} else if (u_input == "6") {
			heap.printHashTable15();
		}
	}

}