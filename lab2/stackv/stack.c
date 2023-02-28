#include "stack.h"
#include <stdio.h>
#include <stdlib.h>


Stack *stack_new(){
	return (Stack *)calloc(1,sizeof(Stack));
}

void stack_delete(Stack *stack){
	free(stack->data);
}

int stack_push(Stack *stack, int data){
	if(stack->size == 79){
		printf("Переполнение стека");
		return 1;
	}
	stack->data[stack->size] = data;
	stack->size++;
	return 0;
}

int stack_pop(Stack *stack, int *output){
	if(stack->size == 0){
		return 1;
	}
	stack->size--;
	*output = stack->data[stack->size];
	return 0;
}

void stack_print(const Stack *stack){
	int i;
	int len = stack->size - 1;
	printf("Stack -> ");
	for (i = len; i > 0; i--){
		printf("%d",stack->data[i]);
		printf(" | ");
	}
	if(stack->size != 0){
		printf("%d", stack->data[i]);
	}
	printf("\n");
}
