#include "stack.h"

struct double_stack * double_stack_new(int max_size) { /* creates a new double_stack struct and initializes its members */
    struct double_stack * stack; /* declares a pointer stack to a double_stack struct */
    stack = malloc(sizeof(struct double_stack)); /* allocates memory for the size of the double_stack */

    stack -> top = 0; /* initializes the top index to 0, indicating that the stack is initially empty */
    stack -> max_size = max_size; /* sets the max size of the stack to a specified value */
    stack -> items = malloc(sizeof(double) * max_size); /* allocates memory for the items array with a size sufficient to hold max_size double values (values are doubles, int max_size represents how many doubles)*/

    return stack; /* returns the pointer to the newly created double_stack struct */
}

// push a value onto the stack
void double_stack_push(struct double_stack * this, double value) { /* this is a pointer to double_stack where push is performed */
    this -> items[ this -> top ] = value; /* items refers to the value at the top of the stack, so value is placed at the index indicated by top index*/
    this -> top ++; /* refers to the top member of the double_stack struct pointed to by this pointer */
}

// pop a value from the stack
double double_stack_pop(struct double_stack * this) {
   this -> top --;
   return this -> items[ this -> top ]; 
}
