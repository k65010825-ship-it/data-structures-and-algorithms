/*
求含有n个点m条边的有向图(n<100)的拓扑序列的算法，即拓扑排序
注意:拓扑序列只有有向无环图具有
*/
#include<stdio.h>
#include<stdlib.h>
#define maxx 105
//栈:存入度=0的点的下标
typedef struct SNode {
	int xi;
	struct SNode* next;
}SNode,*LinkedStack;
LinkedStack initStack() {
	SNode* p = (SNode*)malloc(sizeof(SNode));
	p->next = NULL;
	return p;
}
int Pop(LinkedStack s) {
	if (s->next == NULL) {
		printf("栈空\n");
		return -1;
	}
	SNode* p = s->next;
	int xi = p->xi;
	s->next = p->next;
	free(p);
	p = NULL;
	return xi;
}
void Push(LinkedStack s,int data) {
	SNode* p = (SNode*)malloc(sizeof(SNode));
	p->xi = data;
	p->next = s->next;
	s->next = p;
}
//邻接表存图
int n, m;
typedef struct ENode {
	int xi;
	struct ENode* next;
}ENode,*LinkedENode;
struct Graph {
	char data;
	LinkedENode first;//邻接表(出边)
}g[maxx];
int indu[maxx];//统计每个点的入度
char topo[maxx];
int index;//用于存储topo序列的'指针'
int Find(char x) {
	for (int i = 0; i < n; i++) {
		if (g[i].data == x) {
			return i;
		}
	}
	return -1;
}
void Topo() {
	LinkedStack s = initStack();
	for (int i = 0; i < n; i++) {
		if (indu[i] == 0) {
			Push(s, i);
		}
	}
	for (int i = 1; i <= n; i++) { //执行n次,把每个点都加入topo序列
		int xi = Pop(s);
		if (xi == -1) { //栈空,说明有环
			break;
		}
		topo[++index] = g[xi].data;
		ENode* p = g[xi].first;//出边表
		while (p != NULL) {
			indu[p->xi]--;//该点的出边表的点的入度-1
			if (indu[p->xi] == 0) {
				Push(s, p->xi);
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
	int xi, yi;
	for (int i = 0; i < m; i++) {
		scanf(" %c %c", &x, &y);//x -> y
		int xi = Find(x);
		int yi = Find(y);
		indu[yi]++;
		ENode* p = (ENode*)malloc(sizeof(ENode));
		p->xi = yi;
		p->next = g[xi].first;
		g[xi].first = p;
	}
	Topo();
	if (index != n) {
		printf("有环,无拓扑序列\n");
	}
	else {
		for (int i = 1; i <= n; i++) {
			printf("%c", topo[i]);
		}
	}
	return 0;
}
