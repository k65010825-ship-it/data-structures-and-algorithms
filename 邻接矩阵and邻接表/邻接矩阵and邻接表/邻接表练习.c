//带权无向图为例。n个点 m条边  n<100  0<=w<=10000
//如果是有向图，则要在Graph再定义一个逆邻接表，便于统计入边
//#include<stdio.h>
//#include<stdlib.h>
//int n, m;
//typedef struct Node {
//	int xi;
//	int w;
//	struct Node* next;
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
//LinkNode Head_insert(int xi,int yi,int w) {
//	Node* p = (Node*)malloc(sizeof(Node));
//	p->w = w;
//	p->xi = yi;
//	p->next = point[xi].edge;
//	point[xi].edge = p;
//	return point[xi].edge;
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
//		point[xi].edge = Head_insert(xi, yi, w);
//		point[yi].edge = Head_insert(yi, xi, w);
//	}
//	//找x的度
//	char x;
//	scanf(" %c", &x);
//	int xi = Find(x);
//	int count = 0;
//	Node* p = point[xi].edge;
//	while (p != NULL) {
//		count++;
//		p = p->next;
//	}
//	printf("%d\n", count);
//	return 0;
//}
