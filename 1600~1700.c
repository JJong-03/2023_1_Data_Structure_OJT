#define _CRT_SECURE_NO_WARNINGS
//1625 Stack, 맨 앞과 맨 뒤에 있는 숫자의 합을 출력.
#if 0
#include<stdio.h>
#include<stdlib.h>
#define STACK_SIZE 20
int stack[STACK_SIZE];
int top = -1;
int isEmpty() {
	return(top == -1);
}
int isFull() {
	return (top == STACK_SIZE -1);
}
int pop() {
	if (isEmpty()) { return -999; }
	int temp = stack[top];
	top--;
	return temp;
}
void push(int v) {
	if (isFull()) { return; }
	top++;
	stack[top] = v;
	return;
}
int main() {
	int n = 0;
	while (1) {
		scanf("%d", &n);
		if (n == -1) pop();
		else if (n == 0) break;
		else { push(n); }
	}
	// 0이 입력된 경우
	if (top <= -1) {
		printf("-999");
	}
	else {
		 printf("%d", stack[top] + stack[0]);
	}
	return 0;
}
#endif
//1626 Queue, 맨 앞과 맨 뒤에 있는 숫자의 합을 출력.
#if 0
#include <stdio.h>

#define Q_SZ 10  //최대 9개, circular queue일 경우
int que[Q_SZ];
int front = 0;  // 중요한 위치 변수, 
int rear = 0;

int isEmpty() {
	return (front == rear);
}

int isFull() {  // rear 뒤에 front가 있으면, full
	return  (((rear + 1) % Q_SZ) == front);
}

void enqueue(int _v) {
	if (isFull()) {
		return;
	}
	// rear가 가리키고 있는 현재 위치에 넣는다.
	que[rear] = _v;
	// rear를 1개 증가시킨다.,, 항상 한바퀴 돌아가는 경우를 생각
	rear = (rear + 1) % Q_SZ;
	return;
}

int dequeue(void) {
	// empty 체크
	if (isEmpty()) {
		return -999; // error 표시, -999
	}
	// front 위치에 있는 것 뽑기
	int result = que[front];

	// front 조정
	front = (front + 1) % Q_SZ;

	// 뽑아 놓은 것 반환
	return result;
}

int main() {
	int n = 0;
	while (1) {
		scanf("%d", &n);
		if (n == -1) dequeue();
		else if (n == 0) break;
		else { enqueue(n); }
	}
	// 0이 입력된 경우
	if (rear <= 0) {
		printf("-999");
	}
	else {
		printf("%d", que[rear - 1] + que[front]);
	}
	
	return 0;
}
#endif
//1627 SLL 홀수는 맨 앞에 저장되어야 한다.
#if 0
#include <stdio.h>
#include <stdlib.h>   // malloc 때문에 필요

// linked list의 기본 요소인 node
// Linked List : LL
// Singly Linked List : SLL
typedef struct node {
	int data;
	struct node* next;
}node;
node* head = 0;
// stack에 top, queue에는 front/rear, linked list에는 head


// _v 정수값을 SLL의 끝에 추가한다.
// 점점 늘어나는 리스트의 역할
//
void addToSLL(int _v) {

	// _v값을 저장할 node를 메모리에 마련한다.
	// data type을 casting하는 이유
	//   malloc의 반환값은 void*
	//   type이 없으므로 (void), 적절한 type으로 casting
	// _new는 새로 할당받은 node 구조체의 주소를 가리키고 있다.
	//
	// 주의!! _new를 잃어버리면, 할당받은 공간을 다시 찾아갈 방법이 없음.
	//
	node* _new = (node*)malloc(sizeof(node));
	// -> 화살표를 사용하는 이유: _new가 포인터이기 때문에
	_new->data = _v;
	_new->next = 0; // 신규 노드는 뒤에 오는 노드가 없으므로, 0(null)로 초기화

	// _new를 기존 SLL에 추가

	// 경우의 수, 2가지
	// 1. 빈 SLL일 경우
	if (head == 0) {
		head = _new;
		return;
	}
	// 2. 아닌 경우

	// 2.1 기존 SLL에서 맨 끝의 노드의 주소를 알아낸다.
	node* temp = head; //new값이 들어간 head를 temp에 넣는다.
	while (temp->next != 0) {
		temp = temp->next;
	}

	// 2.2 맨끝 노드의 next에 새로운 노드의 주소를 집어넣는다.
	temp->next = _new;
	return;
}

