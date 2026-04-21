#include<stdio.h>
#include<stdlib.h>
#define maxx 105
#define INF 10001
/*
  含有n个点m条边的AOE网  n<100 边权小于10000
  AOV（Activity On Vertex）：顶点表示活动
  AOE（Activity On Edge）：顶点表示事件,边表示活动
*/

//基于topo排序序列
int indu[maxx];
int topo[maxx];
int idx;
typedef struct SNode {
	int xi;
	struct SNode* next;
}SNode,*Stack;
Stack InitStack() {
	SNode* p = (SNode*)malloc(sizeof(SNode));
	p->next = NULL;
	return p;
}
void Push(Stack s, int x) {
	SNode* p = (SNode*)malloc(sizeof(SNode));
	p->xi = x;
	p->next = s->next;
	s->next = p;
}
int Pop(Stack s) {
	SNode* p = s->next;
	int x = p->xi;
	s->next = p->next;
	free(p);
	p = NULL;
	return x;
}
int n, m;
typedef struct ENode {
	int xi;
	int w;
	struct ENode* next;
}ENode;
struct Graph {
	char data;
	ENode* first;
}g[maxx];
int Find(char x) {
	for (int i = 0; i < n; i++) {
		if (g[i].data == x) {
			return i;
		}
	}
	return -1;
}
int etv[105];//事件(顶点)的最早发生时间
int ltv[105];//事件(顶点)的最晚发生时间
int Maxx(int a, int b) {
	return a > b ? a : b;
}
int Minn(int a, int b) {
	return a > b ? b : a;
}
void Topo() {
	Stack s = InitStack();
	for (int i = 0; i < n; i++) {
		if (indu[i] == 0) {
			Push(s, i);
		}
	}
	for (int i = 1; i <= n; i++) {
		int xi = Pop(s);
		topo[idx++] = xi;
		ENode* p = g[xi].first;
		while (p != NULL) {
			indu[p->xi]--;
			if (indu[p->xi] == 0) {
				Push(s, p->xi);
			}
			//同时更新进入topo序列的点的邻接事件的最早发生时间
			etv[p->xi] = Maxx(etv[p->xi], etv[xi] + p->w);
			p = p->next;
		}
	}
}
void CriticalPath() {
	//初始化ltv数组
	int end = topo[n - 1];//拓扑序列中的最后一个是终点
	for (int i = 0; i < n; i++) {
		ltv[i] = etv[end];//终点的最晚发生时间==终点的最早发生时间,且ltv[i]不会超过ltv[end]
	}
	//求每个事件的最晚发生时间ltv(倒着遍历)
	for (int i = n - 1; i >= 0; i--) {
		//目标:求xi的ltv
		int xi = topo[i];
		ENode* p = g[xi].first;
		//逆向思维
		while (p != NULL) {
			int yi = p->xi;
			ltv[xi] = Minn(ltv[xi], ltv[yi] - p->w);
			p = p->next;
		}
	}
	//枚举所有的边，找关键活动(ete==lte)
	printf("关键活动有:\n");
	for (int i = 0; i < n; i++) {
		ENode* p = g[i].first;
		while (p != NULL) {
			//活动的最早开始时间ete:即活动开始事件的最早开始时间
			int ete = etv[i];
			//活动的最晚开始时间lte:即活动结束事件的最晚开始时间减去边权
			int lte = ltv[p->xi] - p->w;
			if (ete == lte) {
				printf("%c -> %c\n", g[i].data, g[p->xi].data);
			}
			p = p->next;
		}
	}
}
int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf(" %c", &g[i].data);
		g[i].first = NULL;
	}
	char x, y;
	int w;
	for (int i = 0; i < m; i++) {
		scanf(" %c %c %d", &x, &y, &w);//x->y
		ENode* p = (ENode*)malloc(sizeof(ENode));
		p->w = w;
		int xi = Find(x);
		int yi = Find(y);
		p->xi = yi;
		p->next = g[xi].first;
		g[xi].first = p;
		indu[yi]++;
	}
	Topo();
	CriticalPath();
	return 0;
}
