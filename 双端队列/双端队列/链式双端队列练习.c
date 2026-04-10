#include<stdio.h>
#include<stdlib.h>
typedef struct QNode {
	int data;
	struct QNode* pre;
	struct QNode* next;
}QNode,*LinkDeque;
typedef struct {
	LinkDeque l;
	LinkDeque r;
}Deque;
Deque InitDeque() {
	Deque q;
	QNode* head = (QNode*)malloc(sizeof(QNode));
	head->next = head->pre = NULL;
	q.l = q.r = head;
	return q;
}
void LInsert(Deque* q, int k) {
	QNode* p = (QNode*)malloc(sizeof(QNode));
	p->data = k;
	q->l->pre = p;
	p->next = q->l;
	p->pre = NULL;
	q->l = p;
}
void RInsert(Deque* q, int k) {
	QNode* p = (QNode*)malloc(sizeof(QNode));
	q->r->data = k;
	q->r->next = p;
	p->pre = q->r;
	p->next = NULL;
	q->r = p;
}
void LDelete(Deque* q) {
	if (q->l == q->r) {
		printf("队空，无法出队\n");
		return;
	}
	QNode* s = q->l;
	printf("%d左端出队\n", s->data);
	q->l = q->l->next;
	q->l->pre = NULL;
	free(s);
	s = NULL;
}
void RDelete(Deque* q) {
	if (q->l == q->r) {
		printf("队空，无法出队\n");
		return;
	}
	QNode* s = q->r;
	printf("%d右端出队\n", s->pre->data);
	q->r = q->r->pre;
	q->r->next = NULL;
	free(s);
	s = NULL;
}
int main()
{
	Deque q=InitDeque();
	LInsert(&q,1);
	LInsert(&q,2);
	LInsert(&q,3);
	RInsert(&q,6);
	RInsert(&q,7);
	RDelete(&q);
	RDelete(&q);
	RDelete(&q);
	LDelete(&q);
	LDelete(&q);
	LDelete(&q);
	return 0;
}
