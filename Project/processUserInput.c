char *processUserInput(char *input, int maxSizeOfInput){

if(fgets(input, maxSizeOfInput, stdin) != NULL){
//DEBUG:
//int len = strlen(input);
//printf("Strlen is : %d\n", len);
if(input[strlen(input) - 1] != '\n'){
  int numberOver =0;
  while(fgetc(stdin) != '\n'){
    numberOver++;
  }
  printf("The input you entered was %d characters too long. Please only give valid input.\n", numberOver);
}
if(strlen(input) < maxSizeOfInput){
  input[strlen(input) - 1] = '\0';
}
return input;

}
return NULL;
}
