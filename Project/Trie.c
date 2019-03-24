/*
Contains Functions Related to Trie for this Project
A Trie is used here because it gives both a way to effectively search for a word from the dictionary,
and it also is prefix sensitive. So, if a set of characters does not represent a prefix of any word
it will be skipped, greatly reducing runtime and search efficiency when solving the board.

Code Borrowed from https://www.geeksforgeeks.org/trie-insert-and-search/
This code was borrowed and edited to simplify the implementation of a Trie data structure.
*/



//Trie node
typedef struct trieNode {
//pointers to children nodes, one for each alphabetical letter.
//Note that this implementation of a Trie assumes that the index will correspond to the letter.
//This means that a will be located at index 0, b will be located at index 1, and so on.
struct trieNode *children[26];
char key; // the character the node represents. Important for comparisons
bool isEndOfWord; //stores whether the character signifies the end of a word
} TrieNode;

//Function to creat a new Trie Node
TrieNode *newTrieNode(){

    //create the new node and allocate memory to it
    TrieNode *newNode = NULL;
    newNode = (TrieNode *)malloc(sizeof(TrieNode));

    //if the new node is successfully created, initialize its variables
    if(newNode){
      newNode->isEndOfWord = false;
      for(int a = 0; a<26; a++){
        newNode->children[a] = NULL; // make all children nodes set to NULL to be changed later.
      }
    }
    return newNode;
}

//Function to take a given character and determine its index number i.e. a=0, b=1, etc.
int charToIndex(char c){
  return (int)c - (int)'a';
}

void insertTrieNode(TrieNode *root, const char *key){
  //printf("Called insertTrieNode\n");

    int level = 0;
    int length = strlen(key);
    int index = 0;

    //Start at the root
    TrieNode *currentNode = root;

    for(level = 0; level < length; level++){

      index = charToIndex(key[level]); //determine what index to go to based on letter of the word

      if(currentNode->children[index] == NULL){
        currentNode->children[index] = newTrieNode(); //If no node exists, make one
        currentNode->children[index]->key = key[level]; //set key of the newNode to the current character in the word
      }
      currentNode = currentNode->children[index]; //move to next node
    }
    currentNode->isEndOfWord = true; // last inserted Node holds a character that is the end of a word.
}

/*FIXME:
For the purposes of this project and to give the best runtimes, the most efficient way to check through
this tree is to have a function that returns the
*/


TrieNode *getNextNode(TrieNode *currentNode, char nextLetter){
return currentNode->children[charToIndex(nextLetter)]; //returns the next node at that position, if no node, it will be null.
}

bool isNodeEndOfWord(TrieNode *currentNode){
  return currentNode->isEndOfWord;
}


//Function to find words in the Trie
bool findWordWithTrie(char *word, TrieNode *root){
  TrieNode *currentNode = root;
  int length = strlen(word);
  int index = 0;

    for (int level = 0; level < length; level++){
      index = charToIndex(word[level]);

      if(currentNode->children[index] == NULL){
        return false;
      }
      currentNode = currentNode->children[index];
    }
    return (currentNode != NULL && currentNode->isEndOfWord);
  }

/* DEBUG
  // function to display the content of Trie
  void display(TrieNode* root, char str[], int level)
  {
      // If node is leaf node, it indiicates end
      // of string, so a null charcter is added
      // and string is displayed
      if (isNodeEndOfWord(root))
      {
          str[level] = '\0';
          printf("%s\n", str);
      }

      int i;
      for (i = 0; i < 26; i++)
      {
          // if NON NULL child is found
          // add parent key to str and
          // call the display function recursively
          // for child node
          if (root->children[i])
          {
              str[level] = i + 'a';
              display(root->children[i], str, level + 1);
          }
      }
  }

*/
//Function to determine if a given string is a prefix to any word
  bool isTriePrefix(char *word, TrieNode *root){
    //printf("called isTriePrefix\n");
    TrieNode *currentNode = root;
    int length = strlen(word);
    int index = 0;
    int level = 0;
    bool suffixFound = false;
      if(strcmp(word, "") == 0 || length == 0){
        printf("word is empty, returning false\n");
        return false;
      }
      //first, walk to the end of the word, if at any point the word is not in the trie, return false
      for (level = 0; level < length; level++){
        index = charToIndex(word[level]);
        //printf("%c", word[level]);
        if(currentNode->children[index] == NULL){
          printf("word is %s, child at level %d is empty, char %c %c mismatch, returning false\n", word, level, word[level], currentNode->key);
          return false;
        }
        currentNode = currentNode->children[index];
      }
/*
        index = charToIndex(word[level]);
      if(currentNode->children[index] == NULL){
      printf("next child is empty, returning false\n");
      return false;
      }
      printf("\n");
      */
      printf("word is %s, current letter is %c\n", word, currentNode->key);
      for(int a=0; a<26; a++){
        if(currentNode->children[a] != NULL){
          suffixFound = true;

        }
      }
      return suffixFound;

    }
