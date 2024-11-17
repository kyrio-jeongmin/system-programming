#include <stdio.h>
#define SIZE 5

extern void bubble_sort(int arr[], int size);

int main() {
    int arr[SIZE] = {5, 3, 1, 4, 2};
    printf("정렬 전 배열: ");
    for (int i = 0; i < SIZE; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    bubble_sort(arr, SIZE);

    printf("정렬 후 배열: ");
    for (int i = 0; i < SIZE; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}
