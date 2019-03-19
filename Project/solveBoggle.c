



int isInDictionary(char *word, Dictionary *dict){
  for(int a = 0; a<dict->dictLen; a++){
      if(strcmp(word, dict->diction[a]) == 0){

        printf("Word found!\n"); //DEBUG: print statement

        return 1;
      }
  }
  return 0;
}



void solveBoggle(char **Boggle, int Boardsize, Dictionary *dict, Dictionary *wordList){
/*
Note: the dictionary used with this program contains no words of length greater than 100
thus, there is no reason to allocate more memory than 100 characters for a word.
*/

char word[100];
char **boardPos;
boardPos = allocateArray(Boardsize, Boardsize);

DFS()


  return;
}
