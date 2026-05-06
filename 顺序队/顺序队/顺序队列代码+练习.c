#include<stdio.h>
#include<stdlib.h>
#define maxx 10
typedef struct Queue {
	int* data;
	int f, r;
}Queue;
Queue InitQueue() {
	Queue q;
	q.data = (int*)malloc(sizeof(int) * maxx);
	q.f = q.r = 0;
	return q;
}
void EnQueue(Queue* q, int x) {
	if (q->r == maxx) {
		printf("队列已满，无法入队\n");
		return;
	}
	else {
		q->data[q->r] = x;
		q->r++;
	}
}
void DeQueue(Queue* q) {
	if (q->f == q->r) {
		printf("队列已空，无法出队\n");
		return;
	}
	else {
		printf("%d出队\n", q->data[q->f]);
		q->f++;
	}
}
int main() {
	Queue q = InitQueue();
	EnQueue(&q, 1);
	EnQueue(&q, 2);
	EnQueue(&q, 3);
	DeQueue(&q);
	DeQueue(&q);
	return 0;
}