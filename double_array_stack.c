#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

typedef struct {
	int size;
	int top_a;
	int top_b;
	char *array;
} Stack;

Stack *stackCreate() {
	/*allocate memmory for stack struct and for the array, 
	  can create a desired sized stack by giving input arg int size and assign it to stack -> size*/

	Stack *stack = malloc(sizeof(Stack));
	
	stack -> size = SIZE;
	stack -> top_a = 0;
	stack -> top_b = stack -> size - 1;
	stack -> array = (char *) malloc(sizeof(char) * stack -> size);
	
	return stack;
}

void stackDestroy(Stack *stack) {
	/*free the stack and null the reference to it*/

	free(stack -> array);
	free(stack);
	stack = NULL;
}

int stackIsEmpty(Stack *stack, int stack_num) {
	/*if stack is empty (no data inside) return 1 otherwise retrun 0
	  second input arg to select whicha stack*/

	if(stack_num == 1) {
		if (stack -> top_a == 0) {
			return 1;
		}
	} else if (stack_num == 2) {
		if (stack -> top_b == stack -> size - 1) {
			return 1;
		}
	} else {
		printf("Select stack 1 or 2 by giving the third argument\n");
	}
	return 0;
}

int stackIsFull(Stack *stack) {
	/*check whether the stack is full. if true retrn 1 otherwise 0*/

	if(stack -> top_b - stack -> top_a == -1 || stack -> top_a == stack -> size - 1 || stack -> top_b == 0) {
		return 1;
	}
	return 0;
}

int stackPush(Stack *stack, char data, int stack_num) {
	/*push the data element input with arg data. if the push success will return 0 otherwise -1
	  thrid input arg to select which stack*/

	if(!stackIsFull(stack)) {
		if (stack_num == 1) {			
			(stack -> array)[stack -> top_a] = data;
			stack -> top_a ++;

		} else if (stack_num == 2) {
			
			(stack -> array)[stack -> top_b] = data;
			stack -> top_b --;
		} else {
			printf("Select stack 1 or 2 by giving the third argument\n");
			return -1;
		}

		return 0;
	}
	return -1;
}

int stackPop(Stack *stack, char *data, int stack_num) {
	/*pass the pop value to the input arg *data of the function if the pop is success
	  function will return 0 otherwise -1 anda data will be null
	  third input arg to select whicha stack*/

	if (stack_num == 1) {
		if (!stackIsEmpty(stack, 1)) {
			*data = (stack -> array)[stack -> top_a - 1];
			(stack -> array)[stack -> top_a - 1] = '\0';
			stack -> top_a --;
			return 0;
		}			
		

	} else if (stack_num == 2) {
		if (!stackIsEmpty(stack, 2)) {
			*data = (stack -> array)[stack -> top_b + 1];
			(stack -> array)[stack -> top_b + 1] = '\0';
			stack -> top_b ++;
			return 0;
		}		

	} else {
		printf("Select stack 1 or 2 by giving the third argument\n");
		return -1;
	}

	*data = '\0';
	return -1;
}

char stackPeek(Stack *stack, int stack_num) {
	/*return the copy of the top element of the stack. if there is no element to return will retrun null
	  second input arg to select whicha stack*/

	if (stackIsFull(stack)) {
		if (stack_num == 1) {
			return (stack -> array)[stack -> top_a - 1];			
		} else if (stack_num == 2) {
			return (stack -> array)[stack -> top_b + 1];
		} else {
			printf("Select stack 1 or 2 by giving the third argument\n");
			return '\0';
		}
	} else {
		if (stack_num == 1) {
			if (stackIsEmpty(stack, 1)) {
				return '\0';
			}
			return (stack -> array)[stack -> top_a - 1];
		} else if (stack_num == 2) {
			if (stackIsEmpty(stack, 2)) {
				return '\0';
			}
			return (stack -> array)[stack -> top_b + 1];
		} else {
			printf("Select stack 1 or 2 by giving the third argument\n");
			return '\0';
		}
	}
}

int main() {
	int i = 0;
	Stack *stack1 = stackCreate();
	
	stackPush(stack1, '0', 1);
	stackPush(stack1, 'a', 2);
	stackPush(stack1, '1', 1);
	stackPush(stack1, 'b', 2);
	stackPush(stack1, '2', 1);
	stackPush(stack1, 'c', 2);
	stackPush(stack1, '3', 1);
	stackPush(stack1, 'd', 2);
	stackPush(stack1, '4', 1);
	stackPush(stack1, 'e', 2);

	/*Illustration of how data is in the array stack*/
	for (i = 0; i < SIZE; i++) {
		printf("array[%d] = %c\n", i, (stack1 -> array)[i]);
	}
	char val = 'z';
	printf("peek in stack  = %c\n", stackPeek(stack1, 1));
	printf("peek in stack  = %c\n", stackPeek(stack1, 2));
	
	printf("stack return value = %d", stackPop(stack1, &val, 1)); printf(" val1 = %c\n", val); printf("peek in stack 1 = %c\n", stackPeek(stack1, 1));
	printf("stack return value = %d", stackPop(stack1, &val, 1)); printf(" val2 = %c\n", val); printf("peek in stack 2 = %c\n", stackPeek(stack1, 2));
	printf("stack return value = %d", stackPop(stack1, &val, 1)); printf(" val1 = %c\n", val); printf("peek in stack 1 = %c\n", stackPeek(stack1, 1));
	printf("stack return value = %d", stackPop(stack1, &val, 1)); printf(" val2 = %c\n", val); printf("peek in stack 2 = %c\n", stackPeek(stack1, 2));
	printf("stack return value = %d", stackPop(stack1, &val, 2)); printf(" val1 = %c\n", val); printf("peek in stack 1 = %c\n", stackPeek(stack1, 1));
	printf("stack return value = %d", stackPop(stack1, &val, 2)); printf(" val2 = %c\n", val); printf("peek in stack 2 = %c\n", stackPeek(stack1, 2));
	printf("stack return value = %d", stackPop(stack1, &val, 2)); printf(" val2 = %c\n", val); printf("peek in stack 2 = %c\n", stackPeek(stack1, 2));
	printf("stack return value = %d", stackPop(stack1, &val, 1)); printf(" val1 = %c\n", val); printf("peek in stack 1 = %c\n", stackPeek(stack1, 1));
	printf("stack return value = %d", stackPop(stack1, &val, 2)); printf(" val2 = %c\n", val); printf("peek in stack 2 = %c\n", stackPeek(stack1, 2));
	printf("stack return value = %d", stackPop(stack1, &val, 1)); printf(" val1 = %c\n", val); printf("peek in stack 1 = %c\n", stackPeek(stack1, 1));
	printf("stack return value = %d", stackPop(stack1, &val, 2)); printf(" val2 = %c\n", val); printf("peek in stack 2 = %c\n", stackPeek(stack1, 2));
	printf("stack return value = %d", stackPop(stack1, &val, 1)); printf(" val1 = %c\n", val); printf("peek in stack 1 = %c\n", stackPeek(stack1, 1));
	printf("stack return value = %d", stackPop(stack1, &val, 2)); printf(" val2 = %c\n", val); printf("peek in stack 2 = %c\n", stackPeek(stack1, 2));
	
	stackDestroy(stack1);
	
	return 0;	
}