#ifndef LAB2_STACKV_H
#define LAB2_STACKV_H

typedef struct Stack{
	int data[80];
	int size;
}Stack;


Stack *stack_new();

void stack_delete(Stack *stack);

int stack_push(Stack *stack, int data);

int stack_pop(Stack *stack, int *output);

void stack_print(const Stack *stack);

#endif
