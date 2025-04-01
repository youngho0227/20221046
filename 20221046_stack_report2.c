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
