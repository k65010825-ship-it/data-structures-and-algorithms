//#include<stdio.h>
//#include<stdlib.h>
//typedef struct QNode {
//    int data;
//    struct QNode* next;
//}QNode,*LinkQueue;
//typedef struct {
//    LinkQueue f;
//    LinkQueue r;
//}Queue;
//Queue InitQueue() {
//    QNode* head = (QNode*)malloc(sizeof(QNode));
//    Queue q;
//    q.f = q.r = head;
//    head->next = NULL;
//    return q;
//}
//void EnQueue(Queue* q, int k) {
//    QNode* p = (QNode*)malloc(sizeof(QNode));
//    p->data = k;
//    p->next = NULL;
//    q->r->next = p;
//    q->r = p;
//}
//void DeQueue(Queue* q) {
//    if (q->f->next==NULL) {
//        printf("队列已空，无法出队\n");
//        return;
//    }
//    QNode* p = q->f->next;
//    printf("%d出队\n", p->data);
//    if (q->f->next == q->r) {
//        q->r = q->f;
//    }
//    q->f->next = p->next;
//    free(p);
//    p = NULL;
//}
//int main()
//{
//    Queue q = InitQueue();
//    EnQueue(&q, 1);
//    EnQueue(&q, 2);
//    EnQueue(&q, 3);
//    DeQueue(&q);
//    DeQueue(&q);
//    DeQueue(&q);
//    EnQueue(&q, 7);
//    DeQueue(&q);
//    return 0;
//}