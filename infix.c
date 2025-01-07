#include "infix.h"
#include <math.h>
#include <stdbool.h>

// evaluate expression stored as an array of string tokens

double precedence ( char * token ) { 
  if ( strcmp(token, '(') == 0) {
    return 1;
  } else if ( strcmp(token, ')') == 0) {
    return 2;
  } else if ( strcmp(token, 'X') == 0) {
    return 3;
  } else if ( strcmp(token, '/') == 0) {
    return 4;
  } else if ( strcmp(token, '+') == 0) {
    return 5;
  } else if ( strcmp(token, '-') == 0) {
    return 6;
  }
}

char * pop_precedence ( double token ) {
  if ( token == 1 ) {
    return '(';
  } else if ( token == 2 ) {
    return ')';
  } else if ( token == 3 ) {
    return 'X';
  } else if ( token == 4 ) {
    return '/';
  } else if ( token == 5 ) {
    return '+';
  } else if ( token == 6 ) {
    return '-';
  }
}

char ** infix2postfix(char ** infix, int infix_length, int * return_length) {
  struct double_stack * stack = double_stack_new(infix_length);
  char ** postfix = malloc(sizeof(char*) * infix_length); // array of strings
  int postfix_length = 0; // number of tokens in converted postfix expression
  
  for ( int i = 0; i < infix_length; i ++ ) {
    double current_token_as_double = atof(infix[i]);
    if ( current_token_as_double != 0 || infix[i][0] == '0') { // good
      postfix[postfix_length] = infix[i]; 
      postfix_length ++; 
    } else if( strcmp(infix[i], "(") == 0 ) { // good
        double value = precedence(infix[i]);
        double_stack_push(stack, value);
    } else if ( infix[i][0] != ')') { // HELPPPPP
      double cmp_val_op = stack ->items[stack -> top];
      double cmp_val_tok = precedence(infix[i]);

        while (cmp_val_op > 2 && cmp_val_op < cmp_val_tok && stack -> top != 0) {
          double value = double_stack_pop(stack); 
          postfix[i] = pop_precedence(value); 

          cmp_val_op = stack ->items[stack -> top];
        }

      double value = precedence(infix[i]);
      double_stack_push(stack, value); 
    } else if ( strcmp(infix[i], ')') == 0 ) {
        double item = double_stack_pop(stack);
        
        while( precedence(infix[i]) != 1) {
            postfix[i] = pop_precedence(item);
            postfix_length ++;
            item = double_stack_pop(stack);
        }
      }
   }
  * return_length = postfix_length;
   printf("%f \n", postfix_length); // if doesn't print seg fault
  for ( int i = 0; i < postfix_length; i ++)  {
    printf("%s ", postfix[i]);
  }
  printf("\n");
  
  return postfix;
}

double evaluate_infix_expression(char ** args, int nargs) {
    int length = 0;
    char ** postfix = infix2postfix( args, nargs, &length ); 
    double result = evaluate_postfix_expression(postfix, length);

    return result; 
}



