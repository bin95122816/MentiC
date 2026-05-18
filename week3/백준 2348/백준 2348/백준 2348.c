#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct DListNode {
	int item; //쪽지에 적힌 숫자
	int index; //풍선의 번호
	struct DListNode* llink; //왼쪽 노드 주소
	struct DListNode* rlink; //오른쪽 노드 주소
}DListNode;

void init(DListNode* head) { //head만 있을 때 자기 자신을 가리켜야함
	head->llink = head; 
	head->rlink = head;
}

void dinsert(DListNode* before, int item, int index) { //before 뒤에 삽입
	DListNode* node = (DListNode*)malloc(sizeof(DListNode)); //새로운 노드를 만든다 
	node->item = item; //풍선에 쪽지를 넣고
	node->index = index; //풍선에 번호도 매긴다
	node->llink = before; //새로운 노드를 before 노드에 연결한다
	node->rlink = before->rlink; ///새로운 노드를 before 노드의 다음 노드와 연결한다
	before->rlink->llink = node; //원래 before 오른쪽에 있던 노드를 새 노드를 연결시킨다
	before->rlink = node; //before노드를 새 노드에 연결시킨다

}

void ddelete(DListNode* head, DListNode* removed) {
	if (removed == NULL) //삭제할 노드가 없다면 반환
		return;
	removed->llink->rlink = removed->rlink; //삭제할 노드의 왼쪽에 있는 노드를 오른쪽 노드에 연결시킨다
	removed->rlink->llink = removed->llink; //삭제할 노드의 오른쪽에 있는 노드를 왼쪽 노드에 연결시킨다
	free(removed); //메모리 해제한다
}



DListNode* boom(DListNode* head, DListNode *current) { 
	if (current == head) //현재 풍선이 head이면 터트릴 풍선이 없는 것이다
		return current;

	int index = current->index; //현제 픙선의 쪽지 숫자를 저장한다
	int item = current->item;  //현재 풍선의 번호를 저장한다
	printf("%d ", index); //터진 풍선의 번호를 출력한다


	if (item > 0) { //쪽지가 양의 숫자면 오른쪽으로 이동해야함!

		//한 칸 이동 후 삭제함
		DListNode* removed = current; //터진 풍선의 위치를 removed에 저장한다
		current = current->rlink; //current는 삭제한 노드의 오른쪽 위치 (1칸 이동함)

		ddelete(head, removed); //삭제. 

		if (current == head)  //이동한게 head이면 다시 오른쪽으로
			current = current->rlink;

		for (int i = 1; i < item; i++) { //item-1 만큼 더 이동해야하므로 i=1부터 시작한다
			current = current->rlink; //한 칸 이동 후
			if (current == head) //이동할때마다 현재 가리키는게 head인지 확인한다 
				current = current->rlink; //head면 한 칸 더 오른쪽으로 이동한다
		}
	}
	else if (item < 0) { //반대로 쪽지가 음의 숫자면 왼쪽으로 이동해야함

		//한 칸 이동 후 삭제함
		DListNode* removed = current; //터진 풍선의 위치를 removed에 저장한다
		current = current->llink; //current는 삭제한 노드의 왼쪽 위치 (1칸 이동함)

		ddelete(head, removed); //터진 풍선 삭제

		if (current == head) //이동한게 head이면 
			current = current->llink; //다시 왼쪽으로 이동

		for (int i = 1; i < -item; i++) { //한 칸 이동했으므로 1부터 시작한다
			current = current->llink; //이동한다
			if (current == head) //이동한 위치가 head이면 
				current = current->llink; //다시 왼쪽으로 이동

		}
	}
	return current; //이동한 위치를 반환한다
}

int main(void) {
	DListNode* head = (DListNode*)malloc(sizeof(DListNode));
	int n, item, index; //n은 풍선의 개수, item은 종이의 숫자, index는 몇 번째 풍선인가

	init(head); //head 노드 초기화

	scanf("%d", &n); //풍선의 개수를 입력받는다


	for (int i = 1; i <= n; i++) {
		scanf("%d", &item); //n만큼 숫자를 입력받을텐데 각 숫자는 풍선에 적힌 쪽지의 숫자이다
		dinsert(head->llink, item, i); //넣을 위치, 쪽지의 숫자, 풍선의 번호를 넣어 호출(생성)한다
	}
	DListNode* current = head->rlink; //current는 터트릴 풍선 위치. // 처음에는 1번 풍선이 터져야하므로 첫 번째 노드에 배치
	for (int i = 0; i < n; i++) { //n개의 숫자만큼 반복 
		current = boom(head, current); //이동한 위치를 반환하여 current에 저장한다
	}

	return 0;
}