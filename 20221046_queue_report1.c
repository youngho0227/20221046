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
		printf("ť�� ���� á���ϴ�.\n");
		return false;
	}
	q->rear++;
	q->data[q->rear] = value;
	return true;
}

int dequeue(LinearQueue* q) {
	if (isEmpty(q)) {
		printf("ť�� ��� �ֽ��ϴ�.\n");
		return -1;
	}
	int value = q->data[q->front];
	q->front++;
	if (isEmpty(q)) {
		initQueue(q);		// ť�� ��������� �ʱ�ȭ
	}
	return value;
}

void menu(int num,LinearQueue*q) {
	int value;
	switch (num) {
	case 1:
		printf("ť�� ������ ���� �Է��ϼ���: ");
		scanf_s("%d", &value);
		enqueue(q, value);
		break;
	case 2:
		printf("Dequeue: %d\n", dequeue(q));
		break;
	case 3:
		printf("ť ������: ");
		for (int i = q->front; i <= q->rear; i++) {
			printf("%d ", q->data[i]);
		}
		printf("\n");
		break;
	case 4:
		printf("���α׷��� �����մϴ�.\n");
		break;
	default:
		printf("�߸��� ��ȣ�Դϴ�.\n");
		break;
	}
}

int main() {
	LinearQueue q;
	initQueue(&q);
	int num;
	do {
		printf("ť �޴�\n");
		printf("1. ����\n");
		printf("2. ����\n");
		printf("3. ť ������ ���\n");
		printf("4. ����\n");
		scanf_s("%d", &num);
		system("cls");
		menu(num,&q);
	} while (num != 4);
	return 0;
}