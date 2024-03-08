#include <stdio.h>

void bubbleSort(int arr[], int n, int swaps[]) {
    int i, j, temp;

    for (i = 0; i < n-1; i++) {

        for (j = 0; j < n-i-1; j++) {

            if (arr[j] > arr[j+1]) {
                // Swap elements
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                
                // Increment swap count for the swapped values
                swaps[arr[j]]++;
                swaps[arr[j+1]]++;

            }
        }
    }
}

void selectionSort(int arr[], int n, int swaps[]) {
    int i, j, minIndex, temp;
    for (i = 0; i < n-1; i++) {
        minIndex = i;
        for (j = i+1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        // Swapping
        temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;

        // Increment swap count
        swaps[arr[i]]++;
        swaps[arr[minIndex]]++;
    }
}

void printSwaps(int swaps[], int size) {
    int totalSwaps = 0;
    for (int i = 0; i < size; i++) {
        if (swaps[i] > 0) {
            printf("%d: # of times %d is swapped: %d\n", i, i, swaps[i]);
            totalSwaps += swaps[i];
        }
    }
    printf("Total # of swaps: %d\n", totalSwaps);
    
}

int main() {
    int array1[] = {97, 16, 45, 63, 13, 22, 7, 58, 72};
    int array2[] = {90, 80, 70, 60, 50, 40, 30, 20, 10};
    
    int size1 = sizeof(array1) / sizeof(array1[0]);
    int size2 = sizeof(array2) / sizeof(array2[0]);

    int swaps1[100] = {0}; // Assuming values are between 0 and 99
    int swaps2[100] = {0};

    // Bubble Sort
    bubbleSort(array1, size1, swaps1);
    bubbleSort(array2, size2, swaps2);

    printf("array1:\n");
    printSwaps(swaps1, 100);

    printf("\narray2:\n");
    printSwaps(swaps2, 100);

    return 0;
}
