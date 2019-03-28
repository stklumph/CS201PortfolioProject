void loadDictionary(Dictionary *dict){

//open dictionary file
FILE *fp; //file pointer
if ((fp = fopen("dictionary.txt", "r")) == NULL){ // check to see if file can be opened
  printf("ERROR LOADING DICTIONARY : DICTIONARY NOT FOUND\n\n"); //print error message if necessary
  fclose(fp);
  exit(1);
}
printf("Loading Dictionary\n");

dict->diction = (char**)malloc(400000 * sizeof(char *));
for (int i=0; i<400000; i++){
    dict->diction[i] = (char*)malloc(100*sizeof(char));
    memset(dict->diction[i], '\0', 100);
}

char charIn;
int wordSize = 0;
int wordNumber = 0;

while ((charIn = fgetc(fp)) != EOF){
if(charIn == ' ' || charIn == '\n'){
  wordNumber++;
  wordSize = 0;
  }
else{
    dict->diction[wordNumber][wordSize] = tolower(charIn);
    wordSize++;
  }
}

dict->dictLen = wordNumber;

/* //DEBUG FOR DICTIONARY IN
for(int a=0; a<dict->dictLen; a++){
  printf("%s\n",dict->diction[a]);
}
*/
printf("Dictionary size: %d words\n", dict->dictLen);
fclose(fp);
return ;
}

void putPreDictionaryIntoTrie(Dictionary *dict, TrieNode *root){
  for(int a = 0; a<dict->dictLen; a++){
    insertTrieNode(root, dict->diction[a]);
  }
}

int loadDictionaryToTrie(TrieNode *root){

//open dictionary file
FILE *fp; //file pointer
if ((fp = fopen("dictionary.txt", "r")) == NULL){ // check to see if file can be opened
  printf("ERROR LOADING DICTIONARY\n\n"); //print error message if necessary
  fclose(fp);
  exit(1);
}
printf("Loading Dictionary\n");
char wordBuild[1000];
memset(wordBuild, '\0', 1000);
char charIn;
int wordSize = 0;
int wordNumber = 0;

while ((charIn = fgetc(fp)) != EOF){
if(charIn == ' ' || charIn == '\n'){
  insertTrieNode(root, wordBuild);
  wordNumber++;
  wordSize = 0;
  memset(wordBuild, '\0', 1000);
  }
else{
  wordBuild[wordSize] = tolower(charIn);
  //printf("word is %s", wordBuild);
    wordSize++;
  }
}



/* //DEBUG FOR DICTIONARY IN
for(int a=0; a<dict->dictLen; a++){
  printf("%s\n",dict->diction[a]);
}
*/
printf("Dictionary size: %d words\n", wordNumber);
fclose(fp);
return wordNumber;
}
