//针对有向图：
//对有向图邻接表和逆邻接表做优化（少一个malloc）
//以带权有向图为例。n个点 m条边  n<100  0<=w<=10000
//#include<stdio.h>
//#include<stdlib.h>
//int n, m;
//typedef struct Node {
//	int xi;
//	int yi;
//	int w;
//	struct Node* tnext;//弧尾
//	struct Node* hnext;//弧头
//}Node,*LinkNode;
//struct Graph {
//	char data;
//	LinkNode out;
//	LinkNode in;
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
//		point[i].out = point[i].in=NULL;
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
//		p->tnext = point[xi].out;
//		point[xi].out = p;
//		p->hnext = point[yi].in;
//		point[yi].in = p;
//	}
//	//找x的出度和入度
//	char x;
//	scanf(" %c", &x);
//	int xi = Find(x);
//	//出度 ->
//	int outCount = 0;
//	Node* p = point[xi].out;
//	while (p != NULL) {
//		outCount++;
//		p = p->tnext;
//	}
//	//入度
//	int inCount = 0;
//	Node* q = point[xi].in;
//	while (q != NULL) {
//		inCount++;
//		q = q->hnext;
//	}
//	printf("出度：%d 入度：%d\n", outCount, inCount);
//	return 0;
//}


