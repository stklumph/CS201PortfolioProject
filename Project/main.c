#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
//File includes all of the files used in this Project
#include "Portfolio.h"


int main(void){

//Greet the Player
printf("Welcome to Boggle!\n");


//Load the dictionary file
//FIXME:
Dictionary *dict2 = malloc(sizeof(Dictionary));
dict2->dictLen = 0;
loadDictionary(dict2);

TrieNode *dict = newTrieNode();
putPreDictionaryIntoTrie(dict2, dict);

/*
//DEBUG: Print Trie
char str[1000];
int level = 0;
display(dict, str, level);

//loadDictionaryToTrie(dict);
*/

printf("What size Boggle would you like to play? : \n");

// reduce to getBoggleSize();
char playerSize[100];
fgets(playerSize, 100, stdin);
int size = atoi(playerSize);

printf("Enter a seed (MaxSize = 200, integers only): ");

// reduce to getBoggleSeed();
char playerSeed[200];
processUserInput(playerSeed, 100);
int seed = atoi(playerSeed);

char **Boggle;
Boggle = generateBoggle(size, seed);

//FIXME: change to hash table for better lookup
/*
Dictionary *wordList = malloc(sizeof(Dictionary));
wordList->diction = allocateCharArray(400000, 100);
wordList->dictLen = 0;
*/
char **hashTable = newHashTable(200000);
//putPreWordListIntoHashTable(wordList, hashTable);

solveBoggle(Boggle, size, dict, hashTable, 200000);

//DEBUG: print Hash Table contents
printf("Hash Table Contents:\n");
printStringArray(hashTable, 200000);

printPuzzle(Boggle, size);

//FIXME: insert startGame();
startGame(Boggle, size, hashTable, 200000);


//deallocate memory
free(Boggle);
//free(wordList);
free(dict);
  return 0;
}
