#include <stdio.h>
#include <stdlib.h>

// Simple hash map using array (since constraints are small)
int maxLen(int arr[], int n) {
    int prefixSum = 0;
    int maxLength = 0;

    // Hash map (sum → first index)
    int hash[20001];  // assuming sum range
    for (int i = 0; i < 20001; i++) hash[i] = -2;

    // Offset to handle negative sums
    int offset = 10000;

    for (int i = 0; i < n; i++) {
        prefixSum += arr[i];

        // Case 1: sum = 0 from start
        if (prefixSum == 0) {
            maxLength = i + 1;
        }

        // Case 2: seen before
        if (hash[prefixSum + offset] != -2) {
            int prevIndex = hash[prefixSum + offset];
            int length = i - prevIndex;
            if (length > maxLength)
                maxLength = length;
        } else {
            // Store first occurrence
            hash[prefixSum + offset] = i;
        }
    }

    return maxLength;
}

int main() {
    int arr[] = {15, -2, 2, -8, 1, 7, 10, 23};
    int n = sizeof(arr)/sizeof(arr[0]);

    printf("%d", maxLen(arr, n));  // Output: 5
    return 0;
}