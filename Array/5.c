#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable : 4996)
int main()
{
    int **p;
    int N, M;
    int num = 1;
    scanf("%d %d", &N, &M);
    p = (int **)malloc(N * sizeof(int *));
    for (int i = 0; i < N; i++)
        p[i] = (int *)malloc(M * sizeof(int));

    for (int i = 0; i < N * M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            int k = i - j;
            if (k >= 0 && k < M)
                p[j][k] = num++;
        }
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
            printf(" %d", p[i][j]);
        printf("\n");
    }
}