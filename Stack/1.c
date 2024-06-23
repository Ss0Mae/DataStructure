#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int Top = -1;
int size = 0;
void push(char *stack, char ele)
{
    if (Top == size - 1)
        printf("Stack FULL\n");
    else
        stack[++Top] = ele;
}
char pop(char *stack)
{
    char tmp;
    if (Top == -1)
        printf("Stack Empty\n");
    else
    {
        tmp = stack[Top];
        stack[Top] = '\0';
        Top--;
        return tmp;
    }
}
void peek(char *stack)
{
    if (Top == -1)
        printf("Stack Empty\n");
    else
        printf("%c\n", stack[Top]);
}
void duplicate(char *stack)
{
    char s;
    if (Top == size - 1)
        printf("Stack FULL\n");
    else
    {
        s = pop(stack);
        push(stack, s);
        push(stack, s);
    }
}
void upRotate(char *stack, int cnt)
{
    if (Top + 1 < cnt)
        return;
    char tmp;
    tmp = stack[Top];
    for (int i = 1; i <= cnt; i++)
    {
        stack[Top - i + 1] = stack[Top - i];
    }
    stack[Top - cnt + 1] = tmp;
}
void downRotate(char *stack, int cnt)
{
    if (Top + 1 < cnt)
        return;
    char tmp;
    tmp = stack[Top - cnt + 1];
    for (int i = cnt - 1; i >= 1; i--)
    {
        stack[Top - i] = stack[Top - i + 1];
    }
    stack[Top] = tmp;
}
void print(char *stack)
{
    for (int i = Top; i >= 0; i--)
        printf("%c", stack[i]);
    printf("\n");
}
int main()
{
    char command[20];
    char *stack;
    int N, num, cnt = 0;
    int opnum;
    char s;
    scanf("%d", &N);
    size = N;
    stack = (char *)malloc(sizeof(char) * N);
    scanf("%d", &num);
    getchar();
    for (int i = 0; i < num; i++)
    {
        scanf("%s", command);
        getchar();
        if (strcmp(command, "POP") == 0)
        {
            char p = pop(stack);
        }
        else if (strcmp(command, "PUSH") == 0)
        {
            scanf("%c", &s);
            getchar();
            push(stack, s);
        }
        else if (strcmp(command, "PEEK") == 0)
        {
            peek(stack);
        }
        else if (strcmp(command, "DUP") == 0)
        {
            duplicate(stack);
        }
        else if (strcmp(command, "UpR") == 0)
        {
            scanf("%d", &opnum);
            upRotate(stack, opnum);
        }
        else if (strcmp(command, "DownR") == 0)
        {
            scanf("%d", &opnum);
            downRotate(stack, opnum);
        }
        else if (strcmp(command, "PRINT") == 0)
        {
            print(stack);
        }
    }
}