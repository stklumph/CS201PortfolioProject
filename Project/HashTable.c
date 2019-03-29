/*
This file is designed to hold all of the functions necessary to implement a hash table for this Project
The hash table is used for extremely fast lookup of words
Since the goal is to store words in this hash table, it will also be a two dimensional array of characters.
*/

//Function to create a new hash table based on a size.
char **newHashTable(int size){
return allocateCharArray(size, 1000); //1000 because no given word is larger than 1000 characters, thus no need to go larger
}

/*
Borrowed Code: This is code for the djb2 hash function created by Dan Bernstein, modified.
The code I pulled comes from this link: http://www.cse.yorku.ca/~oz/hash.html
*/

unsigned int hashFunction(char *str, int size){
      unsigned int hash = 5381;
      int c;

      while ((c = *str++))
          hash = ((hash << 5) + hash) + c;

      hash = hash % size;

      return hash;
  }


//Function to insert a word into a hash table
  void insertToHashTable(char **hashTable, char *word, int size){
    //First get the hash value
    unsigned int hash = hashFunction(word, size);

    //Linear Probing for the hash function
    while(hashTable[hash][0]!='\0'){ //check to see if the word is empty, signified by a null character at the start
      hash++; //if the spot is filled, increment
      hash = hash % size; //make sure to not go off the edge by modding by size
    }

      strncpy(hashTable[hash], word, 999); //copy word into hashTable;
      return;
  }

//Function to search the hashTable for a word and return the word
  char *searchHashTable(char **hashTable, char *word, int size){
    unsigned int hash = hashFunction(word, size);

    while(hashTable[hash][0]!='\0'){
      if(strncmp(hashTable[hash], word, strlen(hashTable[hash])) == 0)
        return hashTable[hash];

      hash++;
      hash = hash % size;
    }
    return NULL;
  }

//Function to search the hashTable for a word, and return true if it is in the table
  bool isInHashTable(char **hashTable, char *word, int size){
    //first get the hash value
    unsigned int hash = hashFunction(word, size);
    //linear probing
    while(hashTable[hash][0]!='\0'){
      if(strncmp(hashTable[hash], word, strlen(hashTable[hash])) == 0)//check to see if the word is present at this position
        return true; //if it is, return true

      hash++; //if the word is NOT found here, continue looking until you get to an empty space
      hash = hash % size;  //make sure to not go off the edge by modding by size
    }
    return false; //if the word is not found return false
  }
