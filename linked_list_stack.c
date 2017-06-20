#include <stdio.h>
#include <stdlib.h>

struct node_s {
	char data_s;
	struct node *next_s;
};

typedef struct node_s Node;
typedef Node *Node_P;
typedef Node_P *Stack;

Stack stackCreate() {
	/*allocate memmory for stack and return the reference initially null*/

	Stack stack = malloc(sizeof(Stack));
	*stack = NULL;

	return stack;
}

void stackDestroy(Stack stack) {
	/*free the stack and null the reference to it*/


}

int stackIsEmpty(Stack stack) {
	/*if stack is empty (no data inside) return 1 otherwise return 0*/
	
	if (stack) {
		return 0;
	}
	return 1;
}

int stackPush(Stack stack, char data) {
	/*push the data element input with arg data. if the push success will return 0 otherwise -1*/

	Node_P node_p = malloc(sizeof(Node));

	if (node_p)	{
		node_p -> data_s = data;
		node_p -> next_s = stack;
		stack = *node_p;

		return 0;
	}

	return -1;
}

int stackPop(Stack stack, char *data) {
	/*pass the pop value to the input arg *data of the function if the pop is success
	  function will return 0 otherwise -1 anda data will be null*/

	if (stackIsEmpty(stack)) {
		*data = '\0';
		return -1;
	}
	*data = 
}

char stackPeek(Stack stack) {
	/*return the copy of the top element of the stack. if there is no element to return will return null*/
	
	
}

int main() {
	
}