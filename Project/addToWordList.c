//Function to add a word to the list of words found
void addToWordList(char *word, Dictionary *WordList){

strcpy(WordList->diction[WordList->dictLen++], word);

}
