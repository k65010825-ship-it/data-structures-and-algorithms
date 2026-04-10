//#include<stdio.h>
//#include<stdlib.h>
//typedef struct Node {
//	int data;
//	struct Node* pre;
//	struct Node* next;
//}Node,*LinkList;
//Node* InitLink() {
//	Node* head = (Node*)malloc(sizeof(Node));
//	head->pre = head;
//	head->next = head;
//	return head;
//}
//LinkList Head_insert(LinkList L, int k) {
//	Node* p = (Node*)malloc(sizeof(Node));
//	p->data = k;
//	p->next = L->next;
//	p->pre = L;
//	if (L->next != L)L->next->pre = p;
//  else L->pre = p;//维护！
//	L->next = p;
//	return L;
//}
//LinkList Rear_insert(LinkList L, int k) {
//	Node* p = (Node*)malloc(sizeof(Node));
//	p->data = k;
//	Node* q = L;
//	while (q->next != L) {
//		q = q->next;
//	}
//	q->next = p;
//	p->pre = q;
//	p->next = L;
//	L->pre = p;
//	return L;
//}
//Node* Find(LinkList L, int k) {
//	Node* p = L->next;
//	while (p != L && p->data != k) {
//		p = p->next;
//	}
//	return p;
//}
//LinkList Insert(LinkList L,int x,int k) {
//	Node* p = (Node*)malloc(sizeof(Node));
//	p->data = k;
//	Node* q = Find(L, x);
//	if (q == L)printf("%d不存在，无法插入\n", x);
//	else {
//		p->next = q->next;
//		p->pre = q;
//		if (q->next != L)q->next->pre = p;
//		q->next = p;
//	}
//	return L;
//}
//LinkList Delete(LinkList L, int k) {
//	Node* p = Find(L, k);
//	if (p == L)printf("%d不存在，无法删除\n", k);
//	else {
//		p->pre->next = p->pre->next->next;
//		if (p->next != L)p->next->pre = p->pre;
//		free(p);
//		p = NULL;
//	}
//	return L;
//}
//void Printff(LinkList L) {
//	Node* p = L->next;
//	while (p != L) {
//		printf("%d ", p->data);
//		p = p->next;
//	}
//	printf("\n");
//}
//int main()
//{
//    LinkList L=NULL;
//	L=InitLink();//初始化，声明一个头结点 L指向该头结点
//   L=Head_insert(L,6);
//	L=Head_insert(L,7);
//	L=Head_insert(L,1);
//	L=Head_insert(L,8);
//	 Printff(L);
//	L=Rear_insert(L,4);
//	L=Rear_insert(L,9);
//	L=Rear_insert(L,10);
//	 Printff(L);
//	L=Insert(L,6,19);
//	L=Insert(L,4,12);
//	 Printff(L);
//	L=Delete(L,100);
//	L=Delete(L,4);
//	 Printff(L);
//    return 0;
//}


//---------------------版本1--------------------------------




//---------------------版本2---------------------------------
#include<stdio.h>
#include<stdlib.h>
typedef struct Node {
	int data;
	struct Node* pre;
	struct Node* next;
}Node, * LinkList;
Node* InitLink() {
	Node* head = (Node*)malloc(sizeof(Node));
	head->pre = head->next = head;
	return head;
}
LinkList Head_insert(LinkList L, int k) {
	Node* p = (Node*)malloc(sizeof(Node));
	p->data = k;
	p->next = L->next;
	p->pre = L;
	if (L->next != L) {
		L->next->pre = p;
	}
	else {
		//维护L->pre
		L->pre = p;
	}
	L->next = p;
	return L;
}
LinkList Rear_insert(LinkList L, int k) {
	Node* p = (Node*)malloc(sizeof(Node));
	p->data = k;
	Node* q = L->pre; // q是当前尾节点
	q->next = p;
	p->pre = q;
	p->next = L;
	L->pre = p;
	return L;
}
Node* Find(LinkList L, int x) {
	Node* p = L->next;
	while (p != L && p->data != x) {
		p = p->next;
	}
	return p;
}
LinkList Insert(LinkList L, int x, int k) {
	Node* p = (Node*)malloc(sizeof(Node));
	p->data = k;
	Node* q = Find(L, x);

	if (q == L) {
		printf("%d不存在，无法插入\n", x);
		free(p);
		p = NULL;
	}
	else {
		p->next = q->next;
		p->pre = q;
		if (q->next != L) q->next->pre = p;
		q->next = p;
	}
	return L;
}
LinkList Delete(LinkList L, int k) {
	Node* p = Find(L, k);
	if (p == L) {
		printf("%d不存在，无法删除\n", k);
	}
	else {
		Node* q = p->pre;
		q->next = p->next;
		if (p->next != L) p->next->pre = q;
		free(p);
		p = NULL;
	}
	return L;
}
void Printff(LinkList L) {
	Node* p = L->next;
	while (p != L) {
		printf("%d ", p->data);
		p = p->next;
	}
	printf("\n");
}
int main()
{
	LinkList L = NULL;
	L = InitLink();
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
