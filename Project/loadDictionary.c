
#include "Portfolio.h"
//Function to load the dictionary file for use in the program

int loadDictionaryToTrie(TrieNode *root){

//open dictionary file
//Dictionary File I used comes from http://boulter.com/scrabble/words/words.txt
//I highly reccommend using this file, as it requires no extra preprocessing

FILE *fp; //file pointer
if ((fp = fopen("dictionary.txt", "r")) == NULL){ // check to see if file can be opened
  printf("ERROR LOADING DICTIONARY\n\n"); //print error message if necessary
  fclose(fp);
  exit(1); //if the dictionary does not load, the program will NOT work, so it is best to exit.
}
printf("Loading Dictionary\n");
char wordBuild[1000]; //string input buffer
memset(wordBuild, '\0', 1000); //initialize every space with null character
char charIn;
int wordSize = 0;
int wordNumber = 0;

//loop to go through the entire dictionary file and extract all the words to the Trie structure
while ((charIn = fgetc(fp)) != EOF){
if(charIn == ' ' || charIn == '\n'){ //This implementaiton assumes that the words will be separated by either spaces or newlines
  insertTrieNode(root, wordBuild);
  wordNumber++; //count the number of words
  wordSize = 0; //reset the word size
  memset(wordBuild, '\0', 1000); //reset the input buffer for safety
  }
else{ //if it is not the end of a word, add the current character to the end of the input buffer
  wordBuild[wordSize] = tolower(charIn);
    wordSize++; // increment the size of the word
  }
}

printf("Dictionary size: %d words\n", wordNumber); //Inform the user the size of their dictionary
fclose(fp); //close the file
return wordNumber; //return the number of words in the dictionary
}