void displaySLL(void) {

	node* temp = head;
	printf("%d ", temp->data);
	head = head->next;
	
	return;
}


// _v를 가진 노드를 맨 앞에 추가
void addToFront(int _v) {
	// 새로운 node를 1개 할당받아서, _v를 저장, 그 노드를 _new가 가리킨다.
	node* _new = (node*)malloc(sizeof(node));
	_new->data = _v;
	_new->next = 0;

	// 경우의 수. 1 SLL== empty
	if (head == 0) {
		head = _new;
		return;
	}

	// 경우의 수. 2, SLL에 뭔가 있을 때.
	_new->next = head;   // SLL의 대원칙 == 인생의 대원칙 == 새로온 사람이 아쉽다. == 아쉽손
	head = _new;
	
	return;
}


int main(void) {
	int n = 0, cnt = 0;
	while (1) {
		scanf("%d", &n);
		if (n == 0) {
			break;
		}
		else if (n % 2 != 0) {
			if (head == 0) {
				addToSLL(n);
				cnt++;
			}
			else if (head->data % 2 == 0) {
				addToFront(n);
				cnt++;
			}
		
			else if (head->data % 2 != 0) {
				node* temp = head;
				while (temp != 0) {
					if ((temp->next->data) % 2 == 0) {
						break;
					}
					
					temp = temp->next;	
				} // 1 2 3 4 / 3이 들어갈 때 1이 temp다.
				node* _new = (node*)malloc(sizeof(node));
				_new->data = n;
				_new->next = 0;

				_new->next = temp->next; 
				temp->next = _new;
				

				cnt++;
			}
		}
		else if(n % 2 == 0) {
			addToSLL(n);
			cnt++;
		}
	}
	for (int i = 0; i < cnt; i++) {
		displaySLL();
	}
	
	return 0;
}
#endif

//1628 DLL, 홀수는 항상 앞쪽에 입력, 짝수는 뒤에 
#if 0
#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node* next;
	struct node* prev;     
};

struct node* head = 0;


struct node* createNode(int _v) {

	struct node* _new = (struct node*)malloc(sizeof(struct node));
	_new->data = _v;
	_new->next = _new->prev = 0;
	return _new;

}

void addToDLL(int _v) {

	struct node* _new = createNode(_v);

	if (head == 0) {   
		head = _new;
		return;
	}

	
	struct node* spear = head;
	while (spear->next != 0) {      
		spear = spear->next;
	}

	spear->next = _new;
	_new->prev = spear;
	return;

}

void displayReverseDLL(void) {

	if (head == 0) {  
		return;
	}

	struct node* spear = head;
	while (spear->next != 0) {  
		spear = spear->next;
	}

	while (spear != 0) {
		printf("%d ", spear->data);
		spear = spear->prev;
	}

	return;
}

struct node* oddEnd()
{
	struct node* temp = head;


	while (temp->next != 0) {
		if (temp->next->data % 2 == 0) {
			break;
		}
		temp = temp->next;
	}

	return temp;
}

void insertOddEndDLL(int _n) {

	struct node* ode = oddEnd();
	struct node* _new = createNode(_n);


	_new->prev = ode;
	_new->next = ode->next;  
	ode->next = _new;

	if (_new->next != 0) {   
		_new->next->prev = _new;    
	}
	return;

}
void addToFront(int _v) {

	struct node* _new = createNode(_v);

	_new->next = head;
	head->prev = _new;
	head = _new;
	return;
}


