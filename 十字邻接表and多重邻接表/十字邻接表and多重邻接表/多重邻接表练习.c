//针对无向图：
//对同一条边malloc两次做优化（少一个malloc）
//以带权有向图为例。n个点 m条边  n<100  0<=w<=10000
//#include<stdio.h>
//#include<stdlib.h>
//int n, m;
//typedef struct Node {
//	int xi;
//	int yi;
//	int w;
//	struct Node* xnext;
//	struct Node* ynext;
//}Node,*LinkNode;
//struct Graph {
//	char data;
//	LinkNode edge;
//}point[105];
//int Find(char x) {
//	for (int i = 1; i <= n; i++) {
//		if (point[i].data == x) {
//			return i;
//		}
//	}
//	return -1;
//}
//int main() {
//	scanf("%d %d", &n, &m);
//	for (int i = 1; i <= n; i++) {
//		scanf(" %c", &point[i].data);
//		point[i].edge = NULL;
//	}
//	for (int i = 1; i <= m; i++) {
//		char x, y;
//		int w;
//		scanf(" %c %c %d", &x, &y, &w);
//		int xi = Find(x);
//		int yi = Find(y);
//		Node* p = (Node*)malloc(sizeof(Node));
//		p->xi = xi;
//		p->yi = yi;
//		p->w = w;
//		p->xnext = point[xi].edge;
//		point[xi].edge = p;
//		p->ynext = point[yi].edge;
//		point[yi].edge = p;
//	}
//	//找x的度
//	char x;
//	int count = 0;
//	scanf(" %c", &x);
//	int xi = Find(x);
//	Node* p = point[xi].edge;
//	while (p != NULL) {
//		count++;
//		if(xi==p->xi)p = p->xnext;//往x的链表找
//		else p = p->ynext;//往y的链表找
//	}
//	printf("度为：%d\n", count);
//	return 0;
//}
