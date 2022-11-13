#ifndef STACK_H
#define STACK_H

typedef struct Node {
    struct Node* last;
    int data;
} Node;

typedef struct Stack {
    Node* top;
} Stack;

Stack init();
void push(Stack* stack, const int elem);
int pop(Stack* stack);
void transferElements(Stack* origin, Stack* dest);
void copyElements(Stack* origin, Stack* dest);
void freeResources(Stack* stack);

#endif