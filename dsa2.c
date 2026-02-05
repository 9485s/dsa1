#include <stdio.h>

int main() {
    int n, pos;

    // Read size of array
    scanf("%d", &n);

    int arr[n];

    // Read array elements
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Read position to delete (1-based)
    scanf("%d", &pos);

    // Shift elements to the left from the deleted position
    for (int i = pos - 1; i < n - 1; i++) {
        arr[i] = arr[i + 1];
    }

    // Print updated array
    for (int i = 0; i < n - 1; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
