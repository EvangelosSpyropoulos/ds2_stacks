#include "stack.h"
#include <stdio.h>

void pushPrompt(Stack* stack);
void popPrompt(Stack* stack);

int main() {
    Stack first = init();
    Stack second = init();

    int ch;
    
    do {
        printf("Options:\n"
        "1 Push to the 1st stack.\n"
        "2 Pop from the 1st stack.\n"
        "3 Push to the 2nd stack.\n"
        "4 Pop from the 1st stack.\n"
        "5 Transfer the 1st stack's elements to the 2nd\n"
        "6 Copy the 1st stack's elements to the 2nd\n"
        "0 Exit\n\n");
        scanf("%d", &ch);
        switch(ch) {
            case 1:
                pushPrompt(&first);
                break;
            case 2:
                popPrompt(&first);
                break;
            case 3:
                pushPrompt(&second);
                break;
            case 4:
                popPrompt(&second);
                break;
            case 5:
                transferElements(&first, &second);
                printf("Elements transferred.\n");
                break;
            case 6:
                copyElements(&first, &second);
                printf("Elements copied.\n");
                break;
            case 0:
                freeResources(&first);
                freeResources(&second);
                break;
            default:
                break;
        }
        printf("\n");
    } while (ch != 0);

    return 0;
}

void pushPrompt(Stack* stack) {
    int elem;
    printf("Integer to push: ");
    scanf("%d", &elem);
    push(stack, elem);
}

void popPrompt(Stack* stack) {
    int elem = pop(stack);
    printf("Popped element: %d\n", elem);
}