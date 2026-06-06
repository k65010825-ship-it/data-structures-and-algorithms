#include<stdio.h>
#define INF 1000001
#define maxx 105
int n, m; //n<=100,边权不超过10000,假设n个点就是1～～n,以有向图为例
int edge[maxx][maxx];
int dp[maxx][maxx][maxx];//状态数组dp[k][i][j]: 允许用前k个点做中转点的情况下，任意两点(i,j)之间的最短距离
//时间复杂度：O(n^3) 空间复杂度O(n^3)
int Minn(int a, int b) {
	return a < b ? a : b;
}
int main() {
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			edge[i][j] = INF;
			if (i == j) {
				edge[i][j] = 0;
			}
		}
	}
	int x, y, w;
	for (int i = 1; i <= m; i++) {
		scanf("%d %d %d", &x, &y, &w);
		edge[x][y] = w;
	}
	//初始时 不允许经过中转点，两点间的最短距离就是直连的边
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			dp[0][i][j] = edge[i][j];
		}
	}

	//求中间状态 最终得到最终状态
	for (int k = 1; k <= n; k++) { //枚举中转点，现在把第k个加入做中转点
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				dp[k][i][j] = Minn(dp[k - 1][i][j], dp[k - 1][i][k] + dp[k - 1][k][j]); //状态转移方程
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			printf("%d--->%d的距离为%d\n", i, j, dp[n][i][j]);
		}
	}
	return 0;
}

/*
5 7
1 3 1
1 5 10
2 5 5
2 4 1
3 2 1
3 5 7
4 5 1
*/