//#include<stdio.h>
//#include<stdlib.h>
//#define maxx 10
//typedef struct {
//	int* data;
//	int top;
//}Stack;
//Stack InitStack() {
//	Stack s;
//	s.data = (int*)malloc(sizeof(int) * maxx);
//	s.top = 0;
//	return s;
//}
//void Push(Stack* s, int k) {
//	if (s->top == maxx) {
//		printf("栈已满，无法入栈\n");
//	}
//	else {
//		s->data[s->top] = k;
//		s->top++;
//	}
//}
//void Pop(Stack* s) {
//	if (s->top == 0) {
//		printf("栈已空，无法出栈\n");
//	}
//	else {
//		s->top--;
//	}
//}
//int Get(Stack s) {
//	if (s.top == 0) {
//		printf("栈空\n");
//		return -1;
//	}
//	return s.data[s.top - 1];
//}
//int main()
//{
//	Stack s = InitStack();
//	Push(&s, 1);
//	Push(&s, 2);
//	Push(&s, 3);
//	Pop(&s);
//	Pop(&s);
//	Pop(&s);
//	printf("%d\n", Get(s));
//	return 0;
//}