int main(void) {
	int n = 0;
	while (1) {
		scanf("%d", &n);
		if (n == 0) {
			break;
		}
		else if (n % 2 == 0 || head == 0) { // head == 0을 먼저 판단하기 위해 위에 있어야한다.
			addToDLL(n);
		}
		else if (n % 2 != 0) {
			if (head->data % 2 == 0) {
				addToFront(n);
			}
			else if(head->data % 2 != 0) {
				insertOddEndDLL(n);
			}
		}
	
	}

	displayReverseDLL();
	return 0;
}
#endif
//1629 Recursion Fibonacci
#if 0
#include<stdio.h>
int fibo(int n) {
	if (n == 0) {
		return 0;
	}
	if (n == 1) {
		return 1;
	}
	return  fibo(n-1 ) + fibo(n-2);
}

int main() {
	int n = 0;
	scanf("%d", &n);
	printf("%d", fibo(n));
	return 0;
}
#endif
//1630 Non-recursive Fibonacci
#if 0
#include<stdio.h>
	int fibo(int n) {
		if (n == 0) return 0;
		if (n == 1) return 1;

		int pp = 0; // previous~ previous
		int p = 1; //previous
		int result = 0;// 결과값
		for (int i = 2; i <= n; i++) {
			result = pp + p;
			pp = p;
			p = result;
		}
		return result;
	}

int main() {
	int n = 0;
	scanf("%d", &n);
	printf("%d", fibo(n));
	return 0;
}
#endif
//1631 SLL, Stack by SLL
#if 0
#include<stdio.h>
#include<stdlib.h>
typedef struct node {
	int data;
	struct node* next;
}node;
node* head = 0;

void push(int n) {
	node* _new = (node*)malloc(sizeof(node));
	_new->data = n;
	_new->next = 0;

	if (head == 0) {
		head = _new;
		return;
	}
	
	node* temp = head;
	while (temp->next != 0) {
		temp = temp->next;
	}
	temp->next = _new;
	return;
}
int pop() {
	if (head == 0) {
		return;
	}
	if (head->next == 0) {
		int res = head->data;
		free(head);
		head = 0;
		return res;
	}
	node* spear = head;

	while (spear->next->next != 0) {
		spear = spear->next;
	}
	int result = spear->next->data;
	free(spear->next);
	spear->next = 0;
	return result;
}
void displayAddSLL() {
	int result = 0;
	node* spear = head;
	while (spear!= 0) {
		result += spear->data;
		spear = spear->next;
	}
	printf("%d", result);
	return;
}


int main() {
	int n = 0;
	while (1) {
		scanf("%d", &n);
		if (n == 0) {
			break; 
		}

		else if (n == -1) {

			pop();
		}

		else { push(n); }
	}
	displayAddSLL();
	return 0;
}
#endif
//1632 Stack by DLL
#if 0
#include<stdio.h>
#include<stdlib.h>
typedef struct node {
	int data;
	struct node* prev;
	struct node* next;
}node;
node* head = 0;
node* createNode(int n) {
	node* _new = (node*)malloc(sizeof(node));
	_new->data = n;
	_new->next = _new->prev = 0;

	return _new;
}
void push(int n) {
	node* _new = createNode(n);
	if (head == 0) {
		head = _new;
		return;
	}
	node* temp = head;
	while (temp->next != 0) {
		temp = temp->next;
	}
	_new->prev = temp;
	temp->next = _new;
	return;
}
void pop() {
	if (head == 0) {
		return;
	}
	if (head->next == 0) {
		free(head);
		head = 0;
		return;
	}
	node* temp = head;
	while (temp->next->next!= 0) {
		temp = temp->next;
	}
	free(temp->next);
	temp->next = 0;
	return;
}
void displayDLL() {
	if (head == 0) {
		printf("-999");
		return;
	}
	node* temp = head;
	while (temp->next != 0) {
		temp = temp->next;
	}
	
	while (temp->prev != 0) {
		printf("%d ", temp->data);
		temp = temp->prev;
	}
	printf("%d ", temp->data);
	while (temp->next != 0) {
		printf("%d ", temp->data);
		temp = temp->next;
	}
	printf("%d ", temp->data);
	return;
}
int main() {
	int n = 0;
	while (1) {
		scanf("%d", &n);
		if (n == 0) {
			break;
		}
		else if (n == -1) {
			pop(n);
		}
		else { push(n); }
	}
	displayDLL();
	return 0;
}
#endif
/1633 Queue by SLL
#if 0
#include<stdio.h>
#include<stdlib.h>
typedef struct node {
	int data;
	struct node* next;
}node;
node* head = 0;

