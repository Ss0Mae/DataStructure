#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable : 4996)
int main()
{
    int **p;
    int N, M, num = 1;
    int x = 0, y = -1;
    scanf("%d %d", &N, &M);
    int width = M;
    int height = N - 1;
    p = (int **)malloc(N * sizeof(int *));
    for (int i = 0; i < N; i++)
        p[i] = (int *)malloc(M * sizeof(int));
    while (num <= N * M)
    {
        for (int i = 0; i < width && num <= N * M; i++)
        {
            p[x][++y] = num++;
        }
        width--;
        for (int i = 0; i < height && num <= N * M; i++)
        {
            p[++x][y] = num++;
        }
        height--;
        for (int i = 0; i < width && num <= N * M; i++)
        {
            p[x][--y] = num++;
        }
        width--;
        for (int i = 0; i < height && num <= N * M; i++)
        {
            p[--x][y] = num++;
        }
        height--;
    }
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            printf(" %d", p[i][j]);
        }
        printf("\n");
    }
}