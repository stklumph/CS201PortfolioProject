char ** allocateCharArray(int rows, int columns){

char **array;
array = malloc(sizeof(char *) * rows);

for(int a=0; a<rows; a++){
  array[a] = malloc(sizeof(char) * columns);
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
      array[a][b] = 0;
  }
}
return array;
}
