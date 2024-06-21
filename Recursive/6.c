#include <stdio.h>

int Uclid(int N, int M)
{
    if (N > M)
    {
        if (M == 0)
            return N;
        else
            return Uclid(M, N % M);
    }
    else
    {
        if (N == 0)
            return M;
        else
            return Uclid(N, M % N);
    }
}
int main()
{
    int N, M;
    scanf("%d %d", &N, &M);
    int gcd = Uclid(N, M);
    printf("%d\n", gcd);
}