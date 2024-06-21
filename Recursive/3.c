#include <stdio.h>

void recursivePrint(int N){
    int mod = N%10;
    if(N/10 ==0) printf("%d",mod);
    else{
        printf("%d",mod);
        recursivePrint(N/10);    
    }
}
int main(){
    int N;
    scanf("%d",&N);
    recursivePrint(N);
}