#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void insertionSort(int arr[], int n) {
    int i, key, j;

    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

// Заполнение массива случайными числами от 0 до 99
void fillArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100;
    }
}

// Вывод массива в виде таблицы и в консоль, и в файл
void printTable(FILE* out, const char* title, int arr[], int n) {
    fprintf(out, "%s\n", title);
    fprintf(out, "+--------+--------+\n");
    fprintf(out, "| %-6s | %-6s |\n", "Индекс", "Значе.");
    fprintf(out, "+--------+--------+\n");
    for (int i = 0; i < n; i++) {
        fprintf(out, "| %-6d | %-6d |\n", i + 1, arr[i]);
    }
    fprintf(out, "+--------+--------+\n\n");
}

int main() {
    int n;

    srand((unsigned int)time(NULL));

    printf("Введите количество элементов массива: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Ошибка: количество элементов должно быть положительным!\n");
        return 1;
    }

    int* arr = (int*)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Ошибка выделения памяти!\n");
        return 1;
    }

    // Массив заполняется автоматически
    fillArray(arr, n);

    // Файл для записи результата
    FILE* file = fopen("result.txt", "w");
    if (file == NULL) {
        printf("Ошибка открытия файла для записи!\n");
        free(arr);
        return 1;
    }

    // Вывод исходного массива в таблице (консоль + файл)
    printTable(stdout, "Исходный массив:", arr, n);
    printTable(file, "Исходный массив:", arr, n);

    insertionSort(arr, n);

    // Вывод отсортированного массива в таблице (консоль + файл)
    printTable(stdout, "Отсортированный массив:", arr, n);
    printTable(file, "Отсортированный массив:", arr, n);

    fclose(file);
    printf("Результат также записан в файл result.txt\n");

    free(arr);

    return 0;
}
