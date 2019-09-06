
#include "Portfolio.h"
//Functions to get user input and do error checking.
//These are intended to keep a user from entering bad input.

//Function to get the size of the Boggle Board
int getBoggleSize(void){
printf("What size Boggle would you like to play? (integers only): \n");
printf("(Warning:: Board sizes larger than 40 will be difficult to read.\n Board sizes larger than 100,000 may run out of heap or crash your computer. Proceed with caution)\n");
int size = 1;
bool validInput = false;
char userInput[200];

processUserInput(userInput, 200); //get the userInput
if(atoi(userInput) > 1 ){ //make sure the size is reasonable
  size = atoi(userInput);
  validInput = true;
  return size;
}
else{
  validInput = false;
}
while(!validInput){ // if the size is not reasonable, ask the user to try again
  printf("Error! Invalid Board size. Please try again.\n");
  processUserInput(userInput, 200);
  if(atoi(userInput) > 1){
    size = atoi(userInput);
    validInput = true;
    return size;
  }
}
return 0;
}

//Function to get the seed for the rng of the board
int getBoggleSeed(void){
  printf("Enter a seed (integers only): ");
  int seed = 0;
  bool validInput = false;
  char userInput[200];

  processUserInput(userInput, 200);//get the userInput
//make sure the seed is reasonable
//it is worth noting that a character sent to atoi() will result in a 0.
  if(atoi(userInput) > 0 ){
    seed = atoi(userInput);
    validInput = true;
    return seed;
  }
  else{
    validInput = false;
  }
  while(!validInput){ //if the seed is not reasonable, ask the user to try again
    printf("Error! Invalid Boggle seed. Please try again.\n");
    processUserInput(userInput, 200);
    if(atoi(userInput) > 0){
      seed = atoi(userInput);
      validInput = true;
      return seed;
    }
}

  return 0;
}
