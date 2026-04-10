//#include<stdio.h>
//#include<stdlib.h>
//typedef struct QNode{
//    int data;
//    struct QNode* next;
//}QNode,*LinkQueue;
///*
//   若想在函数里修改这两个LinkQueue的指向,需要传二级指针,十分麻烦
//   但如果代码有Queue结构体作为 “容器”,把f/r封装起来了，
//   仅需传递这个容器的地址(Queue*),就能直接修改容器里的f/r
//   故可以用&Queue直接更改,不涉及二级指针,非常方便
//*/
//typedef struct {
//    LinkQueue f;//头指针
//    LinkQueue r;//尾指针
//}Queue;
//Queue InitQueue() {
//    Queue q;
//    QNode* head = (QNode*)malloc(sizeof(QNode));
//    head->next = NULL;
//    q.f = q.r = head;
//    return q;
//}
//void EnQueue(Queue* q, int k) {
//    QNode* p = (QNode*)malloc(sizeof(QNode));
//    p->data = k;
//    p->next = NULL;
//    q->r->next = p;
//    q->r = p;//更新尾结点
//}
//void DeQueue(Queue* q) {
//    if (q->f->next==NULL) {
//        printf("队列已空，无法出队\n");
//    }
//    else {
//        printf("%d\n", q->f->next->data);//q->f表示头结点
//        if (q->f->next == q->r) {//队列中只有一个元素时
//            q->r = q->f;//更新尾指针,让q->r指向头结点,防止q->r为野指针
//        }
//        QNode* temp = q->f->next;
//        q->f->next = q->f->next->next;
//        free(temp);
//        temp = NULL;
//    }
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