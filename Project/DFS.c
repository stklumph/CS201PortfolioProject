/*
Code here borrowed and edited from https://www.geeksforgeeks.org/find-number-of-islands/
The reason this code was used was to simplify the process of a dfs on a 2d array.
The code has been changed and customized to be more compatible for this specific program
*/

//Checks whether a position on the board is within Bounds
//Also checks if a position has been visited.
  int withinBounds(char **Boggle, char *word, int Boardsize, int **visited, int x, int y, TrieNode *root){
    if(x >= 0 && y >=0 && //x and y cannot be less than 0
      x < Boardsize && y < Boardsize //x and y must be less than the size of the board.
      && (visited[x][y] == 0) //cannot move to a node that has already been visited.
        && (isTriePrefix(word, root) == true)){ //checks to see if a word is a prefix to another word.
      return 1;
    }

    return 0;
  }

//Depth first search on a 2d array.
//Saves space instead of creating a massive graph with pointers.
  void dfs(char **Boggle, int Boardsize, TrieNode *dict, char **hashTable, char *word, int **visited, int x, int y, int depth, int hashSize){

    //Values to simplify checking each available neighbor in the matrix.
    //Note: 0,0 is excluded because that would result in not moving.
     int xNeighbor[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
     int yNeighbor[8] = {-1, 0, 1, -1, 1, -1, 0, 1};


    visited[x][y] = 1; // mark current positon as visited
    word[depth++] = Boggle[x][y]; //append the character in this positon to the end of the word, and increment depth.
    printf("checking word %s \n", word);

    //DEBUG: Check word status
    //printf("%s\n", word);
    //DEBUG: printf("%c", Boggle[x][y]);
    if ((findWordWithTrie(word, dict)) == true){
      //addToWordList(word, wordList);
      if(isInHashTable(hashTable, word, hashSize) == false) {
        insertToHashTable(hashTable, word, hashSize);
      }
    }

    for(int a=0; a<8; a++){
      //printf("checking xNeighbor %d , yNeighbor %d\n x is %d, y is %d \n", xNeighbor[a], yNeighbor[a], x, y);
        if((withinBounds(Boggle, word, Boardsize, visited, x+xNeighbor[a], y+yNeighbor[a], dict)) == 1){
          dfs(Boggle, Boardsize, dict, hashTable, word, visited, x+xNeighbor[a], y+yNeighbor[a], depth, hashSize);
        }
    }
    visited[x][y] = 0; // mark curent position as not visited. This is done to ensure the node can be revisited from other nodes
    word[depth] = '\0'; //decrement the end of the word.
    depth--;
    printf("word decremented, word is %s\n", word);
    return;
  }
