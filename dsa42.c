#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int queue[n];
    int stack[n];
    int top = -1;

    for(int i = 0; i < n; i++)
        scanf("%d", &queue[i]);

    // push queue elements into stack
    for(int i = 0; i < n; i++)
        stack[++top] = queue[i];

    // pop stack into queue
    for(int i = 0; i < n; i++)
        queue[i] = stack[top--];

    // print reversed queue
    for(int i = 0; i < n; i++)
        printf("%d ", queue[i]);

    return 0;
}