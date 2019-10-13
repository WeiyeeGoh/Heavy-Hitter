# Heavy-Hitter
# What it does
This program is an attempt at a naive solution to the heavy hitter problem. It will take in a file of words (or just single words) and create a minheap storing the k most frequent words. If a new word arrives, our program will remove our least frequent word and replace it with the new word. In order to eliminate the situation where new words are always getting replaced because they will no doubt start from 1, we have new words assume the frequency of the word it replaces.

#How to Run
Run the make file. Then run the main executable. You will be prompted to select a number to either add a word, a file full of texts, or other info. 
