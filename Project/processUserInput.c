//Function to process userInput and avoid overflow and making sure that the input gets cleared

char *processUserInput(char *input, int maxSizeOfInput){

if(fgets(input, maxSizeOfInput, stdin) != NULL){ //first, make sure there is input
//if the end of the string is not a newline character, then it must not be the end of input
if(input[strlen(input) - 1] != '\n'){
  int numberOver = 0;
  while(fgetc(stdin) != '\n'){ //clear the inupt by running through every character
      numberOver++; //count up the number of characters over the limit
    }
    //inform the user the input was bad
    printf("The input you entered was %d characters too long. Please only give valid input.\n", numberOver);
  }
//attach a null character to the end of the input
if(strlen(input) < maxSizeOfInput){
    input[strlen(input) - 1] = '\0';
  }
return input;
}

return NULL;
}
