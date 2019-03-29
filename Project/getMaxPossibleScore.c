//Function to get the maximum possible score on a board
int getMaxPossibleScore(char **hashTable, int hashTableSize){
  int score = 0;
  unsigned int wordLength = 0;
  for(int a=0; a<hashTableSize; a++){
    wordLength = strlen(hashTable[a]);
    //checks to see if the wordlength is positive, and that there is a word there
    if(wordLength > 0 && hashTable[a][0] != '\0')
      score += getWordScore(wordLength); //adds the corresponding score based on the length of the word 
  }

  return score;
}
