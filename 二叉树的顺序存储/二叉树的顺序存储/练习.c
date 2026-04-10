//#include<stdio.h>
//#define maxx 100
//char data[maxx];
//int flag;//0：左孩子 1：右孩子
//int Find(char x) {
//	int i;
//	for (i = 1; i < maxx; i++) {
//		if (data[i] == x) {
//			break;
//		}
//	}
//	return i;
//}
//int main() {
//	int n;//树中共n个结点
//	scanf("%d", &n);
//	for (int i = 0; i < maxx; i++) {
//		data[i] = ' ';
//	}
//	char root,x,fx;
//	scanf(" %c", &root);
//	data[1] = root;
//	for (int i = 1; i < n; i++) {
//		scanf(" %c %c %d", &x,&fx,&flag);
//		int fxi = Find(fx);
//		if (!flag) {
//			data[fxi * 2] = x;
//		}
//		else {
//			data[fxi * 2 + 1] = x;
//		}
//	}
//	scanf(" %c", &x);
//	int xi = Find(x);
//	//找x的父亲
//	if (xi == 1) {
//		printf("%c为根结点\n", x);
//	}
//	else {
//		printf("%c的父亲是%c\n", x, data[xi / 2]);
//	}
//	//找x的儿子
//	if (data[xi * 2] == ' ' && data[xi * 2 + 1] == ' ') {
//		printf("%c为叶子结点\n", x);
//	}
//	else {
//		if (data[xi * 2] != ' ') {
//			printf("%c的左孩子为%c\n", x, data[xi * 2]);
//		}
//		if (data[xi * 2 + 1] != ' ') {
//			printf("%c的右孩子为%c\n", x, data[xi * 2 + 1]);
//		}
//	}
//	return 0;
//}