//백준 9012번
#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define MAX_STACK_SIZE 1000

typedef char element;
typedef struct {
    element data[MAX_STACK_SIZE];
    int top;
}StackType;

void init_stack(StackType* s) {
    s->top = -1;
}

int empty(StackType* s) {
    return (s->top == -1);
}


void push(StackType* s, element item) {
    s->data[++(s->top)] = item;
}

int size(StackType* s) {
    return s->top + 1;
}

element pop(StackType* s) {
    if (empty(s)) {
        return -1;
    }
    return s->data[(s->top)--];
}

element peek(StackType* s) {
    if (empty(s)) {
        return -1;
    }
    return s->data[s->top];
}

int check(element* str) {

    StackType s;
    init_stack(&s);

    for (int i = 0; i < strlen(str); i++) {
        char ch = str[i]; //문자 하나씩 검토
        switch (ch) {
        case '(': // 여는 괄호면 무조건 push
            push(&s, ch);
            break;
        case ')':
            if (empty(&s))  //닫는 괄호면 일단 스택이 비었나 확인
                return 0; //비었으면 0
            pop(&s);
            break;
        }

    }
    if (empty(&s)) //모든 탐색이 끝난 후 스택에 안 남아있으면 1
        return 1;
    return 0;
}

int main(void) {

    int n;
    char str[100];
    ;
    scanf("%d", &n);
    getchar();
    for (int i = 0; i < n; i++) {
        fgets(str, 100 * sizeof(element), stdin);
        int key = check(str);
        if (key == 1)
            printf("YES\n");
        else
            printf("NO\n");

    }

    return 0;
}