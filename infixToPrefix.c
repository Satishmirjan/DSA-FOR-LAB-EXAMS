#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

char infix[100], prefix[100];

int priority(char symbol) {
    switch (symbol) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
        default:
            return 0;
    }
}

void infixtoprefix() {
    int start, end, i = 0, j = 0, top = -1;
    int stk[100];
    start = 0;
    end = strlen(infix) - 1;
    while (start < end) {
        char temp = infix[start];
        infix[start] = infix[end];
        infix[end] = temp;
        start++;
        end--;
    }

    for (i = 0; infix[i] != '\0'; i++) {
        char symbol = infix[i];
        if (isalnum(symbol)) {
            prefix[j++] = symbol;
        } else {
            if (symbol == ')') {
                stk[++top] = symbol;
            } else if (symbol == '(') {
                while (top != -1 && stk[top] != ')') {
                    prefix[j++] = stk[top--];
                }
                top--;
            } else {
                while (top != -1 && (priority(symbol) < priority(stk[top]))) {
                    prefix[j++] = stk[top--];
                }
                stk[++top] = symbol;
            }
        }
    }
    while (top != -1) {
        prefix[j++] = stk[top--];
    }
    prefix[j] = '\0';

    start = 0;
    end = strlen(prefix) - 1;
    while (start < end) {
        char temp = prefix[start];
        prefix[start] = prefix[end];
        prefix[end] = temp;
        start++;
        end--;
    }

    printf("Prefix expression: %s\n", prefix);
}

void evaluation() {
    float st[100];
    int top = -1;

    for (int i = strlen(prefix) - 1; i >= 0; i--) {
        char symbol = prefix[i];
        if (isalnum(symbol)) {
            st[++top] = symbol - '0';
        } else {
            float op1 = st[top--];
            float op2 = st[top--];
            float res;

            switch (symbol) {
                case '+':
                    res = op1 + op2;
                    st[++top] = res;
                    break;
                case '-':
                    res = op1 - op2;
                    st[++top] = res;
                    break;
                case '*':
                    res = op1 * op2;
                    st[++top] = res;
                    break;
                case '/':
                    res = op1 / op2;
                    st[++top] = res;
                    break;
                case '^':
                    res = pow(op1, op2);
                    st[++top] = res;
                    break;
            }
        }
    }
    printf("Result: %.2f\n", st[top]);
}

int main() {
    int choice;

    while (1) {
        printf("Enter the choice:\n");
        printf("1. Enter the infix expression\n");
        printf("2. Convert to prefix\n");
        printf("3. Evaluate prefix expression\n");
        printf("4. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the infix expression: ");
                scanf("%s", infix);
                break;
            case 2:
                infixtoprefix();
                break;
            case 3:
                evaluation();
                break;
            case 4:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}
