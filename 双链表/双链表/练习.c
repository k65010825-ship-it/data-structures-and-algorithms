#include<stdio.h>
#include<stdlib.h>
typedef struct Node {
	int data;
	struct Node* pre;
	struct Node* next;
}Node,*LinkList;
//若返回普通结点(包括头结点)，则函数返回值类型为Node*，若返回链表，则返回值类型为LinkList，增强可读性
Node* InitLink() {
	Node* head = (Node*)malloc(sizeof(Node));
	head->pre = NULL;
	head->next = NULL;
	return head;
}
LinkList Head_insert(LinkList L, int k) {
	Node* p = (Node*)malloc(sizeof(Node));
	p->data = k;
	p->next = L->next;
	L->next = p;
	p->pre = L;
	if (L->next != NULL)L->next->pre = p;
	return L;
}
LinkList Rear_insert(LinkList L, int k) {
	Node* p = (Node*)malloc(sizeof(Node));
	p->data = k;
	Node* q = L;
	while (q->next != NULL) {
		q = q->next;
	}
	q->next = p;
	p->next = NULL;
	p->pre = q;
	return L;
}
LinkList Insert(LinkList L,int x,int k) {
	Node* p = (Node*)malloc(sizeof(Node));
	p->data = k;
	Node* q = L->next;
	while (q != NULL && q->data != x) {
		q = q->next;
	}
	if (q == NULL)printf("%d不存在，无法插入\n", x);
	else {
		p->next = q->next;
		p->pre = q;
		if(q->next!=NULL)q->next->pre = p;
		q->next = p;
	}
	return L;
}
LinkList Delete(LinkList L, int k) {
	Node* p = L;
	while (p->next!= NULL && p->next->data != k) {
		p = p->next;
	}
	if (p->next == NULL)printf("%d不存在，无法删除\n", k);
	else {
		Node* q = p->next;
		p->next = q->next;
		if(q->next!=NULL)q->next->pre = p;
		free(q);
		q = NULL;
	}
	return L;
}
void Printff(LinkList L) {
	Node* p = L->next;
	while (p != NULL) {
		printf("%d ", p->data);
		p = p->next;
	}
	printf("\n");
}
int main()
{
	LinkList L = NULL;
	L = InitLink();//初始化，声明一个头结点 L指向该头结点
	L = Head_insert(L, 6);
	L = Head_insert(L, 7);
	L = Head_insert(L, 1);
	L = Head_insert(L, 8);
	Printff(L);
	L = Rear_insert(L, 4);
	L = Rear_insert(L, 9);
	L = Rear_insert(L, 10);
	Printff(L);
	L = Insert(L, 6, 19);
	L = Insert(L, 4, 12);
	Printff(L);
	L = Delete(L, 100);
	L = Delete(L, 4);
	Printff(L);
	return 0;
}
