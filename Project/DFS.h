#ifndef DFS_H
#define DFS_H

  int withinBounds(char **Boggle, char *word, int Boardsize, int **visited, int x, int y, TrieNode *root);
  void dfs(char **Boggle, int Boardsize, TrieNode *dict, char **hashTable, char *word, int **visited, int x, int y, int depth, int hashSize);

#endif
