#ifndef NODE_H
#define NODE_H

#include <string>

//forward declaration for Hashentry, due to .h cant include each other.
class Hashentry;


struct Node {
public:
	Node();
	void incFreq();
	int getFrequency();
	Hashentry* getEntry();
	void setEntry(Hashentry& entry);

private:
	int frequency;
	Hashentry* entry;

};




#endif