#include<stdio.h>
#include<string.h>
int main() {
	char s[255]; //主串
	char t[255]; //模式串
	scanf("%s", s);
	getchar();
	scanf("%s", t);
	int lens = strlen(s);
	int lent = strlen(t);
	if (lens < lent) {
		printf("-1/n");
		return 0;
	}
	//1.计算next数组
	int next[255];
	next[0] = -1;
	next[1] = 0;
	int idx = 2;
	int x = 0; //x = next[idx-1],初始idx = 2,x = next[1] = 0 
	while (idx < lent) {
		if (x == -1 || t[x] == t[idx - 1])
		{
			next[idx] = x + 1;
			x++;
			idx++;
		}
		else {
			x = next[x];
		}
	}
	//2.KMP匹配
	int i = 0, j = 0;
	while (i < lens && j < lent) {
		if (j == -1 || s[i] == t[j]) {
			i++;
			j++;
		}
		else {
			j = next[j];
		}
	}
	if (j == lent) {
		printf("%d\n", i - lent);
	}
	else {
		printf("-1\n");
	}
	return 0;
}