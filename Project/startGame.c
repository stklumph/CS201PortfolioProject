
void startGame(char **Boggle, int boggleSize, char **hashTable, int hashSize){
  printf("Game start!\n");
  printf("Type words found in the puzzle to gain points!\n (Type !help for a list of commands)\n");
  bool gameFinished = false;
  char userIn[10]; //FIXME: make userin larger, and dynamically allocated]
  unsigned int userScore =0;
  char **wordFoundHashTable = newHashTable(200000);

  while(!gameFinished){
    processUserInput(userIn, 10);
    if (userIn[0] == '!'){
      if(strcmp(userIn, "!print") == 0)
        printPuzzle(Boggle, boggleSize);

      else if(strcmp(userIn, "!exit") == 0)
        gameFinished = true;

      else if(strcmp(userIn, "!help") == 0){
        printf("Commands:\n");
        printf("!print : prints the Boggle board\n");
        printf("!exit : exits the game\n");
        printf("!help : prints this list of commands\n");
      }

      else{
        printf("Unknown command, type !help for a list of commands.\n");
      }
    }
    else{
      if((isInHashTable(hashTable, userIn, hashSize) == true) && (isInHashTable(wordFoundHashTable, userIn, hashSize) == false)){
        printf("Word found! \nscore: %d\n", ++userScore);
        insertToHashTable(wordFoundHashTable, userIn, hashSize);
      }
      else if((isInHashTable(wordFoundHashTable, userIn, hashSize) == true)){
        printf("Word already found!\n");
      }
      else if((isInHashTable(hashTable, userIn, hashSize) == false)){
        printf("Word not found in Boggle Board!\n");
      }
    }
  }

}
