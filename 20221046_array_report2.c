//20221046_array_report2.c

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>

void menu(int* scores, int* size, int mainOption, int* sum);
void printAverage(int* scores, int* size, int* sum);
int getStudentScore(int* scores, int* size);
void printScore(int* scores, int* size, int* sum);
void studentScoreMenegement(int* scores, int* size, int* sum);

void main() {
    srand(time(NULL));

    int* scores;
    int size = 30;
    int mainOption;
    int sum = 0;

    scores = (int*)malloc(sizeof(int) * size);
    for (int i = 0; i < size; i++) {
        scores[i] = rand() % 101;
        sum += scores[i];
    }
    do {
        printf("\n���� ����\n");
        printf("1) ���� ��� ���\n");
        printf("2) ��ȣ �˻� ���\n");
        printf("3) ������� ���� ���\n");
        printf("4) ���� ���� �� �߰�\n");
        printf("5) ���α׷� ����\n");
        printf("���ڸ� �Է��ϼ��� : ");
        scanf_s("%d", &mainOption);
        system("cls");
        menu(scores, &size, mainOption, &sum);
    } while (mainOption != 5);

    free(scores);
}

void menu(int* scores, int* size, int mainOption, int* sum) {
    switch (mainOption) {
    case 1:
        printAverage(scores, size, sum);
        break;
    case 2:
        getStudentScore(scores, size);
        break;
    case 3:
        printScore(scores, size, sum);
        break;
    case 4:
        studentScoreMenegement(scores, size, sum);
        break;
    case 5:
        break;
    default:
        printf("�߸��� ���ڸ� �Է��߽��ϴ�.\n");
        break;
    }

}

void printAverage(int* scores, int* size, int* sum)
{
    printf("���� ��� : %.2f\n", *sum / (double)*size);
}
int getStudentScore(int* scores, int* size) {
    int studentNumber;
    printf("�л� ��ȣ�� �Է��ϼ��� (1 ~ %d) : ", *size);
    scanf_s("%d", &studentNumber);
    printf("��ȣ : %d, ���� : %d\n", studentNumber, scores[studentNumber - 1]);
}
void printScore(int* scores, int* size, int* sum) {
    int option;
    double average = *sum / (double)*size;
    printf("1) ��� ���� ���\n");
    printf("2) ��� �̻� ���� ���\n");
    printf("3) ��� �̸� ���� ���\n");
    printf("��ȣ�� �Է��ϼ��� : ");
    scanf_s("%d", &option);
    switch (option) {
    case 1:
        for (int i = 0; i < *size; i++) {
            printf("��ȣ : %d, ���� : %d\n", i + 1, scores[i]);
        }
        break;
    case 2:
        for (int i = 0; i < *size; i++) {
            if (scores[i] >= average) {
                printf("��ȣ : %d, ���� : %d\n", i + 1, scores[i]);
            }
        }
        break;
    case 3:
        for (int i = 0; i < *size; i++) {
            if (scores[i] < average) {
                printf("��ȣ : %d, ���� : %d\n", i + 1, scores[i]);
            }
        }
        break;
    default:
        printf("�߸��� ��ȣ�� �Է��߽��ϴ�.\n");
    }
}
void studentScoreMenegement(int* scores, int* size, int* sum) {
    int option, studentNumber, newscore;
    printf("1) ���� ����\n");
    printf("2) ���� �߰�\n");
    printf("���ڸ� �Է��ϼ��� : ");
    scanf_s("%d", &option);
    switch (option) {
    case 1:
        printf("������ �л� ��ȣ�� �Է��ϼ��� (1 ~ %d) : ", *size);
        scanf_s("%d", &studentNumber);
        if (studentNumber >= 1 && studentNumber <= *size) {
            *sum -= scores[studentNumber - 1];
            *size -= 1;
            for (int i = studentNumber - 1; i < *size; i++) {
                scores[i] = scores[i + 1];
            }
            realloc(scores, sizeof(int) * (*size));
        }
        else {
            printf("�߸��� ��ȣ�Դϴ�.\n");
        }
        break;
    case 2:
        while (TRUE) {
            printf("�߰��� �л��� ������ �Է��ϼ��� : ");
            scanf_s("%d", &newscore);
            if (newscore >= 0 && newscore <= 100) {
                break;
            }
            else {
                printf("�߸��� ������ �Է��߽��ϴ�.\n");
            }
        }
        *size += 1;
        *sum += newscore;
        realloc(scores, sizeof(int) * (*size));
        scores[*size - 1] = newscore;
        break;
    default:
        printf("�߸��� ���ڸ� �Է��߽��ϴ�.\n");
    }
}