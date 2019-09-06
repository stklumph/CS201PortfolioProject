
#include "Portfolio.h"
//This function returns the appropriate score depending on the length of a word
int getWordScore(unsigned int wordLength){
if(wordLength <= 4){
  return 1;
}
else if(wordLength == 5){
  return 2;
}
else if(wordLength == 6){
  return 3;
}
else if(wordLength == 7){
  return 4;
}
else if(wordLength >= 8){
  return 11;
}
else {printf("ERROR: wordlength not defined.\n");}

return 0;
}
