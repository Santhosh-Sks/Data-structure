#include <stdio.h>
#include <stdlib.h>
#include<conio.h>

// Function to merge two subarrays
void merge(int arr[], int left, int mid, int right) {
int l,i=0,j=0,k=left;
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int* leftArr = (int*)malloc(n1 * sizeof(int));
    int* rightArr = (int*)malloc(n2 * sizeof(int));

    for (l = 0; l < n1; l++)
	leftArr[l] = arr[left + l];
    for (l = 0; l < n2; l++)
	rightArr[l] = arr[mid + 1 + l];


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

    free(leftArr);
    free(rightArr);
}

// Function to implement merge sort
void mergeSort(int arr[], int left, int right) {
    if (left < right) {
	int mid = left + (right - left) / 2;

	mergeSort(arr, left, mid);
	mergeSort(arr, mid + 1, right);

	merge(arr, left, mid, right);
    }
}

// Function to perform binary search
int binarySearch(int arr[], int left, int right, int target) {
    while (left <= right) {
	int mid = left + (right - left) / 2;

	// Check if target is present at mid
	if (arr[mid] == target) {
	    return mid;
	}

	// If target is greater, ignore left half
	if (arr[mid] < target) {
	    left = mid + 1;
	}
	// If target is smaller, ignore right half
	else {
	    right = mid - 1;
	}
    }

    // If target is not present in array
    return -1;
}

// Function to display the elements of the array
void displayArray(int arr[], int size) {
int i;
    printf("Array elements: ");
    for ( i = 0; i < size; i++) {
	printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int size,i,target,result;
    int* arr=(int*)malloc(size * sizeof(int));
    clrscr();
    printf("Enter the number of elements: ");
    scanf("%d", &size);


    printf("Enter %d elements:\n", size);
    for ( i = 0; i < size; i++) {
	scanf("%d", &arr[i]);
    }

   // printf("Given array:\n");
   // displayArray(arr, size);

    // Sort the array before searching
    mergeSort(arr, 0, size - 1);

   // printf("Sorted array:\n");
   // displayArray(arr, size);


    printf("Enter the target element to search: ");
    scanf("%d", &target);

    result = binarySearch(arr, 0, size - 1, target);
    if (result != -1) {
	printf("Element found at index %d.\n", result);
    } else {
	printf("Element not found.\n");
    }
    printf("Sorted array:\n");

    displayArray(arr, size);
    getch();
    free(arr);
    return 0;
}
