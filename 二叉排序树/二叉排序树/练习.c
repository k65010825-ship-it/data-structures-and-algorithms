#include<stdio.h>
#include<stdlib.h>
typedef struct BSTNode {
	int data;
	struct BSTNode* l;
	struct BSTNode* r;
}BSTNode,*BSTree;
BSTNode* CreateNode(int x) {
	BSTNode* s = (BSTNode*)malloc(sizeof(BSTNode));
	s->data = x;
	s->l = s->r = NULL;
	return s;
}
//递归
BSTNode* Find1(BSTree r, int x) {
	if (r == NULL || r->data == x) {
		return r;
	}
	else if (x < r->data) {
		return Find1(r->l, x);
	}
	else {
		return Find1(r->r, x);
	}
}
//非递归
BSTNode* Find2(BSTree r,int x) {
	BSTNode* p = r;
	while (p != NULL && p->data != x) {
		if (x < p->data)p = p->l;
		else p = p->r;
	}
	return p;
}
//递归
BSTree Insert1(BSTree r, int x) {
	if (r == NULL) {
		r = CreateNode(x);
		return r;
	}
	else if (x < r->data) {
		r->l = Insert1(r->l, x);
	}
	else {
		r->r = Insert1(r->r, x);
	}
	return r;
}
//非递归
BSTree Insert2(BSTree r, int x) {
	if (r == NULL) {
		r = CreateNode(x);
		return r;
	}
	BSTNode* pre = NULL;
	BSTNode* p = r;
	BSTNode* s = CreateNode(x);
	while (p != NULL) {
		pre = p;
		if (x < p->data)p = p->l;
		else p = p->r;
	}
	//循环结束时,pre指向x的上一个结点
	if (x < pre->data)pre->l = s;
	else pre->r = s;
	return r;
}
//递归
BSTree Delete1(BSTree r, int x) {
	if (r == NULL) {
		printf("%d不存在,无法删除\n",x);
		return r;
	}
	else if (x < r->data) r->l=Delete1(r->l, x);
	else if (x > r->data) r->r=Delete1(r->r, x);
	else {
		//x==r->data
		if (r->l != NULL && r->r != NULL) {
			//找r的前驱结点
			BSTNode* p = r->l;
			while (p->r != NULL) {
				p = p->r;
			}
			//p为r的前驱
			r->data = p->data;
			//问题转化为删除p
			r->l = Delete1(r->l, p->data);
		}
		else {
			BSTNode* p = r;
			if (r->l != NULL)r = r->l;
			else r = r->r;
			free(p);
			p = NULL;
		}
	}
	return r;
}
//非递归
BSTree Delete2(BSTree r, int x) {
	if (r == NULL) {
		printf("空树,无法删除\n");
		return r;
	}
	//找x所在的结点以及它的父亲
	BSTNode* p = r;
	BSTNode* pre = NULL;
	BSTNode* ch = NULL;
	while (p != NULL && p->data != x) {
		pre = p;
		if (x < p->data)p = p->l;
		else p = p->r;
	}
	//此时p为空 or x所在的结点
	//pre为x的父亲(物理意义上的)
	if (p == NULL) {
		printf("%d不存在,无法删除\n",x);
		return r;
	}
	else {//此时p为x所在的结点
	    //度为2时进行一个转化
		if (p->l != NULL && p->r != NULL) {
			//找x中序遍历的前驱
			//1234567->1233567
			BSTNode* t = p->l;
			BSTNode* tf = p;
			while (t->r != NULL) {
				tf = t;
				t = t->r;
			}
			//tf为x前驱的父亲,t为x的前驱
			p->data = t->data;
			//问题转化为删除x的前驱t
			pre = tf;
			p = t;
		}
		//度为0 or 1时
		//记录p的孩子(0 or 1)个
		if (p->l != NULL)ch = p->l;
		else ch = p->r;
		if (pre != NULL) {
			//将pre指向p的指针指向p的孩子
			if (pre->l==p)pre->l = ch;
			else pre->r = ch;
		}
		else {//pre==NULL说明要删除的结点为根结点
			r = ch;
		}
		//删除目标结点p
		free(p);
		p = NULL;
	}
	return r;
}
void InOrder(BSTree r)
{
	if (r == NULL)return;
	InOrder(r->l);
	printf("%d ", r->data);
	InOrder(r->r);
}

int main() {
	int n;
	scanf("%d", &n);
	int data;
	BSTree r = NULL;
	for (int i = 0; i < n; i++) {
		scanf("%d", &data);
		r = Insert2(r, data);
	}
	InOrder(r);
	printf("\n");
	scanf("%d",&data);
	r=Delete1(r,data);
	InOrder(r);
	printf("\n");
}
