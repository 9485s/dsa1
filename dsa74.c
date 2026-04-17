#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1000
#define LEN 50

int cmp(const void *a, const void *b) {
    return strcmp((char *)a, (char *)b);
}

int main() {
    int n;
    scanf("%d", &n);

    char votes[MAX][LEN];

    for (int i = 0; i < n; i++) {
        scanf("%s", votes[i]);
    }

    // Sort names
    qsort(votes, n, sizeof(votes[0]), cmp);

    int maxCount = 1, count = 1;
    char winner[LEN];
    strcpy(winner, votes[0]);

    for (int i = 1; i < n; i++) {
        if (strcmp(votes[i], votes[i - 1]) == 0) {
            count++;
        } else {
            count = 1;
        }

        // Update winner
        if (count > maxCount) {
            maxCount = count;
            strcpy(winner, votes[i]);
        }
    }

    printf("%s %d\n", winner, maxCount);

    return 0;
}