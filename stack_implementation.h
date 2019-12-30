struct stack_entry {
  char *data;
  struct stack_entry *next;
};

struct stack_t{
  struct stack_entry *head;
  size_t stackSize;  
};

/*Create a new stack instance*/


char *copyString(char *str);

void push(struct stack_t *theStack, char *value);

char *top(struct stack_t *theStack);

void * stackpointer(struct stack_t *theStack);

char* pop(struct stack_t *theStack);
