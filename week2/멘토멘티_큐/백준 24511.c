#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAX_SIZE 100

typedef int element;

typedef struct {
	element data[MAX_SIZE];
	element type[MAX_SIZE];
}QueueStack;

//스택은 변화x
//큐는 기존 것이 반환되고 새로운 것을 넣어야 함
//따라서 tmp 써서 두 변수를 교환하는 방식으로!
element endeque(QueueStack* q, element item, int j) { //item이 들어온 값이고, j는 q->data의 인덱스 위치
	int tmp = q->data[j];
	q->data[j] = item;
	return tmp;
}

int main(void) {

	QueueStack q;

	int n, k, w;
	int tmp[30];


	scanf("%d", &n); //원소의 수
	for (int i = 0; i < n; i++) { //큐인가 스택인가
		scanf("%d", &k);
		q.type[i] = k;
	}

	for (int i = 0; i < n; i++) { //어떤 값을 지녔는가
		scanf("%d", &k);
		q.data[i] = k;
	}

	scanf("%d", &w); //몇 개 넣을 것인가
	for (int i = 0; i < w; i++) {
		scanf("%d", &k);
		tmp[i] = k;
	}

	for (int i = 0; i < w; i++) { //w의 개수만큼 돌아야함 
		for (int j = 0; j < n; j++) { // q.data의 요소를 한 번씩 지나쳐야함. 
			if (q.type[j] == 0) { //타입이 큐면
				tmp[i] = endeque(&q, tmp[i], j); //반환된 값으로 순회

			}
		}
		printf("%d ", tmp[i]);
	} 
	printf("\n");

}