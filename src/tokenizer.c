#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"

// FIRST IMPLEMENTATIONS ATTEMPT //

// Return TRUE if c is a whitespace ('\t' or ' '). Zero terminators are not printable (FALSE) //
int space_char(char c)
{
  return (c == ' ' || c == '\t');
}

// Return TRUE if c is a non-whitespace character ('\t' or ' '). Zero are not printable //
int non_space_char(char c)
{
  return (!space_char(c) && c != '\0');
}

// Returns POINTER to to first character of the next space-separated token in zero-terminated str//
char *token_start(char *str)
{
  while (*str != '\0' && space_char(*str)) {
    str++;
  }
  return str;
}

// Returns a pointer terminator char following *token * //
char *token_terminator(char *token)
{
  while(non_space_char(*token)){
    token++;
  }
  return token;
}

// Counts number of tokens in the argument //
int count_tokens(char *str)
{
  int count = 0;
  char *s = token_start(str);
  while (*s != '\0') {
    count++;
    s = token_start(token_terminator(s));
  }
  return count;

}

// Returns a fresly allocate a new zero-terminated string containing <len> chars from <inSrt> //
char *copy_str(char *intStr, short len)
{
  int i;
  char *copy = (char*)malloc((len+1)*sizeof(char));
  for (i = 0; i < len; i++) {
    * (copy +i) =* (intStr + i);
  }
  *(copy+i) = '\0';
  return copy;
}

// Return a freshly allocated zero-terminated vector of freshly allocated space-separated tokens from zero-terminated str. //
char **tokenize(char* str)
{
  int stringNum = count_tokens(str);
  char *t = str;
  char **c = malloc((stringNum + 1) * sizeof(char *));

  for (int i = 0; i < stringNum; i++) {
    t = token_start(t);
    char *over = token_terminator(t);
    int length = over - t;
    
    c[i] = copy_str(t, length);
    t = token_terminator(t);
  }
  
    c[stringNum] = NULL;
    return c;
}

// Prints all tokens //
void print_tokens(char **tokens)
{
  int i;
  for (i = 0; tokens[i] != 0; i++) {
    printf("%s\n", tokens[i]);
  }
}

// Frees all tokens and the vector containing them. //
void free_tokens(char **tokens)
{
  short len = 0;
  int i;
  for (i = 0; tokens[i] != 0; i++) {
    free(tokens[i]);
  }
  free(tokens);
}
