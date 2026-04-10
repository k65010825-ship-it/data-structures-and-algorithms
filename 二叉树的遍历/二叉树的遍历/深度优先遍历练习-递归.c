//#include<stdio.h>
//#include<stdlib.h>
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
//	BTNode* f = Find(r, fx);
//	p->fa = f;
//	p->l = p->r = NULL;
//	if (!flag) {
//		f->l = p;
//	}
//	else {
//		f->r = p;
//	}
//	return r;
//}
////先序遍历(根->左->右)
//void PreOrderBT(BTree r) {
//  //递归出口 
//	if (r == NULL) {
//		return;
//	}
//	printf("%c ", r->data);//访问根结点
//	PreOrderBT(r->l);
//	PreOrderBT(r->r);
//}
////中序遍历(左->根->右)
//void InOrderBT(BTree r) {
//	if (r == NULL) {
//		return;
//	}
//	InOrderBT(r->l);
//	printf("%c ", r->data);//访问根结点
//	InOrderBT(r->r);
//}
////后序遍历(左->右->根)
//void PostOrderBT(BTree r) {
//	if (r == NULL) {
//		return;
//	}
//	PostOrderBT(r->l);
//	PostOrderBT(r->r);
//	printf("%c ", r->data);//访问根结点
//}
//int main() {
//	int n;
//	scanf("%d", &n);
//	char root, x, fx;
//	int flag;//0：左 1：右
//	scanf(" %c", &root);
//	BTree r = InitBTree(root);
//	for (int i = 1; i < n; i++) {
//		scanf(" %c %c %d", &x, &fx, &flag);
//		r = Insert(r, x, fx, flag);
//	}
//	PreOrderBT(r);
//	printf("\n");
//	InOrderBT(r);
//	printf("\n");
//	PostOrderBT(r);
//	printf("\n");
//	return 0;
//}