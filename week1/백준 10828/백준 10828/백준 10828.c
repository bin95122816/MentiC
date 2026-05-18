#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define MAX_STACK_SIZE 1000

//int를 element로 이용
typedef int element;

//구조체를 이용한 구조체
typedef struct {
    element data[MAX_STACK_SIZE];
    int top;
}StackType;

//기본 세팅
void init_stack(StackType* s) {
    s->top = -1;
}

//스택이 비면 1, 아니면 0 반환 
int empty(StackType* s) {
    return (s->top == -1);
}

//스택에 값 넣기
void push(StackType* s, element item) {
    s->data[++(s->top)] = item;
}

//스택에 들어있는 수 만큼 반환
int size(StackType* s) {
    return s->top + 1;
}

//스택에 있는 값 없애면서 반환
element pop(StackType* s) {
    if (empty(s)) {
        return -1;
    }
    return s->data[(s->top)--];
}

//스택 맨 위 값 반환
element peek(StackType* s) {
    if (empty(s)) {
        return -1;
    }
    return s->data[s->top];
}

int main(void) {

    int n, item; //n은 반복 횟수
    char str[10]; //함수이름 받기
    StackType s;

    init_stack(&s);


    scanf("%d", &n); //반복횟수 입력받기
    for (int i = 0; i < n; i++) {
        scanf("%s", str); // 무슨 함수를 실행할지 받기
        if (strcmp(str, "push") == 0) {
            scanf("%d", &item); //! scanf는 분리자를 통해 입력받을 부분은 끊음
            push(&s, item);     // 따라서 push는 str에 ' '건너뛰고 숫자는 item에 저장 //이 부분은 gpt 도움 받았습니다..
        }
        else if (strcmp(str, "pop") == 0) {
            printf("%d\n", pop(&s));
        }
        else if (strcmp(str, "size") == 0) {
            printf("%d\n", size(&s));
        }
        else if (strcmp(str, "top") == 0) {
            printf("%d\n", peek(&s));
        }
        else if (strcmp(str, "empty") == 0) {
            printf("%d\n", empty(&s));
        }
    }
    return 0;
}