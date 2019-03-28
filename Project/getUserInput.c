
int getBoggleSize(void){
printf("What size Boggle would you like to play? (integers only): \n");
printf("(Warning:: Board sizes larger than 40x40 will be difficult to read.)\n");
int size = 1;
bool validInput = false;
char userInput[200];

processUserInput(userInput, 200);
if(atoi(userInput) > 1 ){
  size = atoi(userInput);
  validInput = true;
  return size;
}
else{
  validInput = false;
}
while(!validInput){
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

int getBoggleSeed(void){
  printf("Enter a seed (integers only): ");
  int seed = 0;
  bool validInput = false;
  char userInput[200];
    processUserInput(userInput, 200);

  if(atoi(userInput) > 0 ){
    seed = atoi(userInput);
    validInput = true;
    return seed;
  }
  else{
    validInput = false;
  }
  while(!validInput){
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
