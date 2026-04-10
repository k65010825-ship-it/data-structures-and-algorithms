//#include<stdio.h>
//#define maxx 100
////基于结构体数组实现(顺序存储)
//struct Node {
//	char data;
//	int fa;
//}t[maxx];
//int sum = 0;
//void InitTree(char root) {
//	t[0].data = root;
//	t[0].fa = -1;
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
//void Insert(char x, char fx) {
//	if (sum == maxx) {
//		printf("空间已满，无法插入\n");
//		return;
//	}
//	t[sum].data = x;
//	t[sum].fa = Find(fx);
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
//		Insert(x, fx);
//	}
//	scanf(" %c", &x);
//	//找x的父亲
//	int xi = Find(x);
//	int fxi = t[xi].fa;
//	if (fxi == -1) {
//		printf("%c为根结点\n", x);
//	}
//	else {
//		printf("%c的父亲为%c\n", x, t[fxi].data);
//	}
//	//找x的儿子
//	int flag = 0;
//	for (int i = 0; i < sum; i++) {
//		if (t[i].fa == xi) {
//			printf("%c的父亲是%c\n", t[i].data, x);
//			flag = 1;
//		}
//	}
//	if (!flag) {
//		printf("%c为叶子结点\n", x);
//	}
//	return 0;
//}






/*
13
A
B A
C A
D A
E B
F B
G C
H D
I D
J D
K E
L E
M H
G
*/