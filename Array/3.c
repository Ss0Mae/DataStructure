#include <stdio.h>

int main()
{
    int N;
    scanf("%d", &N);
    int arr[N][N];
    int num = 1;
    for (int i = 0; i < N; i++){
        if (i %2==0){
            for (int j = 0; j < N;j++){
                arr[i][j] = num;
                num++;
            }
        }
        else{
            for(int j = N-1; j >= 0; j--){
                arr[i][j] = num;
                num++;
            }
        }
    }
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}