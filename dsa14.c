#include <stdio.h>

int main() {
    int n, i, j;
    int matrix[100][100];
    int flag = 1;   // Assume matrix is identity

    // Input size
    scanf("%d", &n);

    // Input matrix
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    // Check identity matrix
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            if(i == j && matrix[i][j] != 1)
                flag = 0;
            if(i != j && matrix[i][j] != 0)
                flag = 0;
        }
    }

    // Output result
    if(flag == 1)
        printf("Identity Matrix");
    else
        printf("Not an Identity Matrix");

    return 0;
}
