//#include<stdio.h>
//#define maxx 100
//char data[maxx];
//int n;
//int Find(char x) {
//	int i;
//	for (i = 1; i <= n; i++) {
//		if (data[i] == x) {
//			break;
//		}
//	}
//	return i;
//}
//int main() {
//	scanf("%d", &n);
//	for (int i = 1; i <= n; i++) {
//		scanf(" %c", &data[i]);
//	}
//	char x;
//	scanf(" %c", &x);
//	int xi = Find(x);
//	//找x的父亲
//	if (xi == 1) {
//		printf("%c为根结点\n", x);
//	}
//	else {
//		printf("%c的父亲是%c\n", x, data[xi / 2]);
//	}
//	//找x的孩子
//	if (xi * 2 > n) {
//		printf("%c为叶子结点\n", x);
//	}
//	else {
//		//完全二叉树中有右孩子就一定有左孩子
//		printf("%c的左孩子为%c\n", x, data[xi * 2]);
//		if (xi * 2 + 1 <= n) {
//			printf("%c的右孩子为%c\n", x, data[xi * 2 + 1]);
//		}
//	}
//	return 0;
//}