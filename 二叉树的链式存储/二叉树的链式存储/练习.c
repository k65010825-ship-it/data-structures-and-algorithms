#include<stdio.h>
#include<stdlib.h>
typedef struct BTNode {
	char data;
	struct BTNode* l;
	struct BTNode* r;
	struct BTNode* fa;
}BTNode,*BTree;
BTNode* InitBTree(char root) {
	BTNode* p = (BTNode*)malloc(sizeof(BTNode));
	p->data = root;
	p->l = p->r = p->fa = NULL;
	return p;
}
BTNode* Find(BTree r, char x) {
	if (r == NULL || r->data == x) {
		return r;
	}
	BTNode* ans = NULL;
	if (r->l != NULL) {
		ans = Find(r->l, x);
		if (ans != NULL) {
			return ans;
		}
	}
	if (r->r != NULL) {
		ans = Find(r->r, x);
		if (ans != NULL) {
			return ans;
		}
	}
	return NULL;
}
BTree Insert(BTree r, char x, char fx, int flag) {
	BTNode* p = (BTNode*)malloc(sizeof(BTNode));
	p->data = x;
	p->l = p->r = NULL;
	BTNode* q = Find(r, fx);
	p->fa = q;
	if (!flag) {
		q->l = p;
	}
	else {
		q->r = p;
	}
	return r;
}
int main() {
	int n;
	scanf("%d", &n);
	char root, x, fx;
	scanf(" %c", &root);
	BTree r = InitBTree(root);
	int flag;
	for (int i = 1; i < n; i++) {
		scanf(" %c %c %d", &x, &fx, &flag);
		r = Insert(r, x, fx, flag);
	}
	scanf(" %c", &x);
	BTNode* p = Find(r, x);
	//找x的父亲
	if (p->fa == NULL) {
		printf("%c为根结点\n", x);
	}
	else {
		printf("%c的父亲是%c\n", x, p->fa->data);
	}
	//找x的孩子
	if (p->l == NULL && p->r == NULL) {
		printf("%c为叶子结点\n", x);
	}
	else {
		if (p->l != NULL) {
			printf("%c的左孩子是%c\n", x, p->l->data);
		}
		if (p->r != NULL) {
			printf("%c的右孩子是%c\n", x, p->r->data);
		}
	}
	return 0;
}