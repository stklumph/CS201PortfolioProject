//Function to print out an entire dictionary of words
void printStringArray(char **array, int size){
  for(int a=0; a<size; a++){
    if(array[a][0] != '\0')
    printf("%s\n", array[a]);
  }
  return;
}

void printWordList(Dictionary *wordList){
  for(int a=0; a<wordList->dictLen; a++){
    printf("%s\n", wordList->diction[a]);
  }

  printf("\n");
  return;
}
