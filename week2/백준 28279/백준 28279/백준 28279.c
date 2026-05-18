#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef int element;
int count = 0; //노드의 수를 0으로 초기화한다

typedef struct ListNode{
	element data;
	struct ListNode* link;
}ListNode;

// 1번
ListNode* insert_first(ListNode* head, element data) { 
	ListNode* node = (ListNode*)malloc(sizeof(ListNode)); //새 노드를 생성한다
	node->data = data; //새 노드에 값을 넣는다
	if (head == NULL) { //노드가 하나도 없다면
		head = node; //헤드는 새 노드가 된다
		node->link = head; //새 노드가 가리키는건 헤드, 즉 자기자신이다 
	}
	else { //노드가 이미 있다면
		node->link = head->link; //새노드는 첫 번째 노드를 가리킨다
		head->link = node; //헤드는 (첫 번째 노드가 된)새 노드를 가리키게 된다.
	}
	count++; //노드의 수를 증가시킨다
	return head; //head를 반환한다
}

// 2번
ListNode* insert_last(ListNode* head, element data) {
	ListNode* node = (ListNode*)malloc(sizeof(ListNode)); //새 노드를 생성한다
	node->data = data; //새 노드에 값을 넣는다
	if (head == NULL) { //노드가 없다면
		head = node; //새 노드를 헤드가 된다. 
		node->link = head; //새 노드가 헤드를 가리킨다. 즉, 자기자신을 가리킨다
	}
	else { //노드가 있다면
		node->link = head->link; //새 노드는 첫 번째 노드를 가리킨다. 
		head->link = node; //마지막 노드는 새 노드를 가리키게 된다
		head = node; //새 노드가 헤드가 된다. 즉, 새노드가 마지막 노드가 된다 
	}
	count++; //노드의 수를 증가시킨다
	return head; //헤드를 반환한다
}

// 3번
ListNode* delete_first(ListNode* head, element* delete_result) {
	if (head == NULL) { //노드가 비어있다면
		*delete_result = -1; //-1을 저장한다
		return head; //헤드를 반환한다
	}
	ListNode* removed = head->link; //removed는 삭제할 노드를 의미한다
	*delete_result = removed->data; //해당 노드의 값을 저장한다
	if (removed == head) { //삭제할 노드가 헤드라면
		free(removed); //메모리를 해제한다
		count--; //노드가 수를 하나 줄인다
		return NULL; //유일한 노드를 없앴으므로 헤드는 NULL이다
	}
	else { //삭제할 노드가 2개 이상이라면
		head->link = removed->link; //마지막 노드가 두 번째 노드를 가리키게 한다
		free(removed); //노드를 삭제한다
		count--; //노드의 수를 하나 줄인다
		return head; //헤드를 반환한다
	}
	
}

// 4번
ListNode* delete_last(ListNode* head, element* delete_result) {
	if (head == NULL) { //헤드가 비어있으면
		*delete_result = -1; //-1을 저장한다
		return NULL; //헤드는 NULL을 반환한다
	}
	ListNode* removed = head; //removed에 마지막 요소(헤드)를 저장한다
	*delete_result = removed->data; // 삭제할 노드의 값을 저장한다
	if (head->link == head) { //노드가 하나뿐이면
		free(removed); // 하나뿐인 노드를 삭제한다
		count--; //수를 하나 줄인다
		return NULL; //헤드는 NULL로 한다
	}
	ListNode* pre = head->link; //삭제할 노드 이전을 의미하는 pre 노드
	while (pre->link != head) { //pre로 head의 바로 전 노드를 의미하도록 한다
		pre = pre->link;
	}
	pre->link = head->link; //이전노드가 첫 번째 노드를 가리키도록 한다. (원형 완성)
	free(removed); //메모리를 해제한다
	count--; //수를 하나 줄인다
	return pre; //pre가 헤드가 된다
}

//7번 
int get_front(ListNode* head) {
	if (head == NULL) { //노드가 없다면 -1을 반환한다
		return -1;
	}
	ListNode* p = head->link; //head가 가리키는 노드가 첫 번째 노드이다
	return p->data; //첫 번째 노드의 값을 반환한다
}

//8번
int get_rear(ListNode* head) {
	if (head == NULL) { //노드가 없으면 
		return -1; //-1을 반환한다
	}
	ListNode* p = head; // p는 마지막 노드를 의미한다
	return p->data; //마지막 노드의 값을 반환한다
}

int main(void) {
	ListNode* head = NULL; //노드를 생성한다
	int n, choice, item, delete_result; //n은 반복 횟수, choice는 어떤 함수를 실행할 것인가, 
	//item은 1과 2를 실행했을 때 넣을 것, delete_result는 노드를 삭제했을 때 반환할 것

	scanf("%d", &n); //반복할 횟수를 입력받아 n에 저장한다
	for (int i = 0; i < n; i++) { //n번 반복한다
		scanf("%d", &choice); //무슨 함수를 실행할지 입력받아 choice에 저장한다

		switch (choice) { //switch문을 이용하여 우선 함수를 실행한다
		case 1: //단, 1과 2는 넣을 값을 추가로 입력받는다
			scanf("%d", &item); 
			head = insert_first(head, item); //맨 앞에 노드를 생성하여 값을 넣는다
			break;
		case 2:
			scanf("%d", &item);
			head = insert_last(head, item); //맨 뒤에 노드를 생성하여 값을 넣는다
			break;
		case 3:
			head = delete_first(head, &delete_result); //맨 앞 노드를 삭제하며 해당 값을 delete_result에 저장한다
			//printf("출력: ");
			printf("%d\n", delete_result); //맨 앞 노드였던 것의 값을 출력한다
			break;
		case 4:
			head = delete_last(head, &delete_result); //맨 뒤 노드를 삭제하며 해당 값을 delete_result에 저장한다
			//printf("출력: ");
			printf("%d\n", delete_result); //맨 뒤 노드였던 것의 값을 출력한다
			break;
		case 5:
			//printf("출력: ");
			printf("%d\n", count); //노드의 수를 출력한다. 
			break;
		case 6:
			//printf("출력: "); 
			if (count == 0) //노드의 수가 0이면 
				printf("1\n"); //참이라는 뜻으로 1을 출력하고
			else printf("0\n"); //거짓이면 0을 출력한다
			break;
		case 7:
			//printf("출력: ");
			printf("%d\n", get_front(head)); //첫 번째 노드의 값을 반환한다
			break;
		case 8:
			//printf("출력: ");
			printf("%d\n", get_rear(head)); //두 번째 노드의 값을 반환한다
			break;
		default:
			printf("잘못된 입력\n"); //해당되지 않는 숫자를 입력하면 출력한다
			break;
		}
	}
	return 0;
}