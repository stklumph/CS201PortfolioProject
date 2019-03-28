void deallocateCharArray(char **array, int rows){
for(int a=0; a<rows; a++){
  free(array[a]);
}
free(array);
return;
}


void deallocateIntArray(int **array, int rows){

for(int a=0; a<rows; a++){
  free(array[a]);
}
free(array);

return;
}
