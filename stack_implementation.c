#include <gtk/gtk.h>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <stdbool.h>
#include <string.h>
#include "stack_implementation.h"
struct stack_t *newStack(void)
{
  struct stack_t *stack = malloc(sizeof *stack);
  if (stack)
  {
    stack->head = NULL;
    stack->stackSize = 0;
  }
  return stack;
};
char *copyString(char *str)
{
  char *tmp = malloc(strlen(str) + 1);
  if (tmp)
    strcpy(tmp, str);
  return tmp;
}

/* Push a value onto the stack */
void push(struct stack_t *theStack, char *value)
{
  struct stack_entry *entry = malloc(sizeof *entry);
  if (entry)
  {
    entry->data = copyString(value);
    entry->next = theStack->head;
    theStack->head = entry;
    theStack->stackSize++;
  }
  else
  {
    // handle error here
    printf("stack full\n");
  }
}

/* Get the value at the top of the stack*/
char *top(struct stack_t *theStack)
{
  if (theStack && theStack->head)
    return theStack->head->data;
  else
    return NULL;
}
/*Returns pointer to the top of element*/
void * stackpointer(struct stack_t *theStack)
{
  if (theStack && theStack->head)
    return theStack->head;
  else
    return NULL;
}

/* Pop the top element from the stack*/
char* pop(struct stack_t *theStack)
{
  if (theStack->head != NULL)
  {
    struct stack_entry *tmp = theStack->head;
    theStack->head = theStack->head->next;
	return theStack->head->data;
    free(tmp->data);
    free(tmp);
    theStack->stackSize--;
  }
}

