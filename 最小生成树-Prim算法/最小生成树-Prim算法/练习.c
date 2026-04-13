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
int Min(int a, int b) {
	return a < b ? a : b;
}
void Prim() {
	//随便选一个点作为起点
	int first = 0;
	int sum = 0;
	/*
	循环n次。
	每次选一个dist值最小的并且还没有被加入到生成树中的点，通过一条边加入到生成树中。
	*/
	for (int i = 1; i <= n; i++) {
		int dmin = inf;
		int min = -1;//dmin对应点的下标,初始为一个不存在的下标
		//枚举所有点,找离图距离最小的点
		for (int j = 0; j < n; j++) {
			if(dist[j]!=-1 && dist[j]<dmin)
			{
				dmin=dist[j];
				min=j;
			}
		}
		//第一次dist[j]都为inf,不会进入到for里的if
		//需要手动保证第一次选的点一定是起点
		if (min == -1) {
			dmin = 0;
			min = first;
		}
		//min加入到生成树中(dist[min]=-1)
		printf("点%d 通过边权为%d 加入到生成树中\n", min, dmin);
		sum += dmin;
		dist[min] = -1;
		//更新min的邻接点到生成树的距离
		for (int k = 0; k < n; k++) {
			if (dist[k] != -1 && edge[min][k] < inf) {
				dist[k] = Min(dist[k], edge[min][k]);
			}
		}
	}
	printf("最小生成树的边权和为%d\n", sum);
}
int main() {
	scanf("%d %d", &n, &m);
	//初始化每个点到图的距离为inf,并且每个点均无邻接点
	for (int i = 0; i < n; i++) {
		dist[i] = inf;
		for (int j = 0; j < n; j++) {
			edge[i][j] = inf;
		}
	}
	int x, y;
	for (int i = 0; i < m; i++) {
		scanf("%d %d %d", &x, &y, &w);
		edge[x][y] = edge[y][x] = w;
	}
	Prim();
	return 0;
}
