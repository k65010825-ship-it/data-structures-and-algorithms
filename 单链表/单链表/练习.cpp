//#include<stdio.h>
//#include<stdlib.h>
//typedef struct Node {
//	int data;
//	struct Node* next;
//}Node,*LinkList;
//Node* InitLink() {
//	Node* head = (Node*)malloc(sizeof(Node));
//	head->next = NULL;
//	return head;
//}
//LinkList Head_insert(LinkList L, int k) {
//	Node* p = (Node*)malloc(sizeof(Node));
//	p->data = k;
//	p->next = L->next;
//	L->next = p;//更新首元结点
//	return L;
//}
//LinkList Rear_insert(LinkList L, int k) {
//	Node* p = (Node*)malloc(sizeof(Node));
//	p->data = k;
//	Node* q = L;
//	//寻找尾结点
//	while (q->next != NULL) {
//		q = q->next;
//	}
//	q->next = p;
//	p->next = NULL;
//	return L;
//}
//Node* Find(LinkList L, int k) {
//	Node* p = L->next;//从头结点的下一个结点开始找
//	while (p != NULL && p->data != k) {
//		p = p->next;
//	}
//	return p;
//}
//LinkList Insert(LinkList L, int x,int k) {
//	Node* p = (Node*)malloc(sizeof(Node));
//	p->data = k;
//	Node* q = Find(L, x);
//	if (q == NULL)printf("%d不存在，无法插入\n", x);
//	else {
//		p->next = q->next;
//		q->next = p;
//	}
//	return L;
//}
//LinkList Delete(LinkList L, int k) {
//	Node* p = L;
//	while (p->next != NULL && p->next->data != k) {
//		p = p->next;
//	}
//	if (p->next == NULL)printf("%d不存在，无法删除\n", k);
//	else {
//		Node* q = p->next;
//		p->next = q->next;
//		free(q);
//		q = NULL;
//	}
//	return L;
//}
//void Printff(LinkList L) {
//	Node* p = L->next;
//	while (p != NULL) {
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
//	return 0;
//}
