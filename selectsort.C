
#include <stdio.h>
#include <conio.h>

#define MAX_SIZE 100  // Define a constant for the maximum size of the array

// Function to perform Selection Sort
void selectionSort(int arr[], int n) {
    int i, j, minIdx, temp;

    // Move the boundary of the unsorted subarray
    for (i = 0; i < n-1; i++) {
	// Find the minimum element in the unsorted subarray
	minIdx = i;
	for (j = i+1; j < n; j++) {
	    if (arr[j] < arr[minIdx]) {
		minIdx = j;
	    }
	}

	// Swap the found minimum element with the first element
	temp = arr[minIdx];
	arr[minIdx] = arr[i];
	arr[i] = temp;
    }
}

// Function to print an array
void printArray(int arr[], int size) {
    int i;
    for (i = 0; i < size; i++) {
	printf("%d ", arr[i]);
    }
    printf("\n");
}

// Main function to take user input and sort the array
void main() {
    int n, i, arr[MAX_SIZE];
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter the elements: \n");
    for (i = 0; i < n; i++) {
	scanf("%d", &arr[i]);
    }

    printf("Original array: \n");
    printArray(arr, n);

    selectionSort(arr, n);
    printf("Sorted array in ascending order: \n");
    printArray(arr, n);
    getch();
}
