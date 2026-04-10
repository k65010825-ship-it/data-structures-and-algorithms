#include<stdio.h>
#include<stdlib.h>
typedef struct BTNode {
	char data;
	struct BTNode* fa;
	struct BTNode* l;
	struct BTNode* r;
}BTNode, * BTree;
BTNode* InitBTree(char root) {
	BTNode* p = (BTNode*)malloc(sizeof(BTNode));
	p->data = root;
	p->fa = p->l = p->r = NULL;
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
	p->fa = Find(r, fx);
	p->l = p->r = NULL;
	BTNode* f = Find(r, fx);
	if (!flag) {
		f->l = p;
	}
	else {
		f->r = p;
	}
	return r;
}
//递归版本广度优先遍历二叉树
void LevelOrderBT(BTree r) {
	if (r == NULL) {
		return;
	}
	printf("%c ", r->data);
	LevelOrderBT(r->l);
	LevelOrderBT(r->r);
}
int main() {
	int n;
	int flag;//=0 左  =1右孩子
	scanf("%d", &n);
	char root, x, fx;
	scanf(" %c", &root);
	BTree r = InitBTree(root);
	for (int i = 1; i < n; i++)
	{
		scanf(" %c %c %d", &x, &fx, &flag);
		r = Insert(r, x, fx, flag);
	}
	LevelOrderBT(r);
	printf("\n");
	return 0;
}