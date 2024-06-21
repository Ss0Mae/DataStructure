#include <stdio.h>
void towersOfHanoi(int N, char start, char end, char sub){
    if (N==1){
        printf("%d disk -> %c %c\n", N,start,end);
        return;
    }
    else{
        towersOfHanoi(N-1,start,sub,end);
        printf("%d disk -> %c %c\n",N,start,end);
        towersOfHanoi(N-1,sub,end,start);
    }
}
int main(){
    int N;
    scanf("%d",&N);
    towersOfHanoi(N,'A','C','B');
}