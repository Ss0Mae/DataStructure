#include <stdio.h>
int recursiveFindMax(int *arr,int N){
    if(N == 1) return arr[0];
    else{
        if(recursiveFindMax(arr,N-1) < arr[N-1]) return arr[N-1]; 
        else return recursiveFindMax(arr,N-1);
    }
}
int main(){
    int N;
    int arr[20], max =0;
    scanf("%d",&N);
    for(int i=0;i<N;i++) scanf("%d",&arr[i]);
    max = recursiveFindMax(arr,N);
    printf("%d",max);
    
}