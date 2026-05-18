#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode{
	int type; //0이면 큐, 1이면 스택
	int data; //숫자를 저장한다
	struct ListNode* link; //다음 노드를 가리킨다
}ListNode;

//우선 큐인지 스택인지 입력받고 끝에 노드를 생성한다. 
//큐면 0, 스택이면 1이다.
ListNode* insert_last_type(ListNode* head, int type) { 
	ListNode* node = (ListNode*)malloc(sizeof(ListNode)); //새로운 노드 생성
	node->type = type; //타입 저장
	if (head == NULL) { //노드가 없으면 생성한 노드가 헤드
		head = node; //헤드는 노드다.
		node->link = head; //노드는 헤드를 가리킨다.
		//즉 노드가 헤드는 같은 주소(위치)를 가지므로 본인이다
	}
	else {
		node->link = head->link; //새 노드를 기존 첫 번째 노드를 가리키게 한다.
		head->link = node; //기존 헤드(끝노드)가 새 노드를 가리키게 한다
		head = node; //헤드를 바꾼다.
	} 
	return head; //바뀐 헤드를 반환한다
}

//숫자를 각 노드에 맞게 삽입한다
void add_data(ListNode* head, int data, int n) { //data는 숫자고, n은 몇 번째 노드에 삽입인지 나타내는 것이다.  
	ListNode* p = head; //우선 p가 헤드가
	for (int i = 0; i < n; i++) { //head는 끝 노드를 가리키므로 n이 1이면 첫 번째 노드로 이동하게 된다.
		p = p->link; //다음 노드로 넘어간다
	}
	p->data = data; //data에 숫자를 넣는다
}

//큐이면 값을 빼서 반환하고 push값을 넣어준다
int change_data(ListNode* head, int c, int push) { //c는 몇 번째 숫자(노드)인지를 의미하고, push는 넣어줘야할 값이다. 
	ListNode* p = head->link; 
	for (int i = 0; i < c; i++) {
		p = p->link; //해당 숫자의 노드까지 이동한다
	}
	int tmp = p->data; //숫자를 빼내어 tmp에 저장한다
	p->data = push; //빼낸 숫자 대신 새로운 값(push)을 넣어준다
	return tmp; //빼낸 숫자를 반환한다
}


int main(void) {
	ListNode* head = NULL;
	int number[10]; //큐에 넣을 값들의 모임이다
	int n, m, type, data; //n은 몇 개의 입력을 나타냄, m은 큐에 넣을 값의 수, type은 큐인지 스택인지, data는 숫자
	int result; //최종 결과를 나타낸다

	scanf("%d", &n); //통로에 몇 개의 숫자를 넣을지 입력받아 n에 저장한다

	for (int i = 0; i < n; i++) { //n개 반복
		scanf("%d", &type); //type을 입력받아
		head = insert_last_type(head, type); //우선 노드를 생성한다
	}

	//1부터 시작하는 이유! head는 현재 마지막 노드를 가리키고 있으므로 무조건 1번은 이동하고 시작해야한다
	for (int i = 1;  i <= n; i++) { 
		scanf("%d", &data); //통로 안 숫자를 지정해준다
		add_data(head, data, i); //지정한 숫자를 넣는다
	}

	scanf("%d", &m); //큐에 넣을 값의 개수를 적는다

	for (int i = 0; i < m; i++) { //큐에 넣을 숫자를 
		scanf("%d", &number[i]); //배열에 저장한다
	}

	for (int r = 0; r < m; r++) {
		ListNode* p = head; //임의의 p를 만든다
		result = number[r]; //우선 큐에 넣을 값을 result에 저장한다
		for (int c = 0; c < n; c++) { //통로의 개수만큼 반복한다
			p = p ->link; //head가 마지막 원소이므로 기본적으로 1을 이동하고 시작한다
			if (p->type == 0) { //큐이면
				 result= change_data(head, c, result); // 값을 바꿔주고 반환한다
			} 
		}
		printf("%d ", result); //1패스가 끝났으므로 출력한다
	}
	

	return 0;
}

