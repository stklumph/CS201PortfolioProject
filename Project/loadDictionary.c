void loadDictionary(Dictionary *dict){

//open dictionary file
FILE *fp; //file pointer
if ((fp = fopen("dictionary.txt", "r")) == NULL){ // check to see if file can be opened
  printf("ERROR LOADING DICTIONARY\n\n"); //print error message if necessary
  fclose(fp);
  return;
}

char charIn;
int wordSize = 0;
int wordNumber = 0;

while ((charIn = fgetc(fp)) != EOF){
if(charIn == ' ' || charIn == '\n'){
  wordNumber++;
  }
else{
  dict->diction[wordNumber][wordSize] = charIn;
  }
}

dict->dictLen = wordNumber;

for(int a=0; a<dict->dictLen; a++){
  printf("%s\n",dict->diction[a]);

}
fclose(fp);
return ;
}
