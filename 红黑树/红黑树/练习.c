#include<stdio.h>
#include<stdlib.h>
#define RED 0
#define BLACK 1
typedef struct RBTNode {
	int data;
	struct RBTNode* f;
	struct RBTNode* l;
	struct RBTNode* r;
	int color;
}RBTNode,*RBTree;
RBTNode* CreateNode(int k) {
	RBTNode* p = (RBTNode*)malloc(sizeof(RBTNode));
	p->data = k;
	p->f = p->l = p->r = NULL;
	p->color = RED;
	return p;
}
//左旋
RBTree RR(RBTree T, RBTNode* x) {
	RBTNode* temp = x->r;
	x->r = temp->l;
	if(temp->l!=NULL)temp->l->f = x;
	temp->l = x;
	RBTNode* fx = x->f;
	x->f = temp;
	temp->f = fx;
	if (fx == NULL)T = temp;
	else {
		if (fx->l == x)fx->l = temp;
		else fx->r = temp;
	}
	return T;
}
//右旋
RBTree LL(RBTree T, RBTNode* x) {
	RBTNode* temp = x->l;
	x->l = temp->r;
	if (temp->r != NULL)temp->r->f = x;
	temp->r = x;
	RBTNode* fx = x->f;
	x->f = temp;
	temp->f = fx;
	if (fx == NULL)T = temp;
	else {
		if (fx->l == x)fx->l = temp;
		else fx->r = temp;
	}
	return T;
}
RBTree RL(RBTree T, RBTNode* x) {
	T = LL(T, x->r);
	return RR(T, x);
}
RBTree LR(RBTree T, RBTNode* x) {
	T = RR(T, x->l);
	return LL(T, x);
}
RBTree In_Fixup(RBTree T, RBTNode* z) { //z是破坏“不红红”的罪魁祸首
	RBTNode* p = z->f; //指向z的父亲(z破坏"不红红",z一定存在父亲)
	RBTNode* g = NULL; //指向z的爷爷
	RBTNode* u = NULL; //指向z的叔叔
	while (p != NULL && p->color == RED) {
		g = p->f; //p为红色,说明p一定不是根结点,p一定有父亲g
		if (g->r == p) { //p是g的右孩子
			u = g->l;
			if (u != NULL&&u->color==RED) { //u为红色,长辈变色
				p->color = BLACK;
				u->color = BLACK;
				g->color = RED;
				z = g; //g可能成为“不红红”的罪魁祸首
				p = z->f;
			}
			else { //u为黑色,执行旋转RR/RL
				if (p->r == z) { //RR
					T = RR(T,g);
					g->color = RED;
					p->color = BLACK;
				}
				else { //RL
					T = RL(T, g);
					g->color = RED;
					z->color = BLACK;
				}
				break; //u是黑色时,调整一次就可以直接退出循环,不需要向上调整
			}
		}
		else { //p是g的左孩子
			u = g->r;
			if (u != NULL && u->color == RED) { //u为红色
				p->color = BLACK;
				u->color = BLACK;
				g->color = RED;
				z = g; //g可能成为“不红红”的罪魁祸首
				p = z->f;
			}
			else { //u为黑色,执行旋转LL/LR
				if (p->l == z) { //LL
					T = LL(T, g);
					g->color = RED;
					p->color = BLACK;
				}
				else { //LR
					T = LR(T, g);
					g->color = RED;
					z->color = BLACK;
				}
				break; //u是黑色时,调整一次就可以直接退出循环,不需要向上调整
			}
		}
	}
	//如果p是为空导致循环结束,说明向上调整到了根结点做新的z,那么直接将根的颜色改为黑色
	if (p == NULL)T->color = BLACK;
	return T;
}
RBTree Insert(RBTree T, int k) {
	//空树
	if (T == NULL) {
		T = CreateNode(k);
		T->color = BLACK;
		return T;
	}
	//非空树
	//1.按照二叉排序树的插入过程(非递归)
	RBTNode* z = T;
	RBTNode* zp = NULL;
	while (z != NULL) {
		zp = z;
		if (k < z->data)z = z->l;
		else z = z->r;
	}
	z = CreateNode(k);
	z->f = zp;
	if (k < zp->data)zp->l = z;
	else zp->r = z;
	//2.如果不满足“不红红”,则进行调整
	if (zp->color == RED) {
		T = In_Fixup(T, z);
	}
	return T;
}
RBTree De_Fixup(RBTree T, RBTNode* x, RBTNode* fx) {
	//x可能是空的 fx可能是空的,但是x和fx不可能同时空
	//与In_Fixup不一样的是,这里fx可能为空,所以直接把fx当作参数传入,减少判断

	RBTNode* w = NULL;//指向x的兄弟
	//x是黑色并且x不是根结点
	while (x != T && (x == NULL || x->color == BLACK)) {
		if (fx->l == x) { //x是左孩子
			w = fx->r;
			if (w->color == RED) { //兄弟w是红色的
				T = RR(T, fx);
				w->color = BLACK;
				fx->color = RED;
				w = fx->r;
			}
			if ((w->l == NULL || w->l->color == BLACK) && (w->r == NULL || w->r->color == BLACK)) { //兄弟w是黑色的,并且w的两个孩子都是黑色的
				w->color = RED;
				x = fx;
				fx = x->f;
			}
			else { //兄弟w是黑色的,并且w至少有一个红色的孩子
				//为了保证w的两个孩子都是红色时以右孩子作为红色节点(保证RR单旋),所以先判断w的右孩子是否为黑色
				if (w->r == NULL || w->r->color == BLACK) { //w的右孩子是黑色的,w的左孩子是红色的
					T = LL(T, w);
					w->l->color = BLACK;
					w->color = RED;
					w = fx->r;
				}
				//w的右孩子是红色的
				//到此一定是RR的情况
				w->color = fx->color;
				T = RR(T, fx);
				fx->color = BLACK;
				if (w->r != NULL)w->r->color = BLACK;
				break; //调整完成后直接退出循环
			}
		}
		else { //x是右孩子
			w = fx->l;
			if (w->color == RED) { //兄弟w是红色的
				T = LL(T, fx);
				w->color = BLACK;
				fx->color = RED;
				w = fx->l;
			}
			if ((w->l == NULL || w->l->color == BLACK) && (w->r == NULL || w->r->color == BLACK)) { //兄弟w是黑色的,并且w的两个孩子都是黑色的
				w->color = RED;
				x = fx;
				fx = x->f;
			}
			else { //兄弟w是黑色的,并且w至少有一个红色的孩子
				//为了保证w的两个孩子都是红色时以左孩子作为红色节点(保证单旋LL),所以先判断w的左孩子是否为黑色
				if (w->l == NULL || w->l->color == BLACK) { //w的左孩子是黑色的,w的右孩子是红色的
					T = RR(T, w);
					w->color = RED;
					w->r->color = BLACK;
					w = fx->l;
				}
				//w的左孩子是红色的
				//到此一定是LL的情况
				w->color = fx->color;
				T = LL(T, fx);
				fx->color = BLACK;
				if (w->l != NULL)w->l->color = BLACK;
				break; //调整完成后直接退出循环
			}
		}
	}
	//x是红色
	if (x != NULL && x->color == RED)x->color = BLACK;
	return T;
}
RBTree Delete(RBTree T, int k) {
	if (T == NULL) {
		printf("空树,无法删除\n");
		return T;
	}
	//找到k所在的结点z
	RBTNode* z = T;
	while (z != NULL && z->data != k) {
		if (k < z->data)z = z->l;
		else z = z->r;
	}
	if (z == NULL) { //没有找到k
		printf("%d不存在,无法删除\n", k);
		return T;
	}
	//1.如果z有两个孩子,则找到z的前驱y,将y的数据复制给z,然后删除y
	if (z->l != NULL && z->r != NULL) {
		RBTNode* y = z->l;
		while (y->r != NULL) {
			y = y->r;
		}
		z->data = y->data;
		z = y;//让z指向y,转换为删除y
	}
	//2.删除z,此时z至多有一个孩子
	RBTNode* x = NULL;//x指向z的孩子
	if (z->l != NULL)x = z->l;
	else x = z->r;
	RBTNode* fx = z->f;//指向z的父亲
	if (fx == NULL)T = x;//如果z是根结点,删除z后,x成为新的根结点
	else {
		if (fx->l == z)fx->l = x;
		else fx->r = x;
	}
	if (x != NULL)x->f = fx;
	int zc = z->color; //保存z的颜色后才能把z删掉
	free(z);
	z = NULL;
	if (T == NULL)return T;//删除完后是空树,直接返回
	//3.调整颜色
	//删除z后,如果zc是黑色的,可能会破坏黑色平衡,需要调整
	if (zc == BLACK) {
		T = De_Fixup(T, x, fx);
	}
	return T;
}
void InOrder(RBTree T) {
	if (T == NULL)return;
	InOrder(T->l);
	printf("%d ", T->data);
	if (T->color == RED)printf("RED ");
	else printf("BLACK ");
	if (T->f != NULL)printf("%d\n", T->f->data);
	else printf("\n");
	InOrder(T->r);
}
int main() {
	int n;
	scanf("%d", &n);
	RBTree T = NULL;
	int k;
	for (int i = 1; i <= n; i++) {
		scanf("%d", &k);
		T = Insert(T, k);
	}
	printf("输入要删除的节点:");
	scanf("%d", &k);
	T = Delete(T, k);
	InOrder(T);
	return 0;
}
