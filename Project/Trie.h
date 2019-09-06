#ifndef TRIE_H
#define TRIE_H

//Trie node
typedef struct trieNode {
//pointers to children nodes, one for each alphabetical letter.
//Note that this implementation of a Trie assumes that the index will correspond to the letter.
//This means that a will be located at index 0, b will be located at index 1, and so on.
struct trieNode *children[26];
char key; // the character the node represents. Important for comparisons
bool isEndOfWord; //stores whether the character signifies the end of a word
} TrieNode;

 TrieNode *newTrieNode();
 int charToIndex(char c);
 void insertTrieNode(TrieNode *root, const char *key);
 TrieNode *getNextNode(TrieNode *currentNode, char nextLetter);
 bool isNodeEndOfWord(TrieNode *currentNode);
 bool findWordWithTrie(char *word, TrieNode *root);
 TrieNode * getEndOfWordWithTrie(char *word, TrieNode *root);
 bool isTriePrefix(char *word, TrieNode *root);

#endif
