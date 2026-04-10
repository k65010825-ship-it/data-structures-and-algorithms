//#include<stdio.h>
//#include<stdlib.h>
//typedef struct SNode{
//	int data;
//	struct SNode* next;
//}SNode,*LinkStack;
//SNode* InitStack() {
//	SNode* head = (SNode*)malloc(sizeof(SNode));
//	head->next = NULL;
//	return head;
//}
//LinkStack Push(LinkStack s, int k) {
//	SNode* p = (SNode*)malloc(sizeof(SNode));
//	p->data = k;
//	p->next = s->next;
//	s->next = p;
//	return s;
//}
//LinkStack Pop(LinkStack s) {
//	if (s->next == NULL) {
//		printf("栈已空，无法出栈\n");
//	}
//	else {
//		SNode* q = s->next;
//		s->next = q->next;
//		free(q);
//		q = NULL;
//	}
//	return s;
//}
//int Get(LinkStack s) {
//	if (s->next == NULL) {
//		printf("空栈\n");
//		return -1;
//	}
//	return s->next->data;
//}
//int main()
//{
//	LinkStack s = InitStack();
//	s = Push(s, 1);
//	s = Push(s, 2);
//	s = Push(s, 3);
//	s = Pop(s);
//	s = Pop(s);
//	s = Pop(s);
//	printf("%d\n", Get(s));
//	return 0;
//}