void enqueue(int n) {
	node* _new = (node*)malloc(sizeof(node));
	_new->data = n;
	_new->next = 0;
	if (head == 0) {
		head = _new;
		return;
	}
	node* temp = head;
	while (temp->next != 0) {
		temp = temp->next;
	}
	temp->next = _new;
	return;
}
int dequeue() {
	if (head == 0) {
		return;
	}
	if (head->next == 0) {
		int res = head->data;
		free(head);
		head = 0;
		return res;
	}
	node* spear = head;

	while (spear->next->next != 0) {
		spear = spear->next;
	}
	int result = spear->next->data;
	free(spear->next);
	spear->next = 0;
	return result;
}
void displayQueSLL() {
	int max = 0;
	node* spear = head;
	while (spear != 0) {
		if (max < spear->data) {
			max = spear->data;
		}
		spear = spear->next;
	}
	printf("%d", max);
	return;
}
int main() {
	int n = 0;
	while (1) {
		scanf("%d", &n);
		if (n == 0) break;
		else if (n == -1) dequeue();
		else { enqueue(n); }
	}
	displayQueSLL();
	return 0;
}
#endif
//1634 Queue by DLL
#if 0
#include<stdio.h>
#include<stdlib.h>
typedef struct node {
	int data;
	struct node* prev;
	struct node* next;
}node;
node* head = 0;

node* createNode(int n) {
	node* _new = (node*)malloc(sizeof(node));
	_new->data = n;
	_new->next = _new->prev = 0;

	return _new;
}
void enqueue(int n) {
	node* _new = createNode(n);
	if (head == 0) {
		head = _new;
		return;
	}
	node* temp = head;
	while (temp->next != 0) {
		temp = temp->next;
	}
	_new->prev = temp;
	temp->next = _new;
	return;
}
void dequeue() {
	if (head == 0) {
		return;
	}
	if (head->next == 0) {
		free(head);
		head = 0;
		return;
	}
	node* temp = head;
	head = head->next;
	free(temp);
	head->prev = 0;
	return;
}
int minDLL() {
	int min = 10000;
	node* temp = head;
	while (temp != 0) {
		if (min > temp->data) {
			min = temp->data;
		}
		temp = temp->next;
	}
	return min;
}
int maxDLL() {
	int max = 0;
	node* temp = head;
	while (temp != 0) {
		if (max < temp->data) {
			max = temp->data;
		}
		temp = temp->next;
	}
	return max;
}
node* findNode(int t) {
	node* spear = head;
	while (spear != 0) {
		if (spear->data == t) {
			return spear;
		}
		spear = spear->next;
	}
	return spear;
}
void delFromDLL(node* spear) {
	if (spear == 0) {
		return;
	}

	if (spear == head) {
		head = head->next;
		free(spear);
		if (head != 0) { 
			head->prev = 0;
		}
		return;
	}

	spear->prev->next = spear->next;
	if (spear->next != 0) {     
		spear->next->prev = spear->prev;
	}
	free(spear); 
	return;
}
int SameMaxMin() {
	if (maxDLL() == minDLL()) return 1;
	return 0;
}
void displayDLL(void) {

	if (head == 0) { 
		printf("0");
		return;
	}
	node* spear = head;
	
	while (1) {
		int min = 10000;
		while (spear->next != 0) {
			if (min > spear->data) {
				min = spear->data;
			}
			spear = spear->next;
		}
		if (min > spear->data) {
			min = spear->data;
		}
		printf("%d ", min);
		delFromDLL(findNode(min));
		if (head == 0) break;
		
		min = 10000;
		while (spear->prev != 0) {
			if (min > spear->data) {
				min = spear->data;
			}
			spear = spear->prev;
		}
		if (min > spear->data) {
			min = spear->data;
		}
		printf("%d ", min);
		delFromDLL(findNode(min));
		if (head == 0) break;
	}
	return;
}

