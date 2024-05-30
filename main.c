#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct StackNode {
    int data;
    struct StackNode *nextStackNode;
} StackNode;

typedef struct Stack {
    StackNode *top;
} Stack;

StackNode *createStackNode(int data);

Stack *createStack();

void push(Stack *stack, int data);

int pop(Stack *stack);

int peek(Stack *stack);

StackNode *createStackNode(int data) {
    StackNode *newStackNode = (StackNode *) malloc(sizeof(StackNode));
    if (newStackNode == NULL) {
        printf("Failed to allocate memory in createStackNode().\n");
        exit(EXIT_FAILURE);
    }
    newStackNode->data = data;
    newStackNode->nextStackNode = NULL;
    return newStackNode;
}

Stack *createStack() {
    Stack *stack = (Stack *) malloc(sizeof(Stack));
    if (stack == NULL) {
        printf("Failed to allocate memory in createStack().\n");
        exit(EXIT_FAILURE);
    }
    stack->top = NULL;
    return stack;
}

void push(Stack *stack, int data) {
    if (stack == NULL) {
        printf("Stack pointer is null.\n");
        return;
    }
    StackNode *newStackNode = createStackNode(data);
    newStackNode->nextStackNode = stack->top;
    stack->top = newStackNode;
    printf("%d pushed into stack.\n", data);
}

int pop(Stack *stack) {
    if (stack == NULL) {
        printf("Stack pointer is null.\n");
        return INT_MIN;
    }
    if (stack->top == NULL) {
        printf("Stack underflow.\n");
        return INT_MIN;
    }

    StackNode *temporaryNode = stack->top;
    stack->top = stack->top->nextStackNode;
    int poppedData = temporaryNode->data;
    free(temporaryNode);

    return poppedData;
}

int peek(Stack *stack) {
    if (stack == NULL) {
        printf("Stack pointer is null.\n");
        return INT_MIN;
    }
    if (stack->top == NULL) {
        printf("Stack is empty.\n");
        return INT_MIN;
    }
    return stack->top->data;
}
int main(void) {
    Stack *stack = createStack();
    push(stack, 11);
    push(stack, 22);
    push(stack, 33);

    printf("%d popped from stack.\n", pop(stack));
    printf("%d popped from stack.\n", pop(stack));
    printf("%d popped from stack.\n", pop(stack));
    printf("%d popped from stack.\n", pop(stack));

    push(stack, 44);
    printf("Top element is %d.\n", peek(stack));

    return 0;
}
