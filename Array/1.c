#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#pragma warning(disable : 4996)
int main()
{
    int *p = NULL;
    int *q = NULL;
    int *temp = NULL;
    int N, num;
    int i, j, k, x;
    scanf("%d", &N);
    p = (int *)malloc(N * sizeof(int));
    temp = (int *)malloc(N * sizeof(int));
    for (i = 0; i < N; i++)
        scanf("%d", &p[i]);
    scanf("%d", &num);
    q = (int *)malloc((num * 2) * sizeof(int));
    for (i = 0; i < (num * 2); i++)
        scanf("%d", &q[i]);

    for (i = 0; i < num; i++)
    {
        int indexOdd, indexEven;
        indexOdd = q[i * 2];
        indexEven = q[i * 2 + 1];
        for (x = 0; x < N; x++)
            temp[x] = p[x];
        k = indexEven;
        for (j = indexOdd; j <= indexEven; j++)
        {
            p[j] = temp[k];
            k = k - 1;
        }
    }
    for (x = 0; x < N; x++)
        printf(" %d", p[x]);
    printf("\n");
    free(p);
    free(temp);
    free(q);
    return 0;
}
