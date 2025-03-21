#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int leftArr[n1], rightArr[n2];

    for (int i = 0; i < n1; i++) {
        leftArr[i] = arr[left + i];
    }
    for (int j = 0; j < n2; j++) {
        rightArr[j] = arr[mid + 1 + j];
    }

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (leftArr[i] <= rightArr[j]) {
            arr[k] = leftArr[i];
            i++;
        } else {
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = leftArr[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = rightArr[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}

double timeMergeSort(int n) {
    int arr[n];
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 10000;
    }

    clock_t start_time = clock();
    mergeSort(arr, 0, n - 1);
    clock_t end_time = clock();

    return ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
}

int main() {
    int values_of_n[] = {10, 100, 1000, 5000, 10000, 20000};
    int size = sizeof(values_of_n) / sizeof(values_of_n[0]);

    for (int i = 0; i < size; i++) {
        double time_taken = timeMergeSort(values_of_n[i]);
        printf("Time taken to sort %d elements: %.6f seconds\n", values_of_n[i], time_taken);
    }

    return 0;
}
