#include <stdio.h>
#include <stdlib.h>

typedef struct DListNode{
    struct DListNode *llink;
    struct DListNode *rlink;
    int data;
} DListNode;

void init(DListNode* head){
    head->rlink = head;
    head->llink = head;
}

void insert(DListNode* prev, int data){
    DListNode *newNode = (DListNode *)malloc(sizeof(DListNode));
    newNode->data = data;
    newNode->rlink = prev->rlink;
    newNode->llink = prev;

    prev->rlink->llink = newNode; //prev와 연결되었던 다음 노드의 왼쪽 링크를 업데이트
    prev->rlink = newNode;
}

void delete(DListNode* head, DListNode *remove){
    if(remove == head)
        return;
    else{
        remove->llink->rlink = remove->rlink;
        remove->rlink->llink = remove->llink;
        free(remove);
    }
}

void print(DListNode* head){
    DListNode *p = head->rlink;
    for (; p != head;p=p->rlink){
        printf("%d ->", p->data);
    }
    printf("\n");
}
int main(){
    DListNode *head = (DListNode *)malloc(sizeof(DListNode));
    init(head);
    printf("insert\n");
    for (int i = 0; i < 5;i++){
        insert(head, i);
        print(head);
    }
    printf("\n\ndelete\n");
    for (int i = 0; i < 5;i++){
        print(head);
        delete (head, head->rlink);
    }
}