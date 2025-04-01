#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct {
    int data[MAX];
    int top;
} Stack;

void initStack(Stack* s) {
    s->top = -1;
}

int isEmpty(Stack* s) {
    return s->top == -1;
}

int isFull(Stack* s) {
    return s->top == MAX - 1;
}

void push(Stack* s, int value) {
    if (isFull(s)) {
        printf("Stack overflow! Cannot push %d\n", value);
        return;
    }
    s->data[++(s->top)] = value;
}

int pop(Stack* s) {
    if (isEmpty(s)) {
        printf("Stack underflow! Cannot pop\n");
        return -1;
    }
    return s->data[(s->top)--];
}

int peek(Stack* s) {
    if (isEmpty(s)) {
        printf("Stack is empty! Cannot peek\n");
        return -1;
    }
    return s->data[s->top];
}

void display(Stack* s) {
    if (isEmpty(s)) {
        printf("Stack is empty!\n");
        return;
    }
    printf("Stack contents: ");
    for (int i = 0; i <= s->top; i++) {
        printf("%d ", s->data[i]);
    }
    printf("\n");
}

int main() {
    Stack s;
    initStack(&s);

    char t[MAX];
    printf("문자열을 입력하세요: ");
    gets(t);
    for (int i = 0; t[i] != '\0'; i++) {
        if (t[i] == '(' || t[i] == '{' || t[i] == '[') {
            push(&s, t[i]);
        }
		else if (t[i] == ')') {
			if (peek(&s) == '(') {
				pop(&s);
			}
			else {
				printf("유효하지 않은 괄호\n");
				return 0;
            }
		}
        else if (t[i] == '}') {
            if (peek(&s) == '{') {
                pop(&s);
            }
            else {
                printf("유효하지 않은 괄호\n");
                return 0;
            }
        }
        else if (t[i] == ']') {
            if (peek(&s) == '[') {
                pop(&s);
            }
            else {
                printf("유효하지 않은 괄호\n");
                return 0;
            }
        }
    }
	if (isEmpty(&s)) {
		printf("유효한 괄호\n");
	}
	else {
		printf("유효하지 않은 괄호\n");
	}
    return 0;
}