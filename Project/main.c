#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//Function to print out the Boggle Puzzle
//Takes in a two dimensional array, and the size of the array
void printPuzzle(char **array, int size){

//start by print a newline and a tab
printf("\n\t");

//Nested loop to run through the entire puzzle
for(int a=0; a<size; a++){
  for(int b=0; b<size; b++){
      printf("%c", array[a][b]); //print out one element in the array
    }
  //check to see if at the end of a line
  if(a<size-1)
    //if at the end of a line, print a newline and a tab
    printf("\n\t");
  else
  printf("\n");
}
printf("\n");
  return;
}

//Function to generate a new Boggle map in a two dimensional array
//Takes in a size of an array, and a seed to generate.
char ** generateBoggle(int size, int seed){

char **array;
array = malloc(sizeof(char *) * size);

for(int a=0; a<size; a++){
  array[a] = malloc(sizeof(char) * size);
}

srand(seed);
char newChar;
for(int a=0; a<size; a++){
for(int b=0; b<size; b++){
newChar = 'A' + (rand() % 26);
array[a][b] = newChar;
}
}

  return array;
}

int main(void){

//Greet the Player
printf("Welcome to Boggle!\n");
printf("What size Boggle would you like to play? : \n");

// reduce to getBoggleSize();
char playerSize[100];
scanf("%s", playerSize);
int size = 0;
size = atoi(playerSize);

printf("Enter a seed (MaxSize = 200): ");

// reduce to getBoggleSeed();
char playerSeed[200];
scanf("%s", playerSeed);
int seed = atoi(playerSeed);

// this is probably good.
char **array;
array = generateBoggle(size, seed);
printPuzzle(array, size);

//insert startGame(); 
  return 0;
}
