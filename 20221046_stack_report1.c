int main() {
	Stack s;
	initStack(&s);
	char t[MAX];
	printf("문자열을 입력하세요: ");
	gets_s(t,MAX);

	for (int i = 0; t[i] != '\0'; i++) {
		push(&s, t[i]);
	}
	printf("거꾸로 된 문자열: ");
	while (!isEmpty(&s)) {
		printf("%c", pop(&s));
	}
	return 0;
}
