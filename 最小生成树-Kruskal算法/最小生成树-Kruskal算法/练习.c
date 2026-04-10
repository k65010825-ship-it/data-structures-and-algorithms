#include<stdio.h>
#include<stdlib.h>
#define maxx 5000 //对与n个点,m条边的无向连通图,m的范围为n-1~~n*(n-1)/2 (完全图)
/*
给定一个带权无向连通图：该图中含有n(10<=n<=100)个点，m条边，n个点的数据刚好是0～～n-1
求该图的最小生成树：
即从m条边中，选出n-1条边，使得<图连通>并且<边权和最小>
输出最小生成树的边权和。(选边 + 贪心)
*/
//时间复杂度 取决于排序算法的时间复杂度
int n, m;
//用边集数组存图
struct Edge {
	int a;
	int b;
	int w;
}edge[maxx];
int fa[105];//使用并查集来高效地判断两个顶点是否已经连通（即是否属于同一个集合）
void Sort(int l, int r) {
	for (int i = l; i < r; i++) {
		int min = i;
		for (int j = i + 1; j <= r; j++) {
			if (edge[j].w < edge[min].w) {
				min = j;
			}
		}
		struct Edge temp = edge[min];
		edge[min] = edge[i];
		edge[i] = temp;
	}
}
int Find(int x) {
	if (fa[x] == x)return x;
	return fa[x] = Find(fa[x]);
}
void Kruskal() {
	for (int i = 0; i < n; i++) {
		fa[i] = i;//初始化:i的根就是它自己
	}
	int cnt = 0, sum = 0;
	for (int i = 1; i <= m; i++) {
		int fx = Find(edge[i].a);
		int fy = Find(edge[i].b);
		if (fx != fy) {
			cnt++;
			sum += edge[i].w;
			fa[fx] = fy;//将两个集合合并
			printf("选了%d %d之间 边权为%d\n", edge[i].a, edge[i].b, edge[i].w);
		}
		if (cnt == n - 1) break;
	}
	printf("最小边权和为%d\n", sum);
}
int main() {
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= m; i++) {
		scanf("%d %d %d", &edge[i].a, &edge[i].b, &edge[i].w);
	}
	Sort(1, m);//选择排序:时间复杂度O(m*m)
	Kruskal();//并查集选边:时间复杂度O(m+n)    所以时间复杂度取决于排序算法的时间复杂度
	return 0;
}