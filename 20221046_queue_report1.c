#include <stdio.h>
#include <stdbool.h>
#include <Windows.h>

#define SIZE 5

typedef struct {
	int data[SIZE];
	int front;
	int rear;
} LinearQueue;

void initQueue(LinearQueue* q) {
	q->front = 0;
	q->rear = -1;
}

bool isEmpty(LinearQueue* q) {
	return q->rear < q->front;
}

bool isFull(LinearQueue* q) {
	return q->rear == SIZE - 1;
}

bool enqueue(LinearQueue* q, int value) {
	if (isFull(q)) {
		printf("큐가 가득 찼습니다.\n");
		return false;
	}
	q->rear++;
	q->data[q->rear] = value;
	return true;
}

int dequeue(LinearQueue* q) {
	if (isEmpty(q)) {
		printf("큐가 비어 있습니다.\n");
		return -1;
	}
	int value = q->data[q->front];
	q->front++;
	if (isEmpty(q)) {
		initQueue(q);		// 큐가 비어있으면 초기화
	}
	return value;
}

void menu(int num,LinearQueue*q) {
	int value;
	switch (num) {
	case 1:
		printf("큐에 삽입할 값을 입력하세요: ");
		scanf_s("%d", &value);
		enqueue(q, value);
		break;
	case 2:
		value = dequeue(q);
		if(value != -1) {
			printf("Dequeue: %d\n", dequeue(q));
		}
		break;
	case 3:
		printf("큐 데이터: ");
		for (int i = q->front; i <= q->rear; i++) {
			printf("%d ", q->data[i]);
		}
		printf("\n");
		break;
	case 4:
		printf("프로그램을 종료합니다.\n");
		break;
	default:
		printf("잘못된 번호입니다.\n");
		break;
	}
}

int main() {
	LinearQueue q;
	initQueue(&q);
	int num;
	do {
		printf("큐 메뉴\n");
		printf("1. 삽입\n");
		printf("2. 삭제\n");
		printf("3. 큐 데이터 출력\n");
		printf("4. 종료\n");
		scanf_s("%d", &num);
		system("cls");
		menu(num,&q);
	} while (num != 4);
	return 0;
}
