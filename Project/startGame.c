
#include "Portfolio.h"
//The function to run the game part of the game
unsigned int startGame(char **Boggle, int boggleSize, char **hashTable, int hashSize){
  printf("Game start!\n"); //Tell the user the game is starting
  printf("Type words found in the puzzle to gain points!\n (Type !help for a list of commands)\n (Type !exit when you are finished)\n");
  bool gameFinished = false; //boolean to tell if the game is finished or not
  char *userIn = malloc(sizeof(char) * 1000); //userInput buffer variable
  memset(userIn, '\0', 1000); //initialize every character in userInput to be null character.
  int wordScore = 0;
  unsigned int userScore = 0; //variable to hold the user's score
  unsigned int wordLength = 0; // variable to hold the length of the word a user inputs
  char **wordFoundHashTable = newHashTable(hashSize); //a second hashTable to determine how large

  while(!gameFinished){
    processUserInput(userIn, 999);

    //Command List. Commands are accessed using the character '!' before typing the command to differentiate between words and commands
    if (userIn[0] == '!'){
      if(strncmp(userIn, "!print", 6) == 0) //command to print the board again
        printPuzzle(Boggle, boggleSize);

      else if(strncmp(userIn, "!exit", 5) == 0) //comand to exit the game
        gameFinished = true;

      else if(strncmp(userIn, "!cheat", 6) == 0){ //command to print all of the words found in the board
        printf("Words in Boggle Board:\n");
        printStringArray(hashTable, hashSize);
      }
      else if(strncmp(userIn, "!help", 5) == 0){ //command to print the list of commands
        printf("Commands:\n");
        printf("!print : prints the Boggle board\n");
        printf("!exit : exits the game\n");
        printf("!cheat : prints all the words in the Boggle board\n");
        printf("!help : prints this list of commands\n");
      }

      else{
        printf("Unknown command, type !help for a list of commands.\n"); //error message for any unknown commmand
      }
    }

    //If it is not a command, then it is assumed to be input for a word
    else{
      //check to see if the given word is both in the list of words, and not already found
      if((isInHashTable(hashTable, userIn, hashSize) == true) && (isInHashTable(wordFoundHashTable, userIn, hashSize) == false)){
        wordLength = strlen(userIn);
        wordScore =  getWordScore(wordLength);
        userScore += wordScore;
        printf("Word found! Worth %d points. \nscore: %d\n", wordScore, userScore);
        insertToHashTable(wordFoundHashTable, userIn, hashSize); // add the word to the list of words already found
      }
      else if((isInHashTable(wordFoundHashTable, userIn, hashSize) == true)){ //check to see if the word is already found
        printf("Word already found!\n");
      }
      else if((isInHashTable(hashTable, userIn, hashSize) == false)){ //check to see if the word is in the list of words
        printf("Word not found in Boggle Board!\n");
      }
    }
  }
    printf("Your score: %d\n", userScore);
    printf("Maximum score possible for this Board: %d\n", getMaxPossibleScore(hashTable, hashSize));
    //deallocate the memory used for the second hashTable and buffer input
    deallocateCharArray(wordFoundHashTable, hashSize);
    free(userIn);
    return userScore;
}
