//Functions to deallocate dynamically allocated memory

#include "Portfolio.h"
void deallocateCharArray(char **array, int rows){
for(int a=0; a<rows; a++){
  free(array[a]);
}
free(array);
array = NULL;
return;
}


void deallocateIntArray(int **array, int rows){
for(int a=0; a<rows; a++){
  free(array[a]);
}
free(array);
array = NULL;
return;
}
