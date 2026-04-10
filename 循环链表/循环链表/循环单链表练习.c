//#include<stdio.h>
//#include<stdlib.h>
//typedef struct Node {
//	int data;
//	struct Node* next;
//}Node,*LinkList;
//Node* InitLink() {
//	Node* head = (Node*)malloc(sizeof(Node));
//	head->next = head;
//	return head;
//}
//LinkList Head_insert(LinkList L, int k) {
//	Node* p = (Node*)malloc(sizeof(Node));
//	p->data = k;
//	p->next = L->next;
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
//	p->next = L;
//	return L;
//}
//LinkList Insert(LinkList L,int x,int k) {
//	Node* p = (Node*)malloc(sizeof(Node));
//	p->data = k;
//	Node* q = L->next;
//	while (q != L && q->data != x) {
//		q = q->next;
//	}
//	if (q == L)printf("%d不存在，无法插入\n",x);
//	else {
//		p->next = q->next;
//		q->next = p;
//	}
//	return L;
//}
//LinkList Delete(LinkList L, int k) {
//	Node* p = L;
//	while (p->next != L && p->next->data != k) {
//		p = p->next;
//	}
//	if (p->next == L) {
//	    printf("%d不存在，无法删除\n",k);
//	}
//	else {
//		Node* q = p->next;
//		p->next = p->next->next;
//		free(q);
//		q = NULL;
//	}
//	return L;
//}
//void Printff(LinkList L) {
//	Node* p = L->next;
//	while (p!= L) {
//		printf("%d ", p->data);
//		p = p->next;
//	}
//	printf("\n");
//}
//int main()
//{
//
//	LinkList L = NULL;
//	L = InitLink();//初始化，声明一个头结点 L指向该头结点
//	L = Head_insert(L, 6);
//	L = Head_insert(L, 7);
//	L = Head_insert(L, 1);
//	L = Head_insert(L, 8);
//	Printff(L);
//	L = Rear_insert(L, 4);
//	L = Rear_insert(L, 9);
//	L = Rear_insert(L, 10);
//	Printff(L);
//	L = Insert(L, 6, 19);
//	L = Insert(L, 4, 12);
//	Printff(L);
//	L = Delete(L, 100);
//	L = Delete(L, 4);
//	Printff(L);
//
//	return 0;
//}
