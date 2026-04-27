#include <stdio.h>

int integer_sqrt(long long n) {
    if (n == 0) return 0;

    long long left = 1, right = n;
    long long result = 0;

    while (left <= right) {
        long long mid = left + (right - left) / 2;

        if (mid * mid == n) {
            return (int)mid;
        } else if (mid * mid < n) {
            result = mid;        // best candidate so far
            left = mid + 1;      // try larger
        } else {
            right = mid - 1;     // too big, go smaller
        }
    }

    return (int)result;
}

int main() {
    long long n;
    scanf("%lld", &n);
    printf("%d\n", integer_sqrt(n));
    return 0;
}