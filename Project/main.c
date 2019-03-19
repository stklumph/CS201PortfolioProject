#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
//File includes all of the files used in this Project
#include "Portfolio.h"


int main(void){

//Greet the Player
printf("Welcome to Boggle!\n");


//Load the dictionary file
Dictionary *dict = malloc(sizeof(Dictionary));
dict->dictLen = 0;
loadDictionary(dict);


printf("What size Boggle would you like to play? : \n");

// reduce to getBoggleSize();
char playerSize[100];
scanf("%s", playerSize);
int size = 0;
size = atoi(playerSize);

printf("Enter a seed (MaxSize = 200, integers only): ");

// reduce to getBoggleSeed();
char playerSeed[200];
scanf("%s", playerSeed);
int seed = atoi(playerSeed);

// this is probably good.
char **Boggle;
Boggle = generateBoggle(size, seed);

Dictionary *wordList = malloc(sizeof(Dictionary));
wordList->diction = allocateCharArray(400000, 100);
wordList->dictLen = 0;
//FIXME: insert solveBoggle();
solveBoggle(Boggle, size, dict, wordList);



printPuzzle(Boggle, size);

//FIXME: insert startGame();

//deallocate memory
free(Boggle);
free(wordList);
free(dict);
  return 0;
}
