#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX_QUEUE_SIZE 100

typedef int element;

typedef struct {
	element data[MAX_QUEUE_SIZE];
	int front, rear;
	int count; //get_size 함수를 구현하기 위한 용도
}QueueType;

void init_queue(QueueType* q) {
	q->front = 0;
	q->rear = 0;
	q->count = 0;
	return;
}

int is_empty(QueueType* q) { // 6 
	return q->front == q->rear; // front와 rear가 같으면 큐 공백 상태
}								// 참이면 1, 거짓이면 0

element get_front(QueueType* q) { // 7
	if (is_empty(q)) {
		return -1; // 큐가 비어있으면 -1 반환
	}
	return q->data[(q->front+1)%MAX_QUEUE_SIZE]; //front는 첫 원소의 앞을 가리키므로 +1을 해줘야 함
}

element get_rear(QueueType* q) { // 8
	if (is_empty(q)) {
		return -1; //큐가 비어있으면 -1 반환
	}
	return q->data[q->rear]; //rear는 마지막 원소를 가리키므로 그대로 반환
}

int get_size(QueueType* q) {// 5
	return q->count;

}

void add_front(QueueType *q, element item) { //1
	q->data[q->front] = item; //rear 위치에 값 저장
	q->front = (q->front - 1 + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE; //front 위치를 앞으로 옮김. //원형큐이므로 전체 사이즈로 나눠서 나머지
	q->count++; // 원소가 추가되었으므로 개수 증가
	return;
}

void add_rear(QueueType* q, element item) { //2
	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE; //rear 위치를 뒤로 옮김
	q->data[(q->rear)] = item; // rear 위치에 저장
	q->count++;
	return;
}

element delete_front(QueueType* q) { //3
	if (is_empty(q)) {
		return -1;
	}
	q->front = (q->front + 1) % MAX_QUEUE_SIZE; //front 위치를 뒤로(첫 번째 원소 위치)로 옮긴다
	q->count--; //원소 삭제 되었기 때문에 -1
	return q->data[q->front]; //원소 반환
}

element delete_rear(QueueType *q){ //4
	if (is_empty(q)) {
		return -1;
	}
	element tmp = q->data[q->rear]; //삭제할 원소 임시 저장
	q->rear = (q->rear - 1 + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE; //rear의 위치를 앞으로 옮긴다
	return tmp;
}

int main(void) {


	int n; //반복 횟수
	int cmd, item; //어떤 메소드, 어떤 값
	QueueType q; //포인터로 선언

	init_queue(&q); //호출 

	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%d", &cmd);
		if (cmd == 1 || cmd == 2) {
			scanf("%d", &item);
			getchar();	
		}


		switch (cmd) {
		case 1:
			add_front(&q, item);
			break;
		case 2:
			add_rear(&q, item);
			break;
		case 3:
			//printf("출력: ");
			printf("%d\n", delete_front(&q));
			break;
		case 4:
			//printf("출력: ");
			printf("%d\n", delete_rear(&q));
			break;
		case 5:
			//printf("출력: ");
			printf("%d\n", get_size(&q));
			break;
		case 6:
			//printf("출력: ");
			printf("%d\n", is_empty(&q));
			break;
		case 7:
			//printf("출력: ");
			printf("%d\n", get_front(&q));
			break;
		case 8:
			//printf("출력: ");
			printf("%d\n", get_rear(&q));
			break;
		}
	
	}

	return 0;
}
