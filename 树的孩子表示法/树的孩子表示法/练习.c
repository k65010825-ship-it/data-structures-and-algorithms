//#include<stdio.h>
//#include<stdlib.h>
//#define maxx 100
//typedef struct chNode {
//	int chi;
//	struct chNode* next;
//}chNode,*Linkson;
//struct Tree {
//	char data;
//	Linkson son;
//}t[maxx];
//int sum = 0;
//void InitTree(char root) {
//	t[0].data = root;
//	t[0].son = NULL;
//	sum++;
//}
//int Find(char x) {
//	int i;
//	for (i = 0; i < sum; i++) {
//		if (t[i].data == x) {
//			break;
//		}
//	}
//	return i;
//}
//void Head_Insert(char x, char fx) {
//	if (sum == maxx) {
//		printf("空间已满，无法插入\n");
//		return;
//	}
//	t[sum].data = x;
//	t[sum].son = NULL;
//	int fxi = Find(fx);
//	chNode* p = (chNode*)malloc(sizeof(chNode));
//	p->chi = sum;
//	p->next = t[fxi].son;
//	t[fxi].son = p;
//	sum++;
//}
//void Rear_Insert(char x, char fx) {
//	if (sum == maxx) {
//		printf("空间已满，无法插入\n");
//		return;
//	}
//	t[sum].data = x;
//	t[sum].son = NULL;
//	chNode* s = (chNode*)malloc(sizeof(chNode));
//	s->chi = sum;
//	s->next = NULL;
//	int fxi = Find(fx);
//	chNode* p = t[fxi].son;
//	if (p == NULL) {
//		t[fxi].son = s;
//	}
//	else {
//		while (p->next != NULL) {
//			p = p->next;
//		}
//		p->next = s;
//	}
//	sum++;
//}
//int main() {
//	int n;
//	scanf("%d", &n);
//	char root, x, fx;
//	scanf(" %c", &root);
//	InitTree(root);
//	for (int i = 1; i < n; i++) {
//		scanf(" %c %c", &x, &fx);
//		Head_Insert(x, fx);
//	}
//	scanf(" %c", &x);
//	//找x的孩子
//	int xi = Find(x);
//	chNode* p = t[xi].son;
//	if (p == NULL) {
//		printf("%c为叶子结点\n", x);
//	}
//	else {
//		printf("%c的孩子有:", x);
//		while (p != NULL) {
//			printf("%c ", t[p->chi].data);
//			p = p->next;
//		}
//		printf("\n");
//	}
//	//找x的父亲
//	int flag = 0;
//	for (int i = 0; i < sum; i++) {
//		p = t[i].son;
//		while (p != NULL) {
//			if (p->chi == xi) {
//				printf("%c的父亲是%c\n", x, t[i].data);
//				flag = 1;
//				break;
//			}
//			p = p->next;
//		}
//		if (flag) {
//			break;
//		}
//	}
//	if (!flag) {
//		printf("%c为根结点\n", x);
//	}
//	return 0;
//}
