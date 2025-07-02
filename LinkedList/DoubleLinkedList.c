#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    char data;
    struct Node *prev;
    struct Node *next;
} Node;

typedef struct {
    Node *header;
    Node *trailer;
} DList;

void initList(DList *L) {
    L->header = malloc(sizeof(Node));
    L->trailer = malloc(sizeof(Node));
    L->header->prev = NULL;
    L->header->next = L->trailer;
    L->trailer->prev = L->header;
    L->trailer->next = NULL;
}

// 순위 r에 문자 e 삽입
void add(DList *L, int r, char e){
    Node *newNode = malloc(sizeof(Node));
    newNode->data = e;

    Node *current = L->header; // 순회용 포인터
    for (int i = 0; i < r && current->next != L->trailer; i++){
        current = current->next; // r번째 노드로 이동
    }
    newNode->next = current -> next; // 새 노드의 다음을 현재 노드의 다음으로 설정
    newNode->prev = current; // 새 노드의 이전을 현재 노드로 설정
    current->next->prev = newNode; // 현재 노드의 다음 노드의 이전을 새 노드로 설정
    current->next = newNode; // 현재 노
}

// 순위 r의 노드 삭제 후 원소 반환
char delete(DList *L, int r){
    Node *current = L->header; // 순회용 포인터
    for (int i = 0; i < r && current->next != L->trailer; i++){
        current = current->next; // r번째 노드로 이동
    }
    
    if (current->next == L->trailer) {
        return '\0'; // r이 리스트의 길이보다 크면 빈 문자 반환
    }

    Node *toDelete = current->next; // 삭제할 노드
    char data = toDelete->data; // 삭제할 노드의 데이터 저장

    current->next = toDelete->next; // 현재 노드의 다음을 삭제할 노드의 다음으로 설정
    toDelete->next->prev = current; // 삭제할 노드의 다음 노드의 이전을 현재 노드로 설정

    free(toDelete); // 메모리 해제
    return data; // 삭제한 노드의 데이터 반환
}
// 순위 r의 원소 반환
char get(DList *L, int r){
    Node *current = L->header; // 순회용 포인터
    for (int i = 0; i < r && current->next != L->trailer; i++){
        current = current->next; // r번째 노드로 이동
    }
    
    if (current->next == L->trailer) {
        return '\0'; // r이 리스트의 길이보다 크면 빈 문자 반환
    }

    return current->next->data; // r번째 노드의 데이터 반환
}

// 리스트 내용을 순서대로 공백 없이 출력
void printList(DList *L){
    Node *current = L->header->next; // 헤더 다음 노드부터 시작
    while (current != L->trailer) { // 트레일러 노드까지 순회
        printf("%c", current->data); // 데이터 출력
        current = current->next; // 다음 노드로 이동
    }
    printf("\n"); // 줄바꿈
}

int main()
{
    DList L;
    initList(&L); // 리스트 초기화

    int N, r;
    char e;

    // 입력: N, r, e
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d %c", &r, &e);
        add(&L, r, e); // 순위 r에 문자 e 삽입
    }

    // 출력: 리스트
    printList(&L);

    // 입력: r
    scanf("%d", &r);
    char deletedChar = delete(&L, r); // 순위 r의 노드 삭제 후 원소 반환
    printf("%c\n", deletedChar); // 삭제한 원소 출력

    // 입력: r
    scanf("%d", &r);
    char getChar = get(&L, r); // 순위 r의 원소 반환
    printf("%c\n", getChar); // 반환한 원소 출력

    return 0;
}

