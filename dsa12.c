#include <stdio.h>

int main()
{
    int m, n;
    int matrix[20][20];
    int symmetric = 1;

    scanf("%d %d", &m, &n);

    // If not square matrix
    if(m != n)
    {
        printf("Not a Symmetric Matrix");
        return 0;
    }

    // Input matrix
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            scanf("%d", &matrix[i][j]);
        }
    }

    // Check symmetric condition
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(matrix[i][j] != matrix[j][i])
            {
                symmetric = 0;
                break;
            }
        }
    }

    if(symmetric)
        printf("Symmetric Matrix");
    else
        printf("Not a Symmetric Matrix");

    return 0;
}
