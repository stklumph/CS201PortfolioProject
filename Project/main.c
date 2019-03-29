/*
CS 201 Portfolio Project: Boggle game
Seth Klumph
Dr. Anderson

*/


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
//Load the dictionary file into the Trie

TrieNode *dict = newTrieNode();
int dictionarySize = loadDictionaryToTrie(dict);

//Game loop
while(gameContinue == true){
  int boggleSize = getBoggleSize(); //Get the size of the Board
  int seed = getBoggleSeed(); //Get the seed to use in the RNG, the board is seeded to allow playing the same board multiple times
printf("Generating Boggle...\n"); //notify the user
char **Boggle;
Boggle = generateBoggle(boggleSize, seed);  //Generate the Boggle Board

//Here, the hashtable size is a function of the dictionary size.
//This is because it requires no resizing and there can never be more words found on a board
//than there are words in the dictionary. thus, 2*dictionarySize came to work well for me.
int hashTableSize = 2*dictionarySize;
//check if there is an error or overflow with the hash table size
if(hashTableSize < 0){
  printf("Error with size of dictionary.\n");
  exit(1);
}
//create the hashTable that will store the words in the Boggle Board
char **hashTable = newHashTable(hashTableSize);

//Solve the Boggle board using dfs, and storing the words in a hastable.
solveBoggle(Boggle, boggleSize, dict, hashTable, hashTableSize);

//print the Boggle board
printPuzzle(Boggle, boggleSize);

//start the game, the game will return the score
unsigned int score = startGame(Boggle, boggleSize, hashTable, hashTableSize);
if(score > maxScore) // check to see if there is a new max score
  maxScore = score; //if there is, assign it to be the new max score.

printf("Your high score: %d\n", maxScore); //inform the player of their high score

//deallocate memory: this is done to avoid memory leaks
deallocateCharArray(hashTable, hashTableSize);
hashTable = NULL;
deallocateCharArray(Boggle, boggleSize);
Boggle = NULL;

//prompt the user for another game
printf("Would you like to play again?\n type 'yes' or 'no'\n" );
//get new input on whether the player wants a new game
processUserInput(userInput, 200);


//carefully decide whether the player wants a new game
if(strncmp(userInput, "no", 3) == 0){
  return 0;
}
else if(strncmp(userInput, "yes", 4) == 0){
  gameNumber++;
  printf("Game %d\n", gameNumber);
  validInput = true;
}
else{
    printf("Error invalid input, please type 'yes' or 'no'\n");
    validInput = false;
  }

while(!validInput){
  processUserInput(userInput, 200);
  if(strncmp(userInput, "no", 3) == 0){
    return 0;
  }
  else if(strncmp(userInput, "yes", 4) == 0){
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
