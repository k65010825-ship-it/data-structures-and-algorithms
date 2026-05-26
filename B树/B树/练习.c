#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define m 5  //5阶B树,每个结点最多有4个关键字和5个孩子
typedef struct BNode {
	int* key;
	struct BNode* parent;
	struct BNode** child;
	int keyNum; //当前关键字数
}BNode,*BTree;
typedef struct Result {
	BNode* node;
	int index; //Result->r->key[index]就是要找的关键字
	bool found; //是否找到
}Result;
BNode* CreateNode() {
	BNode* p = (BNode*)malloc(sizeof(BNode));
	p->key = (int*)malloc(sizeof(int) * m); //先插入数据再分裂,所以要预留一个位置
	p->child = (BNode**)malloc(sizeof(BNode*) * (m + 1)); //孩子数比关键字数多1
	for (int i = 0; i < m + 1; i++) {
		p->child[i] = NULL;
	}
	p->parent = NULL;
	p->keyNum = 0;
	return p;
}
Result Find(BTree T, int k) {
	Result res;
	res.node = NULL;
	res.index = 0;
	res.found = false;
	BNode* p = T;
	while (p != NULL) {
		int i = 0;
		while (i < p->keyNum && p->key[i] < k) {
			i++;
		}
		//跳出while时,要么i==p->keyNum,要么p->key[i]>=k
		if (i < p->keyNum && k == p->key[i]) {
			res.node = p;
			res.index = i;
			res.found = true;
			return res;
		}
		if (p->child[i] == NULL) {
			res.node = p;
			res.index = i;
			res.found = false;
			return res;
		}
		p = p->child[i];
	}
	return res;
}
BTree SplitNode(BTree T, BNode* p) {
	BNode* newNode = CreateNode();
	int mid = m / 2; //中间位置的索引
	newNode->keyNum = p->keyNum - mid - 1; //新结点的关键字数
	for (int j = 0; j < newNode->keyNum; j++) {
		newNode->key[j] = p->key[mid + 1 + j];
	}
	for (int j = 0; j <= newNode->keyNum; j++) {
		newNode->child[j] = p->child[mid + 1 + j];
		if (newNode->child[j] != NULL) {
			newNode->child[j]->parent = newNode;
		}
	}
	p->keyNum = mid; //原结点的关键字数


	//--------------------------------------


	if (p->parent == NULL) {
		//p是根结点,需要创建新的根结点
		BNode* newRoot = CreateNode();
		newRoot->key[0] = p->key[mid];
		newRoot->keyNum = 1;
		newRoot->child[0] = p;
		newRoot->child[1] = newNode;
		p->parent = newRoot;
		newNode->parent = newRoot;
		return newRoot; //新的根结点
	}
	else {
		//p不是根结点,将中间关键字插入父结点
		BNode* parent = p->parent;
		int j = 0;
		while (j < parent->keyNum && parent->key[j] < p->key[mid]) {
			j++;
		}
		for (int k = parent->keyNum - 1; k >= j; k--) {
			parent->key[k + 1] = parent->key[k];
			parent->child[k + 2] = parent->child[k + 1];
		}
		parent->key[j] = p->key[mid];
		parent->child[j + 1] = newNode;
		parent->keyNum++;
		newNode->parent = parent;
		if (parent->keyNum < m) {
			return T; //不需要继续分裂
		}
		T = SplitNode(T, parent); //继续分裂父结点
	}
}
BTree Insert(BTree T, int k) {
	if (T == NULL) {
		T = CreateNode();
		T->key[0] = k;
		T->keyNum = 1;
		return T;
	}
	Result res = Find(T, k);
	if(res.found) {
		return T; //关键字已存在,不插入
	}
	BNode* p = res.node;
	int i = res.index;
	//在p->key[i-1]和p->key[i]之间插入k
	for (int j = p->keyNum - 1; j >= i; j--) {
		p->key[j + 1] = p->key[j];
	}
	p->key[i] = k;
	p->keyNum++;
	if (p->keyNum < m) {
		return T; //不需要分裂
	}
	//需要分裂
	T = SplitNode(T, p);
	return T;
}
void Printt(BTree T,int level) {
	if (T == NULL) {
		return;
	}
	for (int i = 0; i < level; i++) {
		printf("	");
	}
	level += 1;
	for (int i = 0; i < T->keyNum; i++) {
		printf("%d ", T->key[i]);
	}
	printf("\n");
	for (int i = 0; i <= T->keyNum; i++) {
		Printt(T->child[i],level);
	}
}
int main() {
	BTree T = NULL;
	// 第一层（根）
	T = Insert(T, 30);

	// 第二层
	T = Insert(T, 15);
	T = Insert(T, 45);
	T = Insert(T, 10);

	// 开始分裂 → 出现第三层
	T = Insert(T, 20);
	T = Insert(T, 5);
	T = Insert(T, 25);
	T = Insert(T, 35);
	T = Insert(T, 40);
	T = Insert(T, 50);

	// 大量插入 → 树变深，形成 3～4 层
	T = Insert(T, 2);
	T = Insert(T, 7);
	T = Insert(T, 12);
	T = Insert(T, 17);
	T = Insert(T, 22);
	T = Insert(T, 27);
	T = Insert(T, 32);
	T = Insert(T, 37);
	T = Insert(T, 42);
	T = Insert(T, 47);
	T = Insert(T, 52);

	Printt(T,0);
	return 0;
}
