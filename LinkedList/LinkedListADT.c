#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} node;

node *head = NULL;
node *tail = NULL;

node *createNode(int data){
    node *newNode = (node *)malloc(sizeof(node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void add_front(int data){
    node *newNode = createNode(data);
    if(head==NULL){
        head = newNode;
        tail = newNode;
    }
    else{
        newNode->next = head;
        head = newNode;
    }
}

// 리스트 뒤에 노드를 추가하는 함수
void add_back(int data)
{
    node *new_node = createNode(data);
    if (tail == NULL)
    {
        head = new_node;
        tail = new_node;
    }
    else
    {
        tail->next = new_node;
        tail = new_node;
    }
}

// 특정 값을 가진 첫 번째 노드를 삭제하는 함수
void delete_node(int data)
{
    node *current = head;
    node *previous = NULL;

    while (current != NULL && current->data != data)
    {
        previous = current;
        current = current->next;
    }

    if (current == NULL)
    {
        printf("Node with data %d not found.\n", data);
        return;
    }

    if (previous == NULL)
    {
        head = current->next;
    }
    else
    {
        previous->next = current->next;
    }

    if (current == tail)
    {
        tail = previous;
    }

    free(current);
}

// 리스트를 출력하는 함수
void print_list()
{
    node *current = head;
    while (current != NULL)
    {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}
int main(){

    add_back(10);
    add_back(20);
    add_front(5);
    add_front(1);
    print_list(); // 1 -> 5 -> 10 -> 20 -> NULL

    delete_node(10);
    print_list(); // 1 -> 5 -> 20 -> NULL

    delete_node(1);
    print_list(); // 5 -> 20 -> NULL
}