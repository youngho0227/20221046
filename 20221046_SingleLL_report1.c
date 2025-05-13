//실습 1-4
void printList(Node* head) {
	Node* current = head;
	while (current != NULL) {
		printf("%d -> ", current->data);
		current = current->next;
	}
	printf("NULL\n");
	return;
}

//실습 1-5
int searchValue1(Node* head, int targetValue) {
	int pos = 1;
	Node* current = head;
	while (current != NULL) {
		if (current->data == targetValue) {
			return pos;
		}
		current = current->next;
		pos++;
	}
	return -1; 
}

void searchValue2(Node* head, int targetValue) {
	Node* current = head;
	while (current != NULL) {
		if (current->next->data == targetValue) {
			printf("앞에 있는 노드의 값 : %d\n", current->data);
			printf("뒤에 있는 노드의 값 : %d\n", current->next->next->data);
			return 0;
		}
		current = current->next;
	}
	printf("값 %d를 가진 노드를 찾을 수 없습니다.\n", targetValue);
	return -1;
}

void freeList(Node* head) {
	Node* current = head;
	Node* nextNode;
	while (current != NULL) {
		nextNode = current->next;
		free(current);
		current = nextNode;
	}
	return 0;
}
