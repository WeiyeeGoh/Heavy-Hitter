#include "Node.h"
#include "Hashentry.h"

Node::Node() { 
	entry = NULL;
	frequency = 1;
}

void Node::incFreq() { 
	frequency++;
}


int Node::getFrequency() { 
	return frequency;
}

Hashentry* Node::getEntry() {
	return entry;
}

void Node::setEntry(Hashentry& entry) {
	this->entry = &entry;
}