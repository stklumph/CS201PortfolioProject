#ifndef HASHTABLE_H
#define HASHTABLE_H

  char **newHashTable(int size);
  unsigned int hashFunction(char *str, int size);
  void insertToHashTable(char **hashTable, char *word, int size);
  char *searchHashTable(char **hashTable, char *word, int size);
  bool isInHashTable(char **hashTable, char *word, int size);

#endif
