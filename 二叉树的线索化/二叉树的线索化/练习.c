#include<stdio.h>
#include<stdlib.h>
typedef struct BTNode {
	char data;
	struct BTNode* l;
	struct BTNode* r;
	int lflag;
	int rflag;
}BTNode,*BTree;
BTNode* pre = NULL;
BTNode* InitBTree(char root) {
	BTNode* p = (BTNode*)malloc(sizeof(BTNode));
	p->data = root;
	p->l = p->r = NULL;
	p->lflag = p->rflag = 0;
	return p;
}
BTNode* Find(BTree r, char x) {
	if (r == NULL || r->data == x) {
		return r;
	}
	BTNode* ans = NULL;
	if (r->l != NULL && r->lflag == 0) {
		ans = Find(r->l, x);
		if (ans != NULL) {
			return ans;
		}
	}
	if (r->r != NULL && r->rflag == 0) {
		ans = Find(r->r, x);
		if (ans != NULL) {
			return ans;
		}
	}
	return NULL;
}
BTNode* Insert(BTree r, char x, char fx, int flag) {
	BTNode* f = Find(r, fx);
	BTNode* p = (BTNode*)malloc(sizeof(BTNode));
	p->data = x;
	p->l = p->r = NULL;
	p->lflag = p->rflag = 0;
	if (!flag)f->l = p;
	else f->r = p;
	return r;
}
void Visit(BTNode* p) {//当前访问的结点为p
	if (p->l == NULL) {
		p->l = pre;
		p->lflag = 1;
	}
	if (pre != NULL && pre->r == NULL) {
		pre->r = p;
		pre->rflag = 1;
	}
	pre = p;
}
void InOrderBT(BTree r) {//左->根->右
	if (r == NULL) {
		return;
	}
	InOrderBT(r->l);
	Visit(r);
	InOrderBT(r->r);
}
int main() {
	int n;
	scanf("%d", &n);
	char root, x, fx;
	int flag;
	scanf(" %c", &root);
	BTree r = InitBTree(root);
	for (int i = 1; i < n; i++) {
		scanf(" %c %c %d", &x, &fx, &flag);
		r = Insert(r, x, fx, flag);
	}
	InOrderBT(r);
	scanf(" %c", &x);
	BTNode* p = Find(r, x);
	//找x的前驱
	if (p->l == NULL) {
		printf("%c无前驱\n", x);
	}
	else {
		if (p->lflag == 1) {
			printf("%c的前驱是%c\n", x, p->l->data);
		}
		else {
			BTNode* q = p->l;
			while (q->rflag == 0) {
				q = q->r;
			}
			printf("%c的前驱是%c\n", x, q->data);
		}
	}
	//找x的后继
	if (p->r == NULL) {
		printf("%c无后继\n", x);
	}
	else {
		if (p->rflag == 1) {
			printf("%c的后继是%c\n", x, p->r->data);
		}
		else {
			BTNode* q = p->r;
			while (q->lflag == 0) {
				q = q->l;
			}
			printf("%c的后继是%c\n", x, q->data);
		}
	}
	return 0;
}