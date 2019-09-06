
#include "Portfolio.h"
//Function to generate a new Boggle map in a two dimensional array
//Takes in a size of an array, and a seed to generate.
char ** generateBoggle(int size, int seed){
//First, create a new array and allocate space for it
char **array;
array = allocateCharArray(size, size);

srand(seed); //seeds the board to allow for playing the same board multiple times
char newChar;
//fill the board with random characters
  for(int a=0; a<size; a++){
    for(int b=0; b<size; b++){
      newChar = 'a' + (rand() % 26);
      array[a][b] = newChar;
    }
  }

  return array;
}
