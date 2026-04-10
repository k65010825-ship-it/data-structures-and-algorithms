//n（<100）个点 m条边的无权无向图为例
#include<stdio.h>
#include<stdlib.h>
#define maxx 105
int n, m;

//-----------基于循环队列为例------------
typedef struct QNode {
	int* data;
	int f, r;
}Queue;
void InitQueue(Queue*q) {
	q->data = (int*)malloc(sizeof(int) * maxx);
	q->f = q->r = 0;
}
void EnQueue(Queue* q,int x) {
	if (q->f == ((q->r + 1) % maxx)) {
		printf("队列已满,无法入队\n");
		return;
	}
	q->data[q->r] = x;
	q->r = (q->r + 1) % maxx;
}
int DeQueue(Queue* q) {
	if (q->f == q->r) {
		printf("队列已空,无法出队\n");
		return -1;
	}
	int x = q->data[q->f];
	q->f = (q->f + 1) % maxx;
	return x;
}
//----------基于邻接表存图为例-----------
//BFS时间复杂度：邻接表存图 O(n+m)(稀疏图快)    (因为邻接表只要在该点的邻接表中存该点的邻接点)(对于无向图,所有邻接表的结点个数之和为2 * m ;对于有向图,所有邻接表的结点个数之和为 m)
//               邻接矩阵存图O(n*n)(稠密图快)   (因为邻接矩阵要在该点所在的行中存所有点的值)  (对于无向图, ==1 是邻接点, ==0 不是邻接点;对于有向图,==权值 是邻接点,==inf 不是邻接点)(但每行始终有n个值)
typedef struct Node {
	int xi;
	struct Node* next;
}Node,*LinkNode;
struct Graph {
	char data;
	LinkNode edge;
}point[maxx];
int Find(char x) {
	for (int i = 1; i <= n; i++) {
		if (point[i].data == x) {
			return i;
		}
	}
	return -1;
}
LinkNode Head_insert(int xi, int yi) {
	Node* p = (Node*)malloc(sizeof(Node));
	p->xi = yi;
	p->next = point[xi].edge;
	point[xi].edge = p;
	return point[xi].edge;
}
int vis[105];//标记有没有入队过，默认为0表示没有入过队
int dis[105];//拓展:BFS可以计算无权图到"根结点"最短路径(分层思想)
void InitDis() {
	for (int i = 1; i <= n; i++) {
		dis[i] = m + 1;//将dis初始化为inf
	}
}
void BFS(int i) {
	InitDis();
	Queue q;
	InitQueue(&q);
	EnQueue(&q, i);
	vis[i] = 1;
	dis[i] = 0;
	while (q.f != q.r) {//队列不为空
		int s = DeQueue(&q);
		printf("%c %d ", point[s].data,dis[s]);
		Node* p = point[s].edge;
		while (p != NULL) {
			if (!vis[p->xi]) {
				EnQueue(&q, p->xi);
				vis[p->xi] = 1;
				dis[p->xi] = dis[s] + 1;
			}
			p = p->next;
		}
	}
}
int main() {
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf(" %c", &point[i].data);
		point[i].edge = NULL;
	}
	for (int i = 1; i <= m; i++) {
		char x, y;
		scanf(" %c %c", &x, &y);
		int xi = Find(x);
		int yi = Find(y);
		point[xi].edge = Head_insert(xi, yi);
		point[yi].edge = Head_insert(yi, xi);
	}
	for (int i = 1; i <= n; i++) {//考虑非(强)连通图
		if (!vis[i])BFS(i);
	}
	printf("\n");
	return 0;
}