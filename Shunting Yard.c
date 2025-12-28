#include <stdio.h>
#include <stdlib.h>
#define MAX 50
/* run this program using the console pauser or add your own getch, system("pause") or input loop */


char stack[MAX];
int top = -1;

// Stack functions
void push(char x) {
    stack[++top] = x;
}

char pop() {
    return stack[top--];
}

// Operator precedence
int priority(char x) {
    if (x == '+' || x == '-')
        return 1;
    if (x == '*' || x == '/')
        return 2;
    return 0;
}

int main(int argc, char *argv[]) {
   char infix[MAX], postfix[MAX];
    int i = 0, k = 0;
    char x;

    printf("Enter infix expression: ");
    scanf("%s", infix);

    while (infix[i] != '\0') {
        // If operand, add to postfix
        if (isalnum(infix[i])) {
            postfix[k++] = infix[i];
        }
        // If '(' push to stack
        else if (infix[i] == '(') {
            push(infix[i]);
        }
        // If ')', pop until '('
        else if (infix[i] == ')') {
            while ((x = pop()) != '(')
                postfix[k++] = x;
        }
        // Operator
        else {
            while (top != -1 && priority(stack[top]) >= priority(infix[i])) {
                postfix[k++] = pop();
            }
            push(infix[i]);
        }
        i++;
    }

    // Pop remaining operators
    while (top != -1)
        postfix[k++] = pop();

    postfix[k] = '\0';

    printf("Postfix expression: %s\n", postfix);

	return 0;
}
