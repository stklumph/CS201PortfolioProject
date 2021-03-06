
#include "Portfolio.h"
//Function to solve the Boggle Board

void solveBoggle(char **Boggle, int Boardsize, TrieNode* dict, char **hashTable, int hashSize){
/*
Note: the dictionary used with this program contains no words of length greater than 1000
thus, there is no reason to allocate more memory than 1000 characters for a word.
*/

char word[1000] = ""; //Make an empty word to send to the dfs
int **boardPos; // create an array to keep track of position on the board in dfs
boardPos = allocateIntArray(Boardsize, Boardsize); //allocate space for the postion array
int depth = 0; //int to keep track of how many nodes have been visited in dfs


  for(int x=0; x<Boardsize; x++){
      for(int y=0; y<Boardsize; y++){
          dfs(Boggle, Boardsize, dict, hashTable, word, boardPos, x, y, depth, hashSize);

    }
  }

deallocateIntArray(boardPos, Boardsize);// return the memory for boardPos, not needed after the board is solved


  return;
}
