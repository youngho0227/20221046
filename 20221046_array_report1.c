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
    printf("학급 평균 점수 : %.2f\n", average);
    printf("학생 번호를 입력하세요 (1 ~ 30): ");
    scanf_s("%d", &studentNumber);

    int score = getStudentScore(scores, 30, studentNumber);
    if (score != -1) {
        printf("%d번 학생의 점수 : %d\n", studentNumber, score);
    }
    else {
        printf("유효하지 않은 학생 번호입니다.\n");
    }
    printf("출력할 성적중 모든 성적은 0, 평균이상은 1, 평균 미만은 2를 입력하시오 : ");
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
            printf("번호 : %d, 성적 : %d\n", i + 1, scores[i]);
        }
        break;
    case 1:
        for (int i = 0; i < size; i++) {
            if (scores[i] >= average) {
                printf("번호 : %d, 성적 : %d\n", i + 1, scores[i]);
            }
        }
        break;
    case 2:
        for (int i = 0; i < size; i++) {
            if (scores[i] < average) {
                printf("번호 : %d, 성적 : %d\n", i + 1, scores[i]);
            }
        }
        break;
    default:
        printf("잘못된 숫자를 입력했습니다.\n");
    }
}