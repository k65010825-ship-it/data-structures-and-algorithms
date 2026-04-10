//#include<stdio.h>
//#include<stdlib.h>
//typedef struct QNode {
//    int data;
//    struct QNode* next;
//}QNode, *LinkQueue;
/*

由于尾指针的地址会发生改变(地址的地址),所以我们要用带返回值的"值传递"(这里的值指的是尾指针的值,即地址的值)
理论上来说,我们也可以用二级指针来修改尾指针的地址,但这样就比较麻烦了，所以不使用

*/
//typedef struct {
//    LinkQueue f; // 头指针
//    LinkQueue r; // 尾指针
//}Queue;
//Queue InitQueue() {
//    Queue q;
//    QNode* head = (QNode*)malloc(sizeof(QNode));
//    head->next = NULL;
//    q.f = q.r = head;
//    return q;
//}
//Queue EnQueue(Queue q, int k) {
//    QNode* p = (QNode*)malloc(sizeof(QNode));
//    p->data = k;
//    p->next = NULL;
//    q.r->next = p;
//    q.r = p;
//    return q;
//}
//Queue DeQueue(Queue q) {
//    if (q.f->next == NULL) {
//        printf("队列已空，无法出队\n");
//    }
//    else {
//        printf("%d\n", q.f->next->data);
//        if (q.f->next == q.r) {
//            q.r = q.f;//若不这样做,free(temp)的时候会把q.r也free掉,q.r就变成野指针了
//        }
//        QNode* temp = q.f->next;
//        q.f->next = q.f->next->next;
//        free(temp);
//        temp = NULL;
//    }
//    return q;
//}
//
//int main()
//{
//    Queue q = InitQueue();
//    q = EnQueue(q, 1);
//    q = EnQueue(q, 2);
//    q = EnQueue(q, 3);
//    q = DeQueue(q);
//    q = DeQueue(q);
//    q = DeQueue(q);
//    q = EnQueue(q, 7);
//    q = DeQueue(q);
//    return 0;
//}