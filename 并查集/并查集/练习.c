#include<stdio.h>
#define maxx 5005
int fa[maxx];
int n, m, p;//初始有n个数据(每个数据范围1~~n) m个亲戚关系 p个询问关系

//找x的根
int Find(int x) {
	//x自己就是根
	if (fa[x] == -1)return x;
	return fa[x] = Find(fa[x]);
	//1.递归找x的父亲的根 
	//2.将x直接连到根上,提高查找效率(路径压缩)------时间复杂度:阿克曼反函数α(x),x->1e9,约等于4
}
int main() {
	scanf("%d %d %d", &n, &m, &p);
	for (int i = 0; i <= n; i++) {
		fa[i] = -1; //-1表示没有父亲,每个数据都是一个独立的集合,根就是自己
	}
	int x, fx, y, fy;
	for (int i = 0; i < m; i++) {
		scanf("%d %d", &x, &y);
		fx = Find(x);
		fy = Find(y);
		if (fx != fy) {
			fa[fy] = fx;//将两个集合的数据合并,也可以是fa[fx]=fy;
		}
	}
	for (int i = 0; i < p; i++) {
		scanf("%d %d", &x, &y);
		fx = Find(x);
		fy = Find(y);
		if (fx == fy)printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}