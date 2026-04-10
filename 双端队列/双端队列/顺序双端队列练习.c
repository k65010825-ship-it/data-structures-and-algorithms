//认为 l指向真正的左端数据，如果认为 r指向真正的右端数据后一个位置
//#include<stdio.h>
//#include<stdlib.h>
//#define maxx 6
//typedef struct Deque {
//	int* data;
//	int l, r;
//}Deque;
//Deque InitDeque() {
//	Deque q;
//	q.data = (int*)malloc(sizeof(int) * maxx);
//	q.l = q.r = 0;
//	return q;
//}
//void LInsert(Deque* q, int k) {
//	if ((q->r + 1) % maxx == q->l) {
//		printf("队列已满，无法入队\n");
//		return;
//	}
//	q->l = (q->l - 1 + maxx) % maxx;
//	q->data[q->l] = k;
//}
//void RInsert(Deque* q, int k) {
//	if ((q->r + 1) % maxx == q->l) {
//		printf("队列已满，无法入队\n");
//		return;
//	}
//	q->data[q->r] = k;
//	q->r = (q->r + 1) % maxx;
//}
//void LDelete(Deque* q) {
//	if (q->l == q->r) {
//		printf("队列已空，无法出队\n");
//		return;
//	}
//	printf("%d左端出队\n", q->data[q->l]);
//	q->l = (q->l + 1) % maxx;;
//}
//void RDelete(Deque* q) {
//	if (q->l == q->r) {
//		printf("队列已空，无法出队\n");
//		return;
//	}
//	q->r = (q->r - 1 + maxx) % maxx;
//	printf("%d右端出队\n", q->data[q->r]);
//}
//int main()
//{
//	Deque q = InitDeque();
//	LInsert(&q, 1);
//	LInsert(&q, 2);
//	LInsert(&q, 3);
//	RInsert(&q, 6);
//	RInsert(&q, 7);
//	RDelete(&q);
//	RDelete(&q);
//	RDelete(&q);
//	LDelete(&q);
//	LDelete(&q);
//	LDelete(&q);
//	return 0;
//}