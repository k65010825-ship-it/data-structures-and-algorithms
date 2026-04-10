//n（<100）个点 m条边的无权无向图为例
#include<stdio.h>
#include<stdlib.h>
//----------基于邻接矩阵存图为例-----------
//时间复杂度(DFS递归)：邻接表存图 O(n+m)(稀疏图快)
//                     邻接矩阵存图O(n*n)(稠密图快)
int n, m;
char point[105];
int edge[105][105];
int Find(char x) {
	for (int i = 1; i <= n; i++) {
		if (point[i] == x) {
			return i;
		}
	}
	return -1;
}
int vis[105];
void DFS(int i) {
	printf("%c", point[i]);
	vis[i] = 1;
	for (int j = 1; j <= n; j++) {
		if (edge[i][j] == 1 && !vis[j]) {
			DFS(j);
		}
	}
}
int main() {
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf(" %c", &point[i]);
	}
	for (int i = 1; i <= m; i++) {
		char x, y;
		scanf(" %c %c", &x, &y);
		int xi = Find(x);
		int yi = Find(y);
		edge[xi][yi] = edge[yi][xi] = 1;
	}
	for (int i = 1; i <= n; i++) {
		//考虑非(强)连通图
		if (!vis[i])DFS(i);
	}
	return 0;
}