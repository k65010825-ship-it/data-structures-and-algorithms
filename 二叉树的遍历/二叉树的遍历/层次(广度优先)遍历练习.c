//#include<stdio.h>
//#include<stdlib.h>
////链队(出队时记得考虑返回值)
//typedef struct QNode {
//	char data;
//	struct QNode* next;
//}QNode,*LinkQueue;
//typedef struct {
//	LinkQueue f;
//	LinkQueue r;
//}Queue;
////层次遍历
//Queue InitQueue() {
//	QNode* head = (QNode*)malloc(sizeof(QNode));
//	head->next = NULL;
//	Queue q;
//	q.f = q.r = head;
//	return q;
//}
//void EnQueue(Queue* q, char x) {
//	QNode* p = (QNode*)malloc(sizeof(QNode));
//	p->data = x;
//	p->next = NULL;
//	q->r->next = p;
//	q->r = p;
//}
//char DeQueue(Queue* q) {
//	if (q->f->next==NULL) {
//		printf("队列已空，无法出队\n");
//		return' ';
//	}
//	else {
//		QNode* p = q->f->next;
//		char x = q->f->next->data;
//		if (q->f->next == q->r) {
//			q->r = q->f;
//		}
//		q->f->next = q->f->next->next;
//		free(p);
//		p = NULL;
//		return x;
//	}
//}
////二叉树的链式存储
//typedef struct BTNode {
//	char data;
//	struct BTNode* fa;
//	struct BTNode* l;
//	struct BTNode* r;
//}BTNode,*BTree;
//BTNode* InitBTree(char root) {
//	BTNode* p = (BTNode*)malloc(sizeof(BTNode));
//	p->data = root;
//	p->fa = p->l = p->r = NULL;
//	return p;
//}
//BTNode* Find(BTree r, char x) {
//	if (r == NULL || r->data == x) {
//		return r;
//	}
//	BTNode* ans = NULL;
//	if (r->l != NULL) {
//		ans = Find(r->l, x);
//		if (ans != NULL) {
//			return ans;
//		}
//	}
//	if (r->r != NULL) {
//		ans = Find(r->r, x);
//		if (ans != NULL) {
//			return ans;
//		}
//	}
//	return NULL;
//}
//BTree Insert(BTree r, char x, char fx, int flag) {
//	BTNode* p = (BTNode*)malloc(sizeof(BTNode));
//	p->data = x;
//	p->fa = Find(r, fx);
//	p->l = p->r = NULL;
//	BTNode* f = Find(r, fx);
//	if (!flag) {
//		f->l = p;
//	}
//	else {
//		f->r = p;
//	}
//	return r;
//}
//void LevelOrderBT(BTree r) {
//	Queue q = InitQueue();
//	EnQueue(&q, r->data);
//	while (q.f->next != NULL) {
//		char x = DeQueue(&q);
//		printf("%c ", x);
//		BTNode* p = Find(r, x);
//		if (p->l != NULL) {
//			EnQueue(&q, p->l->data);
//		}
//		if (p->r != NULL) {
//			EnQueue(&q, p->r->data);
//		}
//	}
//}
//int main() {
//	int n;
//	int flag;//=0 左  =1右孩子
//	scanf("%d",&n);
//	char root,x,fx;
//	scanf(" %c",&root);
//	BTree r=InitBTree(root);
//	for(int i=1;i<n;i++) 
//	{
//    	scanf(" %c %c %d",&x,&fx,&flag);
//		r=Insert(r,x,fx,flag);
//	}
//	LevelOrderBT(r);
//	printf("\n");
//	return 0;
//}