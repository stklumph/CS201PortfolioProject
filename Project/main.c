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
scanf("%s", str);
*/
while(gameContinue == true){
printf("What size Boggle would you like to play? (integers only): \n");
int size = 1;
// reduce to getBoggleSize();
char userInput[200];
fgets(userInput, 200, stdin);
if(atoi(userInput) > 1 ){
  size = atoi(userInput);
  validInput = true;
}
else{
  validInput = false;
}
while(!validInput){
  printf("Error! Invalid Board size. Please try again.\n");
  processUserInput(userInput, 200);
  if(atoi(userInput) > 1){
    size = atoi(userInput);
    validInput = true;
  }
}
printf("Enter a seed (integers only): ");

// reduce to getBoggleSeed();
//char playerSeed[200];
processUserInput(userInput, 200);
int seed = atoi(userInput);

char **Boggle;
Boggle = generateBoggle(size, seed);


char **hashTable = newHashTable(200000);
//putPreWordListIntoHashTable(wordList, hashTable);

solveBoggle(Boggle, size, dict, hashTable, 200000);

//DEBUG: print Hash Table contents
/*
printf("Hash Table Contents:\n");
printStringArray(hashTable, 200000);
*/
printPuzzle(Boggle, size);

//FIXME: insert startGame();
unsigned int score = startGame(Boggle, size, hashTable, 200000);
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
    printf("Error invalid input, please type 'yes' or 'no'");
    validInput = false;
  }
}
}
  return 0;
}
