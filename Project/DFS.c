/*
Code here borrowed and edited from https://www.geeksforgeeks.org/find-number-of-islands/
The reason this code was used was to simplify the process of a dfs on a 2d array.
The code has been changed and customized to be more compatible for this specific program
*/

//Checks whether a position on the board is within Bounds
//Also checks if a position has been visited.
  int withinBounds(char **Boggle, int Boardsize, int **visited, int x, int y){
    if(x >= 0 && y >=0 && //x and y cannot be less than 0
      x < Boardsize && y < Boardsize //x and y must be less than the size of the board.
      && (visited[x][y] == 0)){ //cannot move to a node that has already been visited.
      return 1;
    }

    return 0;
  }

//Depth first search on a 2d array.
//Saves space instead of creating a massive graph with pointers.
  void dfs(char **Boggle, int Boardsize, Dictionary *dict, Dictionary *wordList, char *word, int **visited, int x, int y, int depth){

    //Values to simplify checking each available neighbor in the matrix.
    //Note: 0,0 is excluded because that would result in not moving.
    static int xNeighbor[] = {-1, -1, -1, 0, 0, 1, 1, 1};
    static int yNeighbor[] = {-1, 0, 1, -1, 1, -1, 0, 1};


    visited[x][y] = 1; // mark current positon as visited
    word[depth++] = Boggle[x][y]; //append the character in this positon to the end of the word, and increment depth.

    //DEBUG: Check word status
    //printf("%s\n", word);
    //DEBUG: printf("%c", Boggle[x][y]);
    if ((isInDictionary(word, dict)) == 1){
      addToWordList(word, wordList);
    }

    for(int a=0; a<8; ++a){
        if((withinBounds(Boggle, Boardsize, visited, x+xNeighbor[a], y+yNeighbor[a]))){
          dfs(Boggle, Boardsize, dict, wordList, word, visited, x+xNeighbor[a], y+yNeighbor[a], depth);
        }
    }
    visited[x][y] = 0; // mark curent position as not visited. This is done to ensure the node can be revisited from other nodes
    word[depth--] = '\0'; //decrement the end of the word.
    return;
  }
