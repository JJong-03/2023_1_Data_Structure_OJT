#define _CRT_SECURE_NO_WARNINGS
//1137번 Stack의 이해
#if 0
#include<stdio.h>
#define STACK_SIZE 5
int stack[STACK_SIZE];
int top = -1;
int isFull() {
	return(top == STACK_SIZE - 1);
}
int isEmpty() {
	return(top == -1);
}
void push(int v) {
	if (isFull()) {
		return;
	}
	top++;
	stack[top] = v;
	return;
}
int pop() {
	if (isEmpty()) {
		return -999;
	}
	int temp = stack[top];
	top--;
	return temp;
}
int main() {
	int n = 0;
	int d_i = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &d_i);
		push(d_i);
	}
	while (isEmpty() != 1) {

		printf("%d ", pop());
	}
}
#endif
//1138번 Queue의 이해
#if 0
#include<stdio.h>
#define Q_SZ 5
int queue[Q_SZ];
int front = 0;
int rear = 0;
int isFull() {
	return(front == (rear + 1) % Q_SZ);
}
int isEmpty() {
	return(front == rear);
}
void enque(int v) {
	if (isFull()) {
		return;
	}
	queue[rear] = v;
	rear = (rear + 1) % Q_SZ;
	return;
}
int deque() {
	if (isEmpty()) {
		return -999;
	}
	int temp = queue[front];
	front = (front + 1) % Q_SZ;
	return temp;
}

int main() {
	int n = 0;
	int d_i = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &d_i);
		enque(d_i);
	}
	
	while (isEmpty() != 1) {
		printf("%d ", deque());
	}
	return 0;
}
#endif
//1139번 이상한 나라의 Stack(100이 들어가는 순간 stack에 들어 있던 모든 값들이 없어지고 그 값들의 합만 남게 된다.)
#if 0
#include<stdio.h>
#define STACK_SIZE 100
int stack[STACK_SIZE];
int top = -1;
int isFull() {
	return(top == STACK_SIZE - 1);
}
int isEmpty() {
	return(top == -1);
}
void push(int v) {
	if (isFull()) return;
	
	top++;
	stack[top] = v;
	return;
}
int pop() {
	if (isEmpty()) return -999;

	int temp = stack[top];
	top--;
	return temp;
}


int main() {
	int n = 0, d_i = 0, cnt = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int v1 = 0;
		scanf("%d", &d_i);
		if (d_i == 100) {
			for (int j = 0; j < cnt; j++) {
				v1 = v1 + pop();
			}
			push(v1);
			cnt = 1;
		}
		else {
			push(d_i);
			cnt++;
		}
	}
	while (isEmpty() != 1) {
		printf("%d ", pop());
	}
	return 0;
}
#endif