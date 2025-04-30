#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable:4996)

#define SIZE 10

typedef struct {
	char documentName[50];
	int numPages;
} PrintJob;

typedef struct {
	PrintJob queue[SIZE];
	int front;
	int rear;
} PrintQueue;

void initQueue(PrintQueue* q) {
	q->front = 0;
	q->rear = 0;
}

bool isEmpty(PrintQueue* q) {
	return q->front == q->rear;
}

bool isFull(PrintQueue* q) {
	return (q->rear + 1) % SIZE == q->front;
}

bool enqueue(PrintQueue* q, char* documentName, int numPages) {
	if (isFull(q)) {
		printf("��⿭�� ���� á���ϴ�. �۾��� �߰��� �� �����ϴ�.\n");
		return false;
	}
	if (numPages > 50) {
		printf("������ ���� 50�� �ʰ��߽��ϴ�. �۾��� �߰��� �� �����ϴ�.\n");
		return false;
	}
	strcpy(q->queue[q->rear].documentName, documentName);
	q->queue[q->rear].numPages = numPages;
	q->rear = (q->rear + 1) % SIZE;
	printf("�۾� '%s' (%d ������)�� ��⿭�� �߰��Ǿ����ϴ�.", documentName, numPages);
	return true;
}

PrintJob dequeue(PrintQueue* q) {
	if (isEmpty(q)) {
		printf("��⿭�� ��� �ֽ��ϴ�. �۾��� �����ϴ�.\n");
		PrintJob emptyJob = { "", 0 };
		return emptyJob;
	}
	PrintJob job = q->queue[q->front];
	q->front = (q->front + 1) % SIZE;
	return job;
}

void printQueue(PrintQueue* q) {
	if (isEmpty(q)) {
		printf("��⿭�� ��� �ֽ��ϴ�.\n");
		return;
	}
	printf("���� ��� ���� �۾�:\n");
	int i = q->front;
	while (i != q->rear) {
		printf("- %s (%d ������)\n", q->queue[i].documentName, q->queue[i].numPages);
		i = (i + 1) % SIZE;
	}
}
void cancelJob(PrintQueue* q, char* documentName) {
	if (isEmpty(q)) {
		printf("��⿭�� ��� �ֽ��ϴ�. �۾��� ����� �� �����ϴ�.\n");
		return;
	}
	int i = q->front;
	while (i != q->rear) {
		if (strcmp(q->queue[i].documentName, documentName) == 0) {
			printf("�۾� '%s' (%d ������)�� ��ҵǾ����ϴ�.\n", q->queue[i].documentName, q->queue[i].numPages);
			for (int j = i + 1; j != q->rear; j = (j + 1) % SIZE)
				q->queue[(j - 1 + SIZE) % SIZE] = q->queue[j];
			q->rear = (q->rear - 1 + SIZE) % SIZE;
			return;
		}
		i = (i + 1) % SIZE;
	}
	printf("�ش� ������ ��⿭�� �����ϴ�.\n");
}
void clearQueue(PrintQueue* q) {
	initQueue(q);
	printf("��⿭�� �ʱ�ȭ�Ǿ����ϴ�.\n");
}

int main() {
	PrintQueue q;
	initQueue(&q);
	int choice;
	char documentName[50];
	int numPages;

	while (true) {
		printf("\n1. �۾� �߰�\n2. �۾� ó��\n3. ��⿭ ���\n4. �μ� ���\n5. ��⿭ ��ü ����\n6. ����\n����: ");
		scanf_s("%d", &choice);

		switch (choice) {
		case 1:
			printf("���� �̸�: ");
			scanf_s("%s", documentName, 50);
			printf("������ ��: ");
			scanf_s("%d", &numPages);
			enqueue(&q, documentName, numPages);
			break;
		case 2:

			PrintJob job = dequeue(&q);
			if (strlen(job.documentName) > 0) {
				printf("�۾� '%s' (%d ������)�� ó�� ���Դϴ�...\n", job.documentName, job.numPages);
			}
			break;

		case 3:
			printQueue(&q);
			break;
		case 4:
			printf("����� ���� �̸�: ");
			scanf_s("%s", documentName, 50);
			cancelJob(&q, documentName);
			break;
		case 5:
			clearQueue(&q);
			break;
		case 6:
			printf("���α׷��� �����մϴ�.\n");
			return 0;
		default:
			printf("�߸��� �����Դϴ�. �ٽ� �õ����ּ���.\n");
			break;
		}
	}
}