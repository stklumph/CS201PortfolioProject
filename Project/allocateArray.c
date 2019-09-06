//Functions to allocate memory for new two-dimensional arrays.
//Two dimensional arrays are common in this project, so functions were made to simplify the process
#include "Portfolio.h"

char ** allocateCharArray(int rows, int columns){

char **array;
array = malloc(sizeof(char *) * rows);

for(int a=0; a<rows; a++){
  array[a] = malloc(sizeof(char) * columns);
  memset(array[a], '\0', columns); //initialize the array to be all null characters
}
return array;
}


int ** allocateIntArray(int rows, int columns){

int **array;
array = malloc(sizeof(int *) * rows);

for(int a=0; a<rows; a++){
  array[a] = malloc(sizeof(int) * columns);
}

for(int a=0; a<rows; a++){
  for(int b=0; b<columns; b++){
      array[a][b] = 0; //initialize the array to be all 0's
  }
}
return array;
}
