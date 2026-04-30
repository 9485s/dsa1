#include <limits.h>

// Check if allocation is possible
int isPossible(int arr[], int n, int m, int maxPages) {
    int students = 1;
    int currentPages = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] > maxPages)
            return 0;

        if (currentPages + arr[i] > maxPages) {
            students++;
            currentPages = arr[i];

            if (students > m)
                return 0;
        } else {
            currentPages += arr[i];
        }
    }

    return 1;
}

int findPages(int arr[], int n, int m) {
    if (m > n) return -1;

    int low = 0, high = 0;

    // range setup
    for (int i = 0; i < n; i++) {
        if (arr[i] > low)
            low = arr[i];   // max element
        high += arr[i];     // total sum
    }

    int ans = high;

    // Binary Search
    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (isPossible(arr, n, m, mid)) {
            ans = mid;
            high = mid - 1;  // try smaller answer
        } else {
            low = mid + 1;   // increase limit
        }
    }

    return ans;
}