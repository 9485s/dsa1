#include <stdio.h>
#include <string.h>

int main() {
    char s[1000];
    int left, right;
    int flag = 1;

    // Read string
    scanf("%s", s);

    left = 0;
    right = strlen(s) - 1;

    // Two-pointer comparison
    while (left < right) {
        if (s[left] != s[right]) {
            flag = 0;
            break;
        }
        left++;
        right--;
    }

    // Output result
    if (flag)
        printf("YES");
    else
        printf("NO");

    return 0;
}
