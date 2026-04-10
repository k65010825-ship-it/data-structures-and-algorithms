#include<stdio.h>
#include<stdlib.h>
#define maxx 10
typedef struct {
	int* data;
	int f, r;
}Queue;
Queue InitQueue() {
    Queue q;
    q.data = (int*)malloc(sizeof(int) * maxx);
    q.f = q.r = 0;
    return q;
}
void EnQueue(Queue* q, int k) {
    if (q->f == (q->r + 1) % maxx) {
        printf("队列已满，无法入队\n");
    }
    else {
        q->data[q->r] = k;
        q->r = (q->r + 1) % maxx;
    }
}
void DeQueue(Queue* q) {
    if (q->f == q->r) {
        printf("队列已空，无法出队\n");
    }
    else {
        printf("%d\n", q->data[q->f]);
        q->f = (q->f+1) % maxx;
    }
}
int main()
{
    Queue q=InitQueue();
    EnQueue(&q,1);
    EnQueue(&q,2);
    EnQueue(&q,3);
    DeQueue(&q);
    DeQueue(&q); 
    return 0;
}