int main() {
	int n = 0;
	while (1) {
		scanf("%d", &n);
		if (n == 0) break;
		else if (n == -1) dequeue(n);
		else enqueue(n);
	}
	if (SameMaxMin()) {
		printf("-999"); 
		return 0;
	}
	delFromDLL(findNode(maxDLL()));
	delFromDLL(findNode(minDLL()));
	displayDLL();
	return 0;
}
#endif
//1635번 중복숫자 사라지는 Stack
#if 0
#include<stdio.h>
#include<stdlib.h>
typedef struct node {
	int data; 
	struct node* next;
}node;
node* head = 0;

node* findnode(int n) {
	node* temp = head;
	while (temp != 0) {
		if (temp->data == n) {
			return temp;
		}
		temp = temp->next;
	}
	return temp;
}
node* findPreNode(node* spear) {
	node* _new = head;
	while (_new->next != spear) {
		_new = _new->next;
	}
	return _new;
}
void delfromSLL(node* spear) {
	if (spear == 0) {
		return;
	}
	if (spear == head) {
		head = head->next;
		free(spear);
		return;
	}
	node* pre = findPreNode(spear);
	pre->next = spear->next;
	free(spear);
	return;
}
void displaySLL() {
	if (head == 0) {
		printf("0");
		return;
	}
	node* temp = head;
	int a[1000] = { '\0' };
	int i = 0, cnt = 0;
	while (temp != 0) {
		a[i] = temp->data;
		temp = temp->next;
		cnt++;
		i++;
	}
	for (int j = cnt -1; j >= 0; j--) {
		printf("%d ", a[j]);
	}
	return;
}
void push(int n) {
	node* _new = (node*)malloc(sizeof(node));
	_new->data = n;
	_new->next = 0;
	if (head == 0) {
		head = _new;
		return;
	}
	node* temp = head;
	while (temp->next != 0) {
		temp = temp->next;
	}
	temp->next = _new;
	return;
}
void pop() {
	if (head == 0) {
		return;
	}
	node* temp = head;

	if (head->next == 0) {
		head = head->next;
		free(temp);
		return;
	}

	while (temp->next->next != 0) {
		temp = temp->next;
	}
	free(temp->next);
	temp->next = 0;
	return;
}


int main() {
	int n = 0;
	while (1) {
		scanf("%d", &n);
		if (n == -1) pop();
		else if (n == 0) break;
		else {
			if (findnode(n) == 0) {
				push(n);
			}
			else { 
				delfromSLL(findnode(n));
				push(n);
			}
		}
	}
	displaySLL();
	return 0;
}
#endif
//1637
#if 1 
#include<stdio.h>
#include<stdlib.h>
int que[1000] = {'\0'};
int rear = 0, front = 0;

void enqueue(int _v) {
	que[rear] = _v;
	rear = (rear + 1);
	return;
}
int isEmpty() {
	return(rear == front);
}
void dequeue() {
	if (isEmpty()) {
		return; 
	}
	int result = que[front];
	front = (front + 1);
	return ;
}

void displayQue() {
	if (rear == front) {
		printf("0");
		return;
	}
	int temp;
	for (int i = front; i <rear; i++) {
		printf("%d ", que[i]);
	}
}
void sort() {
	int temp;
	for (int i = front; i < rear -1; i++) {
		for (int j = i+1; j < rear; j++) {
			if (que[i] < que[j]) {
				temp = que[i];
				que[i] = que[j];
				que[j] = temp;
			}
		}
	}
	return;
}
int main() {
	int n = 0;
	while (1) {
		scanf("%d", &n);
		if (n == -1) dequeue();
		else if (n == 0) break;
		else enqueue(n); 
	}
	sort(que);
	displayQue(que);
	
}
#endif
