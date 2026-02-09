#include <stdio.h>
#include <string.h>

int main() {
    char s[1000];
    int i, temp;
    
    // Input
    scanf("%s", s);

    int n = strlen(s);

    // Mirror operation
    for (i = 0; i < n / 2; i++) {
        temp = s[i];
        s[i] = s[n - i - 1];
        s[n - i - 1] = temp;
    }

    // Output
    printf("%s", s);

    return 0;
}
