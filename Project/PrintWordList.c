//Function to print out an entire dictionary of words
//This is mostly used for DEBUG.
void printStringArray(char **array, int size){
  for(int a=0; a<size; a++){
    if(array[a][0] != '\0')
    printf("%s, ", array[a]);
  }
  printf("\n");
  return;
}

void printWordList(Dictionary *wordList){
  for(int a=0; a<wordList->dictLen; a++){
    printf("%s\n", wordList->diction[a]);
  }

  printf("\n");
  return;
}
