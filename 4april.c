#include <stdio.h>
int partition(int a[], int low, int high) {
    int pivot = a[low];
    int i = low + 1;
    int j = high;

    while (1) {
        while (a[i] <= pivot && i <= high) {
            i = i + 1;
        }

        while (a[j] > pivot && j >= low) {
            j = j - 1;
        }

        if (i < j) {
            int temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        } else {
            a[low] = a[j];
            a[j] = pivot;
            return j;
        }
    }
}

void quickSort(int a[], int low, int high) {
    if (low < high) {
        int pi = partition(a, low, high);
        quickSort(a, low, pi - 1);
        quickSort(a, pi + 1, high);
    }
}

void printArray(int a[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

int main() {
    int n;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int a[n];

    printf("Enter the elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    printf("Original array: ");
    printArray(a, n);

    quickSort(a, 0, n - 1);

    printf("Sorted array: ");
    printArray(a, n);

    return 0;
}
