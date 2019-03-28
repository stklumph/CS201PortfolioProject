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
bool gameContinue = true;
bool validInput = true;
unsigned int gameNumber = 1;
unsigned int maxScore = 0;
char userInput[200];
//Load the dictionary file
//FIXME:
/*
Dictionary *dict2 = malloc(sizeof(Dictionary));
dict2->dictLen = 0;
loadDictionary(dict2);
*/
TrieNode *dict = newTrieNode();
//putPreDictionaryIntoTrie(dict2, dict);
int dictionarySize = loadDictionaryToTrie(dict);
/*
//DEBUG: Print Trie
char str[1000];
int level = 0;
display(dict, str, level);

//loadDictionaryToTrie(dict);
scanf("%s", str);
*/

while(gameContinue == true){
  int boggleSize = getBoggleSize();
  int seed = getBoggleSeed();

char **Boggle;
Boggle = generateBoggle(boggleSize, seed);

int hashTableSize = 2*dictionarySize;
if(hashTableSize < 0){
  printf("Error with size of dictionary.\n");
  exit(1);
}
char **hashTable = newHashTable(hashTableSize);
//putPreWordListIntoHashTable(wordList, hashTable);

solveBoggle(Boggle, boggleSize, dict, hashTable, hashTableSize);

//DEBUG: print Hash Table contents
/*
printf("Hash Table Contents:\n");
printStringArray(hashTable, 200000);
*/
printPuzzle(Boggle, boggleSize);

//FIXME: insert startGame();
unsigned int score = startGame(Boggle, boggleSize, hashTable, hashTableSize);
if(score > maxScore)
  maxScore = score;

printf("Max score: %d\n", maxScore);
printf("Would you like to play again?\n type 'yes' or 'no'\n" );
processUserInput(userInput, 200);
if(strcmp(userInput, "no") == 0){
  //deallocate memory
  free(Boggle);
  free(dict);
  return 0;
}
else if(strcmp(userInput, "yes") == 0){
  gameNumber++;
  printf("Game %d\n", gameNumber);
  free(Boggle);
  validInput = true;
}
else{
    printf("Error invalid input, please type 'yes' or 'no'\n");
    validInput = false;
  }

while(!validInput){
  processUserInput(userInput, 200);
  if(strcmp(userInput, "no") == 0){
    //deallocate memory
    free(Boggle);

    free(dict);
    return 0;
  }
  else if(strcmp(userInput, "yes") == 0){
    gameNumber++;
    printf("Game %d\n", gameNumber);
    validInput = true;
  }
  else{
    printf("Error invalid input, please type 'yes' or 'no\n");
    validInput = false;
  }
}
}
  return 0;
}
