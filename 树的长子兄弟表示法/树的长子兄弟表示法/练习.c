#include<stdio.h>
#include<stdlib.h>
typedef struct Node {
	char data;
	struct Node* ch;
	struct Node* bro;
}Node,*LinkTree;
Node* InitTree(char root) {
	Node* p = (Node*)malloc(sizeof(Node));
	p->data = root;
	p->ch = p->bro = NULL;
	return p;
}
Node* Find(LinkTree r,char x) {
	if (r->data == x) {
		return r;
	}
	if (r->ch != NULL) {
		Node* ans = Find(r->ch, x);
		if (ans != NULL) {
			return ans;
		}
	}
	if (r->bro != NULL) {
		Node* ans = Find(r->bro, x);
		if (ans != NULL) {
			return ans;
		}
	}
	return NULL;
}
LinkTree Insert(LinkTree r, char x, char fx) {
	Node* p = (Node*)malloc(sizeof(Node));
	p->data = x;
	p->ch = p->bro = NULL;
	Node* f = Find(r, fx);
	if (f->ch == NULL) {
		f->ch = p;
	}
	else {
		Node* s = f->ch;
		while (s->bro!=NULL) {
			s = s->bro;
		}
		s->bro = p;
	}
	return r;
}
int main() {
	int n;
	scanf("%d", &n);
	char root, x, fx;
	scanf(" %c", &root);
	LinkTree r = InitTree(root);
	for (int i = 1; i < n; i++) {
		scanf(" %c %c", &x, &fx);
		r = Insert(r, x, fx);
	}
	scanf(" %c", &x);
	Node* p = Find(r, x);
	//找x的孩子
	if (p->ch == NULL) {
		printf("%c为叶子结点\n", x);
	}
	else {
		printf("%c的孩子有:");
		Node* s = p->ch;
		while (s != NULL) {
			printf("%c ", s->data);
			s = s->bro;
		}
		printf("\n");
	}
}