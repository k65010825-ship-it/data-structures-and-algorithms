#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define maxx 205 //HuffmanTree中存储2*n-1个结点,n个带权值的叶子结点(下标0~n-1),n-1个两个叶子结点合并后新增的结点(下标n~2n-2)
int n;//要对n个字符编码,n<=100
int weight[105];//保存权值
char a[105];//保存字符
struct HuffmanNode {
	int w;//权值
	int fa;//父亲的下标
	int l, r;//左,右孩子的下标
}t[maxx];
void InitHuffmanTree() {
	for (int i = 0; i < n; i++) {
		t[i].w = weight[i];
		t[i].fa = -1;
		t[i].l = t[i].r = -1;
	}
}
void Find(int x, int* xi, int* yi) {//找到权值最小且均为根结点的两个结点的下标(xi,yi),之后进行合并
	//最小
	int min1;
	for (int i = 0; i < x; i++) {
		if (t[i].fa == -1) {
			min1 = i;
			break;
		}
	}
	for (int i = 0; i < x; i++) {
		if (t[i].fa == -1 && t[i].w < t[min1].w) {
			min1 = i;
		}
	}
	*xi = min1;
	//第二小
	int min2;
	for (int i = 0; i < x; i++) {
		if (t[i].fa == -1 && i != min1) {
			min2 = i;
			break;
		}
	}
	for (int i = 0; i < x; i++) {
		if (t[i].fa == -1 && t[i].w < t[min2].w && i!=min1) {
			min2 = i;
		}
	}
	*yi = min2;
}
void CreateHuffmanTree() {
	int xi, yi; //权值最小且均为根结点的两个结点的下标
	for (int i = n; i < 2 * n - 1; i++) {
		Find(i, &xi, &yi);
		t[i].w = t[xi].w + t[yi].w;
		t[i].fa = -1;
		t[i].l = xi;
		t[i].r = yi;
		t[xi].fa = t[yi].fa = i;
	}
}
char** CreatCode() {
	//一共有n个编码,每个编码的长度暂时还不知道
	char** codes = (char**)malloc(sizeof(char*) * n);
	memset(codes, 0, sizeof(char*) * n);
	//每个编码最长为n-1(类似斜着的情况)  下标0~~n-2
	char* temp = (char*)malloc(sizeof(char) * n);
	for (int i = 0; i < n; i++) {
		int start = n - 1;//存放编码字符的位置
		temp[start] = '\0';
		int p = i;
		while (t[p].fa != -1) {
			int fp = t[p].fa;//取p父亲的下标,原因:判断p是左孩子还是右孩子
			if (t[fp].l == p)temp[--start] = '1';
			else temp[--start] = '0';
			p = t[p].fa;
		}
		codes[i] = (char*)malloc(sizeof(char) * (n - start));
		strcpy(codes[i], &temp[start]);//从temp数组的第start位开始复制,直到遇到'\0'为止
		                               //注意:temp[start] = 字符值 → 必须&取地址
	}
	return codes;
}
int main() {
	scanf("%d", &n);
	getchar();//输入n后的吞掉换行符
	for (int i = 0; i < n; i++) {
		scanf("%c", &a[i]);
	}
	for (int i = 0; i < n; i++) {
		scanf("%d", &weight[i]);
	}
	InitHuffmanTree();
	CreateHuffmanTree();
	char**codes=CreatCode();
	for (int i = 0; i < n; i++) {
		printf("%c的编码为%s\n", a[i], codes[i]);
	}
	return 0;
}
