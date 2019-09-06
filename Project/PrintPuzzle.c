
#include "Portfolio.h"
//Function to print out the Boggle Puzzle
//Takes in a two dimensional array, and the size of the array
void printPuzzle(char **array, int size){

printf("Boggle Board: \n\n");
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
