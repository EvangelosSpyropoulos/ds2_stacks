#include "stack.h"
#include <stdlib.h>
#include <stdio.h>

Stack init() {
    Stack stack = {NULL};
    return stack;
}

void push(Stack* stack, const int elem) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->last = stack->top;
    newNode->data = elem;
    stack->top = newNode;
}

int pop(Stack* stack) {
    if (!stack->top) {
        printf("Stack is empty. Invalid element returned.\n");
        return -1;
    }
    
    Node* topNode = stack->top;
    int elem = topNode->data;
    stack->top = topNode->last;
    free(topNode);
    return elem;
}

void transferElements(Stack* origin, Stack* dest) {
    int elem;
    while (origin->top) {
        elem = pop(origin);
        push(dest, elem);
    }
}

void copyElements(Stack* origin, Stack* dest) {
    freeResources(dest);
    Stack tmp = init();
    transferElements(origin, &tmp); 
    
    int elem;
    while (tmp.top) {
        elem = pop(&tmp);
        push(origin, elem);
        push(dest, elem);
    }
}

void freeResources(Stack* stack) {
    while (stack->top) {
        pop(stack);
    }
}