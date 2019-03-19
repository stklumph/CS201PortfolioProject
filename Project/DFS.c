//Checks whether a position on the board is within Bounds
//Also checks if a position has been visited.
  int withinBounds(char **Boggle, int Boardsize, int **visited, int x, int y){
    if(x >= 0 && y >=0 &&
      x < Boardsize && y < Boardsize && (visited[x][y] == 0)){
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

    visited[x][y] = 1;
    word[depth++] = Boggle[x][y];

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
    visited[x][y] = 0;
    word[depth--] = '\0';
    return;
  }
