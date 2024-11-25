#include <stdio.h>
#include <stdlib.h>

int main() {
    int rows = 4; // ���������� �����
    int cols = 3; // ���������� ��������

    // 1. �������� ������ ��� ������� ����������
    int** array = (int**)malloc(rows * sizeof(int*));
    if (array == NULL) {
        fprintf(stderr, "������ ��������� ������\n");
        return 1;
    }

    // 2. �������� ������ ��� ������ ������
    for (int i = 0; i < rows; i++) {
        array[i] = (int*)malloc(cols * sizeof(int));
        if (array[i] == NULL) {
            fprintf(stderr, "������ ��������� ������\n");
            // ����������� ��� ���������� ������ � ������ ������
            for (int j = 0; j < i; j++) {
                free(array[j]);
            }
            free(array);
            return 1;
        }
    }

    // ������: ��������� ������ ����������
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            array[i][j] = i * cols + j; // ��������� ����������
        }
    }

    // ������: ������� ������
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", array[i][j]);
        }
        printf("\n");
    }

    // 3. ����������� ������
    for (int i = 0; i < rows; i++) {
        free(array[i]); // ����������� ������ ������
    }
    free(array); // ����������� ������ ����������

    return 0;
}
