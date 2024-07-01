#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"

int main()
{
  // Variables
  char givenStr[100];
  
  puts ("WELCOME TO THE TESTING UI");

  //  while (1) {    // Infinite while loop
  printf("We are testing making a UI to have fun, a fancy one!");
  putchar('\n');
  char string[100];
  printf("Give me some Strings: ");
  putchar('\n');
  fgets(string, sizeof(string),stdin); //reading the input

  // Attempt to save Strings/chars
  int s = 0;
  while (string[s] != '\0') {
    givenStr[s] = string[s];
    s++;
  }
  givenStr[s] = '\0';
  
  printf("You submited: %s", givenStr);
  // }
  // Testing new things. Lets see what happens //
  printf ("Now lets attempt to test some newly added functions: \n ");
  printf ("Testing space_char: \n ");
  for (int t = 0; givenStr[t] != '\0'; t++) {
    if(space_char(givenStr[t])) {
      printf ("Character '%c'. \n Position %d is a space or tab. \n", givenStr[t],t);
    }
  }
  printf("Now lets test non_space_char: \n ");
  for (int t = 0; givenStr[t] != '\0'; t++) {
    if(non_space_char(givenStr[t]!= ' ')){
      printf ("Character '%c'. \n Position %d is NOT a space or tab. \n", givenStr[t], t);
   }
  }
  printf( "Now lets try to know the start AND finish");
  char *st = token_start(givenStr);
  while (*st != '\0') {
    char *en = token_terminator(st);
    printf ("Token Start is: ''%c', End: '%c' \n", *st, *(en-1));
    st = token_start(en);
  }
    printf ("Now lets try to count: \n");
    // for (int t = 0; givenStr[t] != '\0;' t++) {
    int count = count_tokens(givenStr);
    printf ("The number of WORDS in this string are: %d \n", count);

     char **tokens = tokenize(givenStr);
     printf ("Now lets tokenize the string");
     putchar ('\n');
    for (int i = 0; tokens[i] != NULL; i++) {
      printf ("Token[%d]: %s\n", i, tokens[i]);
      putchar ('\n');
       free(tokens[i]);
}
    free(tokens);
    return 0;

    printf ("Now lets test Printing the tokens");
      putchar ('\n');
    print_tokens(tokens);
    putchar ('\n');
    
    printf ("Now lets test Free tokens");
    free_tokens(tokens);

    printf ("Leaving Testing, trying to implement the real thing!", '\n');

    return 0;

    //    void menu()
    //{
    // printf{"Welcome to this pretty little Tokenizer", '\n');
      
    //}
}
