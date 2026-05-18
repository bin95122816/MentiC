#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode {
    int data; //data는 사람의 번호
    struct ListNode* link; // link는 다음 노드를 가리킨다
}ListNode;

ListNode* inser_last(ListNode* head, int value) { 
    ListNode* node = (ListNode*)malloc(sizeof(ListNode)); //새 노드를 생성한다
    node->data = value; //값을 저장한다
    if (head == NULL) { //head가 NULL이면 새 노드가 head이다
        head = node; //head는 node이다
        node->link = head; //따라서 node가 가리키는 값은 자기자신(head)이다
    }
    else {
        node->link = head->link; //node가 가리키는 값은 head가 가리키는 값이다. 즉, 새로운 노드가 헤드를 가리킨다
        head->link = node; //head가 가리키는 값은 node로 바뀐다. 즉, 마지막 노드가 새로운 노드를 가리킨다
        head = node;  //head는 node로 바뀐다. 
    }
    return head; //새로운 head를 반환한다
}

ListNode* delete(ListNode* head, int k) { //k번째 노드(사람)을 삭제한다
    int i = 0; //i는 몇 번째 노드인지 세는 용도이다.

    ListNode* pre = head;; //pre는 삭제할 노드의 이전 노드
    ListNode* p = head; //p는 삭제할 노드
    if (head == NULL) { //NULL이면 삭제할 노드가 없다 (끝이란 이야기다)
        return;
    }
    while (k > i) {  //이동할 때마다 i가 1씩 증가한다
        p = p->link; //다음 노드로 이동한다 
        if (k > i-1) //k가 삭제할 사람 위치이면 pre는 그 전 사람이므로, 마지막에 pre는 이동하지 않는다
            pre = p;
        i++; //한 번 돌렸으므로 i는 1 증가한다
    }
    ListNode* removed = pre->link; //삭제할 노드를 pre가 가리킨다
    printf("%d ", removed->data); ///삭제할 노드가 몇 번째 사람인지 출력한다
    pre->link = removed->link; //이전 노드는 삭제할 노드가 가리키는 노드를 가리킨다
    free(removed); //삭제할 노드 메모리 해제
    head = pre; //head가 시작할 때부터 한 칸 전을 가리켰으므로 head = pre이다. (insert_last. 즉 마지막 노드가 head)
    return head; //헤드를 반환한다
}

int main(void) {
    ListNode* head = NULL;
    int n, k; // n은 n명의 사람, k는 k번째 사람 제거 
    scanf("%d %d", &n, &k); //n과 k를 입력받는다
    for (int i = 0; i < n; i++) { //n만큼 입력받길 반복한다
        head = inser_last(head, i + 1); //1부터 n까지의 숫자를 넣는다
    }

    printf("< ");
    for (int i = 0; i < n; i++) { //n만큼 제거하길 반복한다
        head = delete(head, k); //k번째 사람을 제거한다 //출력은 delete함수에서 한다
    }
    printf(" >");

    return 0;
}