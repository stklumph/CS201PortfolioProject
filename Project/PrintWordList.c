
#include "Portfolio.h"
//Function to print out an entire dictionary of words
//This is mostly used for DEBUG, and !cheat

void printStringArray(char **array, int size){
  for(int a=0; a<size; a++){
    if(array[a][0] != '\0')
    printf("%s, ", array[a]);
  }
  printf("\n");
  return;
}
