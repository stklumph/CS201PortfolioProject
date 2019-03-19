char ** allocateArray(int rows, int columns){

char **array;
array = malloc(sizeof(char *) * rows);

for(int a=0; a<rows; a++){
  array[a] = malloc(sizeof(char) * columns);
}
return array;
}
