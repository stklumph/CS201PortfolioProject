//Function to print out an entire dictionary of words
void printWordList(Dictionary *wordList){
  for(int a=0; a<wordList->dictLen; a++){
    printf("%s\n", wordList->diction[a]);
  }


  return;
}
