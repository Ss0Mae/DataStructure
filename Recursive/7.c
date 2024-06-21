#include <stdio.h>

int recursiveCount(char str[], char c, int i){
    if(str[i] == '\0') return 0;
    else{
        if(str[i] == c) return 1 + recursiveCount(str, c, i+1);
        else return recursiveCount(str, c, i+1);
    }
}
int main(){
    char str[100];
    char c;
    int i = 0;
    scanf("%s", str);
    getchar();
    scanf("%c", &c);
    printf("%d", recursiveCount(str, c, i));
}