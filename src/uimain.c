#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tokenizer.h"
#include "history.h"

int main()
{
  char* histo;
  char** toks;
    // This is to initiate the history of the tokenizer, so we can keep track of it
  List* hist = init_history();
  puts("Welcome! To Jesus Lopez Tokenizer");

  while(1){
    
    fputs("Insert string,h(history),q(quit) or ! for a specific history\n>", stdout);
    fflush(stdout);
    char k[1000];
    fgets(k, 1000, stdin);
    fflush(stdout);
      
    k[strcspn(k, "\n")] = '\0';

    //this is for tokenizing the word and we are going to assign it to the pointer of chars
    // that we previously declared
    toks = tokenize(k);
    //we are going to print the token with the function print_tokens()
    print_tokens(toks);
    //then free it
    free_tokens(toks);
     
    switch(k[0]){
        // case for quitting 
      case 'q':
	       printf("Bye!\n");
	       return 0;
        // case for gathering the history
      case 'h':
	       print_history(hist);
	       break;
      case '!':
           histo = get_history(hist, atoi(k + 1));
           if(histo != NULL){
           toks = tokenize(histo);
           printf("History %s\n", histo);
           printf("Tokenized hist: \n");
           print_tokens(toks);

	}
	else{
	  printf("Invalid history index \n");
	}
	break;
    default:
      add_history(hist, k);
      
    }
    
  }
  // free_tokens(toks);
  free_history(hist);
  return 0;
}
