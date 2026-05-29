#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define m 5  //5阶B树,每个结点最多有4个关键字和5个孩子
typedef struct BNode {
	int* key;
	struct BNode* parent;
	struct BNode** child;
	int keyNum; //当前关键字数
}BNode, * BTree;
typedef struct Result {
	BNode* node;
	int index; //Result->node->key[index]就是要找的关键字
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
	//这里的p开始时是内部终端节点,但是后续递归分裂父结点时,p会变为内部非终端节点,所以newNode必须复制p的孩子指针
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
	if (res.found) {
		return T; //关键字已存在,不插入
	}
	BNode* p = res.node; //k要插入的结点p一定是内部终端节点
	int i = res.index;
	//在p->key[i-1]和p->key[i]之间插入k，p为内部终端节点,所以p->child[i]==NULL，不需要移动孩子指针
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

BTree UnionNode(BTree T, BNode* p, BNode* bro, int i) {
	BNode* parent = p->parent;

	//合并parent->key[i]
	p->key[p->keyNum++] = parent->key[i];

	//合并bro的所有key
	for (int j = 0; j < bro->keyNum; j++) {
		p->key[p->keyNum++] = bro->key[j];
	}

	//合并bro的所有child：注意p->keyNum在复制key时已经被改了，所以要推算出bro的child在p->child中的位置
	int pos = p->keyNum - bro->keyNum; // pos = p->keyNum - bro->keyNum = (原始keyNum + 1 + bro->keyNum) - bro->keyNum = 原始keyNum + 1
	for (int j = 0; j <= bro->keyNum; j++) {
		p->child[pos + j] = bro->child[j];
		if (p->child[pos + j] != NULL)
			p->child[pos + j]->parent = p;
	}

	//删除parent->key[i]和parent->child[i+1]
	for (int j = i + 1; j < parent->keyNum; j++) {
		parent->key[j - 1] = parent->key[j];
		parent->child[j] = parent->child[j + 1];
	}
	parent->keyNum--;

	free(bro->key);
	free(bro->child);
	free(bro);

	return T;
}
BTree Delete(BTree T, int k) {
	if (T == NULL) {
		return T;
	}
	Result res = Find(T, k);
	if (!res.found) {
		return T;
	}
	BNode* p = res.node;
	int i = res.index;
	//p不是内部终端节点,需要找到p->key[i]的后继关键字替换p->key[i],然后删除那个后继关键字
	//为什么要转换呢?因为B树的删除只能删除内部终端节点的关键字,如果p->key[i]在内部非终端节点,直接删除会破坏B树的性质
	if (p->child[i] != NULL) {
		//找到右子树的最小关键字,替换p->key[i],然后删除那个最小关键字
		//为什么选择右子树的最小关键字而不选择左子树的最大关键字?因为child[0]==NULL，唯一、固定，写起来更简单
		BNode* minNode = p->child[i + 1];
		while (minNode->child[0] != NULL) {
			minNode = minNode->child[0];
		}
		p->key[i] = minNode->key[0];
		//转化为删除右子树的最小关键字
		p = minNode;
		i = 0;
	}
	else {
		for (int j = i + 1; j < p->keyNum; j++) {
			p->key[j - 1] = p->key[j];
		}
	}
	p->keyNum--;
	//p为根结点时，如果p->keyNum==0,树就空了，需要特殊处理
	if (p->parent == NULL) {
		if (p->keyNum == 0) {
			free(p->key);
			free(p->child);
			free(p);
			return NULL;
		}
		return T;
	}
	if (p->keyNum >= (m - 1) / 2) {  // keyNum的下界为ceil(m/2)-1，等价于(m-1)/2 
		return T;
	}
	//需要找兄弟结点借一个关键字或者和兄弟结点合并
	while (p != NULL && p->parent != NULL && p->keyNum < (m - 1) / 2) {
		BNode* parent = p->parent;
		int ci = 0; //parent->child[ci] = p
		while (ci <= parent->keyNum && parent->child[ci] != p) {
			ci++;
		}
		//child[0 - parent->keyNum]
		BNode* lbro = (ci > 0) ? parent->child[ci - 1] : NULL;
		BNode* rbro = (ci < parent->keyNum) ? parent->child[ci + 1] : NULL;
		// 向左兄弟借
		// 注意：keyNum要比下界 (m-1)/2 多一个才能借
		if (lbro != NULL && lbro->keyNum > (m - 1) / 2) {
			for (int j = p->keyNum - 1; j >= 0; j--) {
				p->key[j + 1] = p->key[j];
			}
			for (int j = p->keyNum; j >= 0; j--) {
				p->child[j + 1] = p->child[j];
			}

			//parent->key[ci-1]下移到p->key[0]
			p->key[0] = parent->key[ci - 1];
			//lbro->key[lbro->keyNum - 1]上移到parent->key[ci-1]
			parent->key[ci - 1] = lbro->key[lbro->keyNum - 1];

			p->child[0] = lbro->child[lbro->keyNum];
			if (p->child[0] != NULL) {
				p->child[0]->parent = p;
			}

			lbro->keyNum--;
			p->keyNum++;
			return T;
		}
		// 向右兄弟借
		// 注意：keyNum要比下界 (m-1)/2 多一个才能借
		if (rbro != NULL && rbro->keyNum > (m - 1) / 2) {
			//parent->key[ci]下移到p->key[p->keyNum]
			p->key[p->keyNum] = parent->key[ci];
			//rbro->key[0]上移到parent->key[ci]
			parent->key[ci] = rbro->key[0];

			p->child[p->keyNum + 1] = rbro->child[0];
			if (p->child[p->keyNum + 1] != NULL) {
				p->child[p->keyNum + 1]->parent = p;
			}

			for (int j = 1; j < rbro->keyNum; j++) {
				rbro->key[j - 1] = rbro->key[j];
			}
			for (int j = 1; j <= rbro->keyNum; j++) {
				rbro->child[j - 1] = rbro->child[j];
			}

			rbro->keyNum--;
			p->keyNum++;
			return T;
		}
		// 借不了:和兄弟结点合并
		if (rbro != NULL) {
			return UnionNode(T, p, rbro, ci); // 同时合并parent->key[ci]
		}
		else if (lbro != NULL) {
			return UnionNode(T, lbro, p, ci - 1); // 同时合并parent->key[ci-1]
		}
		p = parent; //循环向上检查父结点是否需要借或合并
	}
	//循环退出后统一做根坍塌处理
	if (T != NULL && T->keyNum == 0) {
		BNode* newRoot = T->child[0]; //keyNum==0,孩子数=keyNum+1=1,唯一的孩子就是child[0]
		if (newRoot != NULL) {
			newRoot->parent = NULL;
		}
		free(T->key);
		free(T->child);
		free(T);
		return newRoot;
	}
	return T;
}
void Printt(BTree T, int level) {
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
		Printt(T->child[i], level);
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

	Printt(T, 0);

	T = Delete(T, 2);
	T = Delete(T, 5);
	T = Delete(T, 10);

	Printt(T, 0);
	return 0;
}