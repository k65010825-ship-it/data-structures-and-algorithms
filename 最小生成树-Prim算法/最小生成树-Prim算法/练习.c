#include<stdio.h>
#define maxx 105
#define inf 10001
/*
给定一个带权无向连通图：该图中含有n(10<=n<=100)个点，m条边，n个点的数据刚好是0～～n-1
边权的范围(0 <= w <= 10000)
求该图的最小生成树：
即从m条边中，选出n-1条边，使得<图连通>并且<边权和最小>
输出最小生成树的边权和。(选点 + 贪心)
*/
int n, m;
int w;
int edge[maxx][maxx];
int dist[maxx];//每个点到生成树的距离(初始为inf)
void Prim() {
	//随便选一个点作为起点
	int first = 0;
	dist[0] = -1;//表示该点已经在图中
	/*
	循环n次。
	每次选一个dist值最小的并且还没有被加入到生成树中的点p，通过一条边加入到生成树中。
	更新p的邻接点到生成树到最小距离 dist[j]=min
	*/
	for (int i = 0; i < n; i++) {
		int dmin = inf;
	}
}
int main() {
	scanf("%d %d", &n, &m);
	//初始化
	for (int i = 0; i < n; i++) {
		dist[i] = inf;
		for (int j = 0; j < n; j++) {
			edge[i][j] = inf;
		}
	}
	int x, y;
	for (int i = 0; i < n; i++) {
		scanf("%d %d %d", &x, &y, &w);
		edge[x][y] = edge[y][x] = w;
	}
	Prim();
	return 0;
}