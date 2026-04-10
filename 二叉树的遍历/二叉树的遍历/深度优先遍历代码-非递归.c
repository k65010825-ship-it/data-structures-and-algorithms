//#include<stdio.h>
//#include<stdlib.h>
//typedef struct BTNode {
//	char data;
//	struct BTNode* l;
//	struct BTNode* r;
//}BTNode,*BTree;
//BTNode* InitBTree(char root) {
//	BTNode* p = (BTNode*)malloc(sizeof(BTNode));
//	p->data = root;
//	p->l = p->r = NULL;
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
//typedef struct SNode {
//	BTNode* data;
//	struct SNode* next;
//}SNode,*LinkStack;
//SNode* InitStack() {
//	SNode* head = (SNode*)malloc(sizeof(SNode));
//	head->next = NULL;
//	return head;
//}
//void Push(LinkStack s, BTNode* x) {
//	SNode* p = (SNode*)malloc(sizeof(SNode));
//	p->data = x;
//	p->next = s->next;
//	s->next = p;
//}
//BTNode* Pop(LinkStack s) {
//	if (s->next == NULL) {
//		printf("¿ÕÕ»\n");
//		return NULL;
//	}
//	SNode* p = s->next;
//	BTNode* k = s->next->data;
//	s->next = s->next->next;
//	free(p);
//	p = NULL;
//	return k;
//}
//BTNode* Get(LinkStack s) {
//	if (s->next == NULL) {
//		printf("¿ÕÕ»\n");
//		return NULL;
//	}
//	return s->next->data;
//}
//void Visit(BTree x) {
//	printf("%c ", x->data);
//}
//void PreOrderBT(BTree r) {
//	LinkStack s = InitStack();
//	BTNode* p = r;
//	while (p != NULL || s->next != NULL) {
//		if (p != NULL) {
//			Visit(p);
//			Push(s, p);
//			p = p->l;
//		}
//		else {
//			BTNode*f = Pop(s);
//			p = f->r;
//		}
//	}
//}
//void InOrderBT(BTree r) {
//	LinkStack s = InitStack();
//	BTNode* p = r;
//	while (p != NULL || s->next != NULL) {
//		if (p != NULL) {
//			Push(s, p);
//			p = p->l;
//		}
//		else {
//			BTNode* f = Pop(s);
//			Visit(f);
//			p = f->r;
//		}
//	}
//}
//void PostOrderBT(BTree r) {
//	LinkStack s = InitStack();
//	BTNode* p = r;
//	BTNode* pre = NULL;
//	while (p != NULL || s->next != NULL) {
//		if (p != NULL) {
//			Push(s, p);
//			p = p->l;
//		}
//		else {
//			BTNode* f = Get(s);
//			if (f->r != NULL && pre != f->r) {
//				p = f->r;
//			}
//			else {
//				f = Pop(s);
//				Visit(f);
//				pre = f;
//			}
//		}
//	}
//}
//int main() {
//	int n;
//	scanf("%d", &n);
//	char root, x, fx;
//	int flag;
//	scanf(" %c", &root);
//	BTree r = InitBTree(root);
//	for (int i = 1; i < n; i++) {
//		scanf(" %c %c %d", &x, &fx, &flag);
//		r = Insert(r, x, fx, flag);
//	}
//	printf("ÏÈÐò±éÀú£º");
//	PreOrderBT(r);
//	printf("\nÖÐÐò±éÀú£º");
//	InOrderBT(r);
//	printf("\nºóÐò±éÀú£º");
//	PostOrderBT(r);
//	printf("\n");
//	return 0;
//}