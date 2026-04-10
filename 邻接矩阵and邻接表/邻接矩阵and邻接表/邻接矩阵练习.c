//带权无向图为例。n个点 m条边  n<=100 ,权值：0<=w<=10000
//#include<stdio.h>
//#define inf 10001
//int n, m;
//char point[105];
//int edge[105][105];
//int Find(char x) {
//	for (int i = 1; i <= n; i++) {
//		if (x == point[i]) {
//			return i;
//		}
//	}
//	return -1;
//}
//int main() {
//	scanf("%d %d", &n, &m);
//	getchar();
//	for (int i = 1; i <= n; i++) {
//		scanf("%c", &point[i]);
//	}
//	for (int i = 1; i <= n; i++) {
//		for (int j = 1; j <= n; j++) {
//			edge[i][j] = inf;
//			//if (i == j)edge[i][j] = 0; 看题目情况:自边是0还是inf
//		}
//	}
//	for (int i = 1; i <= m; i++) {
//		char x, y;
//		int w;
//		scanf(" %c %c %d", &x, &y,&w);
//		int xi = Find(x);
//		int yi = Find(y);
//		edge[xi][yi] = edge[yi][xi] = w;
//	}
//	//计算点x的度
//	char x;
//	scanf(" %c", &x);
//	int xi = Find(x);
//	int count = 0;
//	for (int i = 1; i <= n; i++) {
//		if (edge[xi][i] != inf) {
//			count++;
//		}
//	}
//	printf("%d\n", count);
//}