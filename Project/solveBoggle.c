void solveBoggle(char **Boggle, int Boardsize, Dictionary *dict, Dictionary *wordList){
/*
Note: the dictionary used with this program contains no words of length greater than 100
thus, there is no reason to allocate more memory than 100 characters for a word.
*/

char word[1000];
int **boardPos;
int depth = 0;
boardPos = allocateIntArray(Boardsize, Boardsize);


  for(int x=0; x<Boardsize; x++){
      for(int y=0; y<Boardsize; y++){
        dfs(Boggle, Boardsize, dict, wordList, word, boardPos, x, y, depth);
        printf("\n");
    }
  }

  printWordList(wordList);
  return;
}
