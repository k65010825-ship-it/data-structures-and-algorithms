//#include<stdio.h>
//#include<stdlib.h>
//#define maxx 20
//typedef struct ArrayList {
//	int* data;
//	int s;//表长
//}Array;
//Array initarray() {
//	Array a;
//	a.data = (int*)malloc(sizeof(int) * maxx);
//	a.s = 0;
//	return a;
//}
////末尾添加一个数据k
//void add(Array*a, int k) {
//	if (a->s == maxx) {
//		printf("顺序表已满，无法添加");
//		return;
//	}
//	a->data[a->s] = k;
//	a->s++;
//}
////在下标i位置插入数据k
//void insert(Array* a, int i,int k) {
//	if (a->s == maxx) {
//		printf("顺序表已满，无法插入");
//		return;
//	}
//	for (int j = a->s - 1; j >= i; j--) {
//		a->data[j + 1] = a->data[j];
//	}
//	a->data[i] = k;
//	a->s++;
//}
////查找数据k
//int find(Array* a, int k) {
//	for (int i = 0; i < a->s; i++) {
//		if (a->data[i] == k) {
//			return i;
//		}
//	}
//	return -1;
//}
////删除数据k
//void delete(Array* a, int k) {
//	int i = find(&a, k);
//	if (i == -1) {
//		printf("数据%d不存在，无法删除", k);
//		return;
//	}
//	for (int j = i + 1; j < a->s; j++) {
//		a->data[j - 1] = a->data[j];
//	}
//	a->s--;
//}
////打印顺序表
//void show(Array a) {
//	if (a.s == 0) {
//		printf("空表");
//		return;
//	}
//	for (int i = 0; i < a.s; i++) {
//		printf("%d ", a.data[i]);
//	}
//	printf("\n");
//}
//int main()
//{
//	    Array a;//声明一个顺序表；
//		a=initarray();
//		add(&a,1);
//		add(&a,8);
//		add(&a,2);
//		add(&a,7);
//		add(&a,0);
//		show(a);
//		insert(&a,1,3);
//		insert(&a,3,5);
//		show(a);
//		int i=find(&a,7);//理论上可以用值传递(不需要改变a)但是Insert函数要用到Find函数,故需保持数据类型一致
//		if(i==-1)printf("7不存在\n");
//		else
//		printf("数据7的位置是:%d\n",i);
//		delete(&a,8);
//		show(a);
//		return 0;
//}