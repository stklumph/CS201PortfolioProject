int isInDictionary(char *word, Dictionary *dict){
  for(int a = 0; a<dict->dictLen; a++){
      if((strcmp(word, dict->diction[a])) == 0){

        printf("Word found!\n"); //DEBUG: print statement

        return 1;
      }
  }
  return 0;
}
