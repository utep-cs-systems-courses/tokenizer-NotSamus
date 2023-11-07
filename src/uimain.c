#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tokenizer.h"
#include "history.h"

int main()
{
  char* histo;
  char** toks;
    
  List* hist = init_history();
  puts("Welcome! To Jesus Lopez Tokenizer");

  while(1){
    
    fputs("Insert string,h(history),q(quit) or ! for a specific history\n>", stdout);
    fflush(stdout);
    char k[1000];
    fgets(k, 1000, stdin);
    fflush(stdout);
      
    k[strcspn(k, "\n")] = '\0';

    toks = tokenize(k);
    print_tokens(toks);
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
  free_history(hist);
  return 0;
}
