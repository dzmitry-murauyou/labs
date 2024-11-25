#include <stdio.h>
#include <stdlib.h>

int main() {
    int rows = 4; // Количество строк
    int cols = 3; // Количество столбцов

    // 1. Выделяем память для массива указателей
    int** array = (int**)malloc(rows * sizeof(int*));
    if (array == NULL) {
        fprintf(stderr, "Ошибка выделения памяти\n");
        return 1;
    }

    // 2. Выделяем память для каждой строки
    for (int i = 0; i < rows; i++) {
        array[i] = (int*)malloc(cols * sizeof(int));
        if (array[i] == NULL) {
            fprintf(stderr, "Ошибка выделения памяти\n");
            // Освобождаем уже выделенную память в случае ошибки
            for (int j = 0; j < i; j++) {
                free(array[j]);
            }
            free(array);
            return 1;
        }
    }

    // Пример: заполняем массив значениями
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            array[i][j] = i * cols + j; // Заполняем значениями
        }
    }

    // Пример: выводим массив
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", array[i][j]);
        }
        printf("\n");
    }

    // 3. Освобождаем память
    for (int i = 0; i < rows; i++) {
        free(array[i]); // Освобождаем каждую строку
    }
    free(array); // Освобождаем массив указателей

    return 0;
}
