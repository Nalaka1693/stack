#include <stdio.h>
#include <stdlib.h>

#define SIZE 100

typedef struct {
	int size;
	int top;
	char *array;
} Stack;

Stack *stackCreate() {
	/*allocate memmory for stack struct and for the array, 
	  can create a desired sized stack by giving input arg int size and assign it to stack -> size*/

	Stack *stack = malloc(sizeof(Stack));
	
	stack -> size = SIZE;
	stack -> top = stack -> size - 1;
	stack -> array = (char *) malloc(sizeof(char) * stack -> size);
	
	return stack;
}

void stackDestroy(Stack *stack) {
	/*free the stack and null the reference to it*/

	free(stack -> array);
	stack = NULL;
	free(stack);	
}

int stackIsEmpty(Stack *stack) {
	/*if stack is empty (no data inside) return 1 otherwise return 0*/

	if(stack -> size - 1 == (stack -> top)) {
		return 1;
	}
	return 0;
}

int stackIsFull(Stack *stack) {
	/*check whether the stack is full. if true return 1 otherwise 0*/

	if(stack -> top == 0) {
		return 1;
	}
	return 0;
}

int stackPush(Stack *stack, char data) {
	/*push the data element input with arg data. if the push success will return 0 otherwise -1*/

	if(!stackIsFull(stack)) {		
		(stack -> array)[stack -> top] = data;		
		stack -> top --;
		
		return 0;
	}
	return -1;	
}

int stackPop(Stack *stack, char *data) {
	/*pass the pop value to the input arg *data of the function if the pop is success
	  function will return 0 otherwise -1 anda data will be null*/

	if (!stackIsEmpty(stack)) {
		*data = (stack -> array)[stack -> top + 1];
		(stack -> array)[stack -> top + 1] = '\0';
		stack -> top ++;

		return 0;
	}
	
	*data = '\0';
	return -1;
}

char stackPeek(Stack *stack) {
	/*return the copy of the top element of the stack. if there is no element to return will return null*/
	
	if (stackIsEmpty(stack)) {
		return '\0';
	} else if (stackIsFull(stack)) {
		return (stack -> array)[stack -> top + 1];
	} else {
		return (stack -> array)[stack -> top];
	}
}

int main() {
	char input[256] = {};
	Stack *stack1 = stackCreate();
	
	printf("Enter a String: ");
	fgets(input, 256, stdin);
	int i = 0;
	while (input[i] != '\n') {
		stackPush(stack1, input[i]);
		i++;
	}
	
	printf("Reversed string: ");
	while (!stackIsEmpty(stack1)) {
		char val;
		stackPop(stack1, &val);
		printf("%c", val);
	} printf("\n");
	
	stackDestroy(stack1);
	
	return 0;	
}