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
        printf("\n성적 관리\n");
        printf("1) 성적 평균 출력\n");
        printf("2) 번호 검색 출력\n");
        printf("3) 평균점수 기준 출력\n");
        printf("4) 성적 삭제 및 추가\n");
        printf("5) 프로그램 종료\n");
        printf("숫자를 입력하세요 : ");
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
        printf("잘못된 숫자를 입력했습니다.\n");
        break;
    }

}

void printAverage(int* scores, int* size, int* sum)
{
    printf("성적 평균 : %.2f\n", *sum / (double)*size);
}
int getStudentScore(int* scores, int* size) {
    int studentNumber;
    printf("학생 번호를 입력하세요 (1 ~ %d) : ", *size);
    scanf_s("%d", &studentNumber);
    printf("번호 : %d, 성적 : %d\n", studentNumber, scores[studentNumber - 1]);
}
void printScore(int* scores, int* size, int* sum) {
    int option;
    double average = *sum / (double)*size;
    printf("1) 모든 성적 출력\n");
    printf("2) 평균 이상 성적 출력\n");
    printf("3) 평균 미만 성적 출력\n");
    printf("번호를 입력하세요 : ");
    scanf_s("%d", &option);
    switch (option) {
    case 1:
        for (int i = 0; i < *size; i++) {
            printf("번호 : %d, 성적 : %d\n", i + 1, scores[i]);
        }
        break;
    case 2:
        for (int i = 0; i < *size; i++) {
            if (scores[i] >= average) {
                printf("번호 : %d, 성적 : %d\n", i + 1, scores[i]);
            }
        }
        break;
    case 3:
        for (int i = 0; i < *size; i++) {
            if (scores[i] < average) {
                printf("번호 : %d, 성적 : %d\n", i + 1, scores[i]);
            }
        }
        break;
    default:
        printf("잘못된 번호를 입력했습니다.\n");
    }
}
void studentScoreMenegement(int* scores, int* size, int* sum) {
    int option, studentNumber, newscore;
    printf("1) 성적 삭제\n");
    printf("2) 성적 추가\n");
    printf("숫자를 입력하세요 : ");
    scanf_s("%d", &option);
    switch (option) {
    case 1:
        printf("삭제할 학생 번호를 입력하세요 (1 ~ %d) : ", *size);
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
            printf("잘못된 번호입니다.\n");
        }
        break;
    case 2:
        while (TRUE) {
            printf("추가할 학생의 성적을 입력하세요 : ");
            scanf_s("%d", &newscore);
            if (newscore >= 0 && newscore <= 100) {
                break;
            }
            else {
                printf("잘못된 성적을 입력했습니다.\n");
            }
        }
        *size += 1;
        *sum += newscore;
        realloc(scores, sizeof(int) * (*size));
        scores[*size - 1] = newscore;
        break;
    default:
        printf("잘못된 숫자를 입력했습니다.\n");
    }
}