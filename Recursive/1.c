#include <stdio.h>

int recursiveSum(int N){
    int tot = 0;
    if (N ==0) return 0;
    else return N + recursiveSum(N-1);
}
int main(){
    int N;
    scanf("%d",&N);
    printf("%d",recursiveSum(N));
}