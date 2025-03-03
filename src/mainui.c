#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"
#include "history.h"


// Function to display the menu

void menu() {

  putchar('\n');
  fputs("Select what you want to do now!\n", stdout);
  fputs("c = continue and use the tokenizer\n", stdout);
  fputs("h = print history\n", stdout);
  fputs("f = free tokens\n", stdout);
  fputs("q = quit\n", stdout);
  fflush(stdout);
}


int main() {

  char givenStr[100];
  char **tokens = NULL;
  List *history = init_history();
  int c;

  puts("Welcome to the Tokenizer!");

  while (1) {
    menu();
    while ((c = getchar()) == '\n'); // Skip newline characters
    if (c == EOF)
      goto done;

    // Take answer and do what is expected

    switch (c) {

    case 'c':

      puts ("You chose to use the Tokenizer! Please give a string:");
      if (scanf(" %[^\n]", givenStr) != 1) {
	printf ("Failed to read input.\n");
	continue;
      }

      if (tokens != NULL) {
	printf ("Previous tokens are still allocated. Freeing them first...\n");
	free_tokens(tokens);
      }
      tokens = tokenize(givenStr);
      printf ("Tokens:\n");
      print_tokens(tokens);
      add_history (history, givenStr);  // Add the string to history
      break;

    case 'h':
      
      puts("History:");
      print_history(history);  // Print the history
      break;

    case 'f':

      if (tokens != NULL) {
	puts ("You chose to free the tokens.");
	free_tokens(tokens);
	tokens = NULL;
	free_history(history);

      } else {

	puts ("No tokens to free!");

      }

      break;

    case 'q':

      puts("Thank you for using the Tokenizer!");
      puts("See you next time!");
      goto done;

    case '\n':

      break;

    default:

      printf("Invalid input submitted '%c', please choose c, h, f, or q.\n", c);
      while (getchar() != '\n'); // Clear the input buffer

    }

  }


 done: // Ending program

  if (tokens != NULL) {
    free_tokens(tokens);

  }
  
  free_history(history); // Free the history list

  return 0;

}

