#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<math.h> // For pow function

char infix[100], postfix[100];

int priority(char symbol) {
    switch(symbol) {
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

char associativity(char symbol) {
    if(symbol == '^') {
        return 'R';
    }
    return 'L';
}

void infixtopost() {
    char stk[100];
    int i=0, j=0, top=-1;
    char symbol;

    for(int i = 0; infix[i] != '\0'; i++) {
        symbol = infix[i];

        if(isalnum(symbol)) {
            postfix[j++] = symbol;
        } else {
            if(symbol == '(') {
                stk[++top] = symbol;
            } else if(symbol == ')') {
                while(top != -1 && stk[top] != '(') {
                    postfix[j++] = stk[top--];
                }
                top--;
            } else {
                while(top != -1 && (priority(symbol) < priority(stk[top]) || ((priority(symbol) == priority(stk[top])) && associativity(stk[top]) == 'L'))) {
                    postfix[j++] = stk[top--];
                }
                stk[++top] = symbol;
            }
        }
    }

    while(top != -1) {
        postfix[j++] = stk[top--];
    }
    
    postfix[j] = '\0';
    printf("%s\n", postfix);
}

void evaluation() {
    float st[100];
    int top = -1;

    for(int i = 0; i < strlen(postfix); i++) {
        char symbol = postfix[i];
        if(isalnum(symbol)) {
            st[++top] = symbol - '0'; // Convert char to int
        } else {
            float op2 = st[top--];
            float op1 = st[top--];
            float res;

            switch(symbol) {
                case '+':
                    res = op1 + op2;
                    break;
                case '-':
                    res = op1 - op2;
                    break;
                case '*':
                    res = op1 * op2;
                    break;
                case '/':
                    res = op1 / op2;
                    break;
                case '^':
                    res = pow(op1, op2); // Exponentiation using pow function
                    break;
            }
            st[++top] = res;
        }
    }
    printf("%f\n", st[top--]);
}

int main() {
    int choice;

    while(1) {
        printf("enter the choice\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("enter the expression\n");
                scanf("%s", infix);
                break;
            case 2:
                infixtopost();
                // printf("%s\n", postfix);
                break;
            case 3:
                evaluation();
                break;
            default:
                break;
        }
    }
    return 0;
}
