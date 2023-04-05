//1634 Queue By DLL - MAX, MIN을 지우고 오름차순 출력
#if 1	
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
