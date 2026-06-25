#include <stdio.h>

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
    int arr[100];  // фиксированный массив до 100 элементов
    int n;

    printf("Введите количество элементов массива: ");
    scanf("%d", &n);

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

    return 0;
}