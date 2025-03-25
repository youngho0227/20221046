#include <stdio.h>
#include <stdlib.h>
#include <time.h>

double calculateAverage(int scores[], int size);
int getStudentScore(int scores[], int size, int studentNumber);
void printScore(int scores[], int size, double average, int option);

int main() {
    int scores[30];
    int sum = 0;
    double average;
    int studentNumber;
    int option;

    srand(time(NULL));

    for (int i = 0; i < 30; i++) {
        scores[i] = rand() % 101;
    }
    average = calculateAverage(scores, 30);
    printf("�б� ��� ���� : %.2f\n", average);
    printf("�л� ��ȣ�� �Է��ϼ��� (1 ~ 30): ");
    scanf_s("%d", &studentNumber);

    int score = getStudentScore(scores, 30, studentNumber);
    if (score != -1) {
        printf("%d�� �л��� ���� : %d\n", studentNumber, score);
    }
    else {
        printf("��ȿ���� ���� �л� ��ȣ�Դϴ�.\n");
    }
    printf("����� ������ ��� ������ 0, ����̻��� 1, ��� �̸��� 2�� �Է��Ͻÿ� : ");
    scanf_s("%d", &option);
    printScore(scores, 30, average, option);

    return 0;
}

double calculateAverage(int scores[], int size)
{
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += scores[i];
    }
    return sum / (double)size;
}

int getStudentScore(int scores[], int size, int studentNumber) {
    if (studentNumber >= 1 && studentNumber <= size) {
        return scores[studentNumber - 1];
    }
    else {
        return -1;
    }
}
void printScore(int scores[], int size, double average, int option) {
    switch (option) {
    case 0:
        for (int i = 0; i < size; i++) {
            printf("��ȣ : %d, ���� : %d\n", i + 1, scores[i]);
        }
        break;
    case 1:
        for (int i = 0; i < size; i++) {
            if (scores[i] >= average) {
                printf("��ȣ : %d, ���� : %d\n", i + 1, scores[i]);
            }
        }
        break;
    case 2:
        for (int i = 0; i < size; i++) {
            if (scores[i] < average) {
                printf("��ȣ : %d, ���� : %d\n", i + 1, scores[i]);
            }
        }
        break;
    default:
        printf("�߸��� ���ڸ� �Է��߽��ϴ�.\n");
    }
}