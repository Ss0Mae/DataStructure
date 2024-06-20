#include <stdio.h>

void recursivePrint(int N){
    int mod = N%10;
    if(N/10 ==0) printf("%d",mod);
    else{
        recursivePrint(N/10);
        printf("%d",mod);    
    }
}
int main(){
    int N;
    scanf("%d",&N);
    recursivePrint(N);
}