#include <stdio.h>

int canFinish(int* boards, int n, int k, long long limit) {
    int painters = 1;
    long long current = 0;

    for (int i = 0; i < n; i++) {
        if (current + boards[i] > limit) {
            painters++;
            current = boards[i];
            if (painters > k) return 0;
        } else {
            current += boards[i];
        }
    }
    return 1;
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);

    int boards[n];
    long long lo = 0, hi = 0;

    for (int i = 0; i < n; i++) {
        scanf("%d", &boards[i]);
        if (boards[i] > lo) lo = boards[i];  // max board (minimum possible answer)
        hi += boards[i];                     // sum of all boards (maximum possible answer)
    }

    while (lo < hi) {
        long long mid = lo + (hi - lo) / 2;
        if (canFinish(boards, n, k, mid))
            hi = mid;
        else
            lo = mid + 1;
    }

    printf("%lld\n", lo);
    return 0;
}