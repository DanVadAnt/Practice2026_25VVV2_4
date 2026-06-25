#include <stdio.h>
#include <stdlib.h>

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

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int n;

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

    printf("Введите %d целых чисел:\n", n);
    for (int i = 0; i < n; i++) {
        printf("Элемент [%d]: ", i + 1);
        scanf("%d", &arr[i]);
    }

    printf("\nИсходный массив: ");
    printArray(arr, n);

    insertionSort(arr, n);

    printf("Отсортированный массив: ");
    printArray(arr, n);

    free(arr);

    return 0;
}