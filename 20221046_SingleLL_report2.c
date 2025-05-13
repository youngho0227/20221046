#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>

typedef struct Node {
	char name[20];
	int number;
	struct Node* next;
} Node;

Node* insertFirst(Node* head, char* name, int number) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	strcpy(newNode->name, name);
	newNode->number = number;
	newNode->next = NULL;

	if (head == NULL) {
		return newNode;
	}
	newNode->next = head;
	return newNode;
}

Node* deleteNode(Node* head, char* name) {
	if (head == NULL) {
		printf("전화번호부가 비어 있습니다. 삭제할 연락처가 없습니다.\n");
		return NULL;
	}
	if (strcmp(head->name, name) == 0) {
		Node* temp = head;
		head = head->next;
		free(temp);
		return head;
	}
	Node* current = head;
	while (current->next != NULL && strcmp(current->next->name,name)!= 0) {
		current = current->next;
	}
	if (current->next == NULL) {
		printf("연락처 %s를 찾을 수 없습니다.\n", name);
		return head;
	}
	Node* temp = current->next;
	current->next = current->next->next;
	free(temp);

	return head;
}

void searchValue(Node* head, char* name) {
	Node* current = head;
	while (current != NULL) {
		if (strcmp(current->name,name)== 0) {
			printf("이름 : %s\n", current->name);
			printf("번호 : %d\n", current->number);
			return;
		}
		current = current->next;
	}
	printf("연락처 이름 %s를 찾을 수 없습니다.\n", name);
	return;
}

void printList(Node* head) {
	Node* current = head;
	while (current != NULL) {
		printf("연락처 이름 : %s, 번호 : %d \n", current->name,current->number);
		current = current->next;
	}
	return;
}

void freeList(Node* head) {
	Node* current = head;
	Node* nextNode;
	while (current != NULL) {
		nextNode = current->next;
		free(current);
		current = nextNode;
	}
	return;
}

int main() {
	Node* head = NULL;
	int choice;
	int number;
	char name[20];
	do {
		printf("전화번호부 메뉴:\n 1. 연락처 추가\n 2. 연락처 검색\n 3. 연락처 삭제\n 4. 전화번호부 출력\n 5. 종료\n 선택 : ");
		scanf("%d", &choice);
		system("cls");
		switch (choice) {
		case 1:
			printf("연락처 이름 : ");
			scanf("%s", name);
			printf("연락처 번호 : ");
			scanf("%d", &number);
			head = insertFirst(head, name, number);
			break;

		case 2: {
			printf("검색할 연락처 이름을 입력하세요: ");
			scanf("%s", name);
			searchValue(head, name);
			break;
		}
		case 3: {
			printf("삭제할 연락처 이름을 입력하세요: ");
			scanf("%s", name);
			head = deleteNode(head, name);
			break;
		}
		case 4:
			printList(head);
			break;
		case 5:
			freeList(head);
			break;
		default:
			printf("잘못된 선택입니다. 다시 시도하세요.\n");
		}
	} while (choice != 5);

	return 0;
}
