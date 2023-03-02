#include <stdio.h>
#include <stdlib.h>
#include "stackv/stack.h"
#include <string.h>
#include <ctype.h>

char *Readline(){
	char *ptr = (char *)malloc(1);
	char buf[81];
	int n, len = 0;
	*ptr = '\0';
	do{
		n = scanf("%80[^\n]",buf);
		if (n<0){
			free(ptr);
			ptr = NULL;
			continue;
		}
		if (n==0){
			scanf("%*c");
		}
		else{
			len += strlen(buf);
			ptr = (char *)realloc(ptr, len+1);
			strcat(ptr, buf);
		}
	}while(n>0);
	return ptr;
}

int main(){
	Stack *stack = stack_new();
	char *expression;
	int data1, data2;
	printf("Введите выражение в префиксной форме без пробелов ---> ");
	expression = Readline();
	int len = strlen(expression);
	for (int i = len - 1; i >= 0; i--){
		if(isdigit(expression[i])){
			stack_push(stack, expression[i]-'0');
		}
		if(expression[i]=='+'){
			stack_pop(stack,&data1);
			stack_pop(stack,&data2);
			stack_push(stack, data1 + data2);
		}
		if(expression[i]=='-'){
			stack_pop(stack,&data1);
			stack_pop(stack,&data2);
			stack_push(stack, data1 - data2);
		}
		if(expression[i]=='*'){
			stack_pop(stack,&data1);
			stack_pop(stack,&data2);
			stack_push(stack, data1 * data2);
		}
		if(expression[i]=='/'){
			stack_pop(stack,&data1);
			stack_pop(stack,&data2);
			stack_push(stack, data1 / data2);
		}
		if(expression[i]!= '/' &&  expression[i]!= '*' && expression[i]!='-' && expression[i]!='+' && !(isdigit(expression[i]))){
			printf("Wrong input\n");
			return 1;
		}
		stack_print(stack);
	}
	stack_pop(stack, &data1);
	printf("%s = %d\n", expression, data1);
	stack_delete(stack);
	free(expression);
	return 0;
}
