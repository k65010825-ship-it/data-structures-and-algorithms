#include<stdio.h>
#include<stdbool.h>
#define INF 10001
#define maxx 105
//n（<=100）个点,m条边的带权(边权<10000)无向图，求起点s到其他点的最短路径。
//默认点的数据是0～～n-1
int n, m;
int edge[maxx][maxx];
int dist[maxx];//到起点s的距离
int flag[maxx];//该点是否确定最短距离
int pre[maxx];
bool isConnect = true;
void Dijkstra(int s) {
	dist[s] = 0;
	flag[s] = 1;
	//更新起点的邻接点
	for (int i = 0; i < n; i++) {
		if (edge[s][i] < INF) {
			dist[i] = edge[s][i];
			if (i != s)pre[i] = s; //不写pre[i] = s，路径链就在离起点最近的那一层断掉，起点永远不会被打印出来
		}
	}
	//执行n-1次 每次确定起点到一个点的最短距离
	for (int i = 1; i <= n - 1; i++) {
		int dmin = INF;
		int min = -1;
		for (int j = 0; j < n; j++) {
			if (flag[j] == 0 && dist[j] < dmin) {
				dmin = dist[j];
				min = j;
			}
		}
		if (min == -1) {
			isConnect = false;
			break;
		}
		//此时min就是要找的点
		flag[min] = 1;
		//用min做中转点 更新其邻接点到s的最短路径
		for (int j = 0; j < n; j++) {
			if (flag[j] == 0 && dist[min] + edge[min][j] < dist[j]) {
				dist[j] = dist[min] + edge[min][j];
				pre[j] = min;
			}
		}
	}
}
int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		dist[i] = INF;
		pre[i] = -1;
		for (int j = 0; j < n; j++) {
			edge[i][j] = INF;
			if (i == j) {
				edge[i][j] = 0;
			}
		}
	}
	int x, y, w;
	for (int i = 0; i < m; i++) {
		scanf("%d %d %d", &x, &y, &w);
		edge[x][y] = edge[y][x] = w;
	}
	int s;
	scanf("%d", &s);
	Dijkstra(s);
	//输出路径
	if (!isConnect) {
		printf("该图为非连通图\n");
	}
	for (int i = 0; i < n; i++) {
		printf("%d到%d的最短路径为%d ", i, s, dist[i]);
		printf("路径为:");
		int p = i;
		while (p != -1) {
			printf("%d ", p);
			p = pre[p];
		}
		printf("\n");
	}
	return 0;
}