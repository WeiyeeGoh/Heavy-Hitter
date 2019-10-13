main: main.o  Hashentry.h hashentry.cpp Minheap.h Node.h minheap.cpp node.cpp
	g++ -std=c++11 -o main main.cpp minheap.cpp node.cpp hashentry.cpp -lcrypto

test: test.o  Hashentry.h hashentry.cpp Minheap.h Node.h minheap.cpp node.cpp
	g++ -std=c++11 -o test test.cpp minheap.cpp node.cpp hashentry.cpp -lcrypto

sanity: sanity.o  Hashentry.h hashentry.cpp sanity_minheap.h Node.h sanity_minheap.cpp node.cpp
	g++ -std=c++11 -o sanity sanity.cpp sanity_minheap.cpp node.cpp hashentry.cpp -lcrypto

clean: 
	rm *.o