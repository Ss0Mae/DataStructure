#include <stdio.h>
int main()
{
    int N;
    int arr[100];
    int tmp[100];
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &arr[i]);
    }
    for (int i = 0; i < N; i++)
    {
        tmp[i] = arr[i];
    }
    int switchNum;
    int switchArray[100];
    scanf("%d", &switchNum);
    for (int i = 0; i < switchNum; i++)
    {
        scanf("%d", &switchArray[i]);
    }
    int temp = arr[switchArray[0]];
    for (int i = 0; i < switchNum-1; i++)
    {
        int a, b;
        b = switchArray[i + 1];
        a = arr[b];
        arr[b] = temp;
        temp = a;
    }
    for (int i = 0; i < N; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}