/*
This file is designed to hold all of the functions necessary to implement a hash table for this Project
The hash table is used for extremely fast lookup of words
Since the goal is to store words in this hash table, it will also be a two dimensional array of characters.
*/

//Function to create a new hash table based on a size.
char **newHashTable(int size){
return allocateCharArray(size*size, 1000);
}

/*
Borrowed Code: This is code for the djb2 hash function created by Dan Bernstein, modified.
The code I pulled comes from this link: http://www.cse.yorku.ca/~oz/hash.html
*/

unsigned int hashFunction(char *str, int size){
      unsigned int hash = 5381;
      int c;

      while ((c = *str++))
          hash = ((hash << 5) + hash) + c; /* hash * 33 + c */

      hash = hash % size;

      return hash;
  }


  void insertToHashTable(char **hashTable, char *word, int size){

    unsigned int hash = hashFunction(word, size);

    //Linear Probing for the hash function
    while(hashTable[hash][0]!='\0'){
      hash++;
      hash = hash % size;
    }

      strcpy(hashTable[hash], word); //copy word into hashTable;
      return;
  }

  char *searchHashTable(char **hashTable, char *word, int size){
    unsigned int hash = hashFunction(word, size);

    while(hashTable[hash][0]!='\0'){
      if(strcmp(hashTable[hash], word) == 0)
        return hashTable[hash];

      hash++;
      hash = hash % size;
    }
    return NULL;
  }

  bool isInHashTable(char **hashTable, char *word, int size){
    unsigned int hash = hashFunction(word, size);

    while(hashTable[hash][0]!='\0'){
      if(strcmp(hashTable[hash], word) == 0)
        return true;

      hash++;
      hash = hash % size;
    }
    return false;
  }


void putPreWordListIntoHashTable(Dictionary *wordList, char **hashTable){
  for(int a=0; a<wordList->dictLen; a++){
    insertToHashTable(hashTable, wordList->diction[a], (wordList->dictLen * wordList->dictLen));
  }

}
