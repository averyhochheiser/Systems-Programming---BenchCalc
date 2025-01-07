#include "postfix.h" 
#include <math.h>
#include <ctype.h>

// evaluate expression stored as an array of string tokens
double evaluate_postfix_expression(char ** args, int nargs) { /* n is short for number (number of args) */
  struct double_stack * stack = double_stack_new(nargs);
  double result;

  for ( int i = 0; i < nargs; i ++ ) {
    
    if ( isdigit(args[i][0]) || isdigit(args[i][1])) {
      double value = atof(args[i]);
      double_stack_push(stack, value);
    } 
    else {
      double a = double_stack_pop(stack);
      double b = double_stack_pop(stack);

      if ( strcmp(args[i], "-") == 0) {
        result = b - a;
      } else if ( strcmp(args[i], "+") == 0 ) {
        result = a + b;
      } else if ( strcmp(args[i], "X") == 0 ) {
        result = a * b;
      } else if ( strcmp(args[i], "/") == 0 ) {
        result = b / a;
      } else if ( strcmp(args[i], "^") == 0 ) {
        result = pow(b, a);
      }
     double_stack_push(stack, result);
    }
  }
  return result;
}
