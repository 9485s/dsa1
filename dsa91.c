#include <stdio.h>
#include <stdlib.h>

// Merge two sorted subarrays: nums[left..mid] and nums[mid+1..right]
void merge(int* nums, int left, int mid, int right) {
    int i, j, k;

    int leftSize  = mid - left + 1;
    int rightSize = right - mid;

    // Temporary arrays
    int* L = (int*)malloc(leftSize  * sizeof(int));
    int* R = (int*)malloc(rightSize * sizeof(int));

    // Copy data into temp arrays
    for (i = 0; i < leftSize;  i++) L[i] = nums[left + i];
    for (j = 0; j < rightSize; j++) R[j] = nums[mid + 1 + j];

    // Merge back into nums
    i = 0; j = 0; k = left;
    while (i < leftSize && j < rightSize) {
        if (L[i] <= R[j])
            nums[k++] = L[i++];
        else
            nums[k++] = R[j++];
    }

    // Copy any remaining elements
    while (i < leftSize)  nums[k++] = L[i++];
    while (j < rightSize) nums[k++] = R[j++];

    free(L);
    free(R);
}

void mergeSort(int* nums, int left, int right) {
    if (left >= right) return;         // Base case: 1 element, already sorted

    int mid = left + (right - left) / 2;  // Avoids integer overflow vs (l+r)/2

    mergeSort(nums, left, mid);        // Sort left half
    mergeSort(nums, mid + 1, right);   // Sort right half
    merge(nums, left, mid, right);     // Merge sorted halves
}

void printArray(int* nums, int size) {
    for (int i = 0; i < size; i++)
        printf("%d%s", nums[i], i < size - 1 ? " " : "\n");
}

int main() {
    int nums[] = {12, 11, 3, 5, 6, 7};
    int n = sizeof(nums) / sizeof(nums[0]);

    printf("Before: "); printArray(nums, n);
    mergeSort(nums, 0, n - 1);
    printf("After:  "); printArray(nums, n);

    return 0;
}