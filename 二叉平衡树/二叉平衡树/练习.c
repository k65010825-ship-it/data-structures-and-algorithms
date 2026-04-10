//#include<stdio.h>
//#include<stdlib.h>
//typedef struct AVLNode {
//	int data;
//	int h;
//	struct AVLNode* l;
//	struct AVLNode* r;
//}AVLNode,*AVLTree;
//int GetHeight(AVLNode* p) {
//	if (p == NULL)return 0;
//	return p->h;
//}
//void UpdateHeight(AVLNode* p) {
//	if (p == NULL)return;
//	int LHeight = GetHeight(p->l);
//	int RHeight = GetHeight(p->r);
//	p->h=(LHeight > RHeight) ? LHeight : RHeight + 1;
//}
//AVLNode* CreateNode(int x) {
//	AVLNode* p = (AVLNode*)malloc(sizeof(AVLNode));
//	p->data = x;
//	p->h = 1;
//	p->l = p->r = NULL;
//	return p;
//}
////右旋
//AVLTree LL(AVLTree T) {
//	AVLNode* t = T->l;
//	T->l = t->r;
//	t->r = T;
//	UpdateHeight(T);
//	UpdateHeight(t);
//	return t;
//}
////左旋
//AVLTree RR(AVLTree T) {
//	AVLNode* t = T->r;
//	T->r = t->l;
//	t->l = T;
//	UpdateHeight(T);
//	UpdateHeight(t);
//	return t;
//}
//AVLTree LR(AVLTree T) {
//	T->l = RR(T->l);
//	return LL(T);
//}
//AVLTree RL(AVLTree T) {
//	T->r = LL(T->r);
//	return RR(T);
//}
//AVLTree Insert(AVLTree T, int x) {
//	if (T == NULL) {
//		T = CreateNode(x);
//		return T;
//	}
//	else if (x < T->data) {
//		T->l = Insert(T->l, x);
//		if (GetHeight(T->l) - GetHeight(T->r) == 2) {
//			if (x < T->l->data) {
//				//LL
//				T = LL(T);
//			}
//			else {
//				//LR
//				T = LR(T);
//			}
//		}
//	}
//	else if (x > T->data) {
//		T->r = Insert(T->r, x);
//		if (GetHeight(T->r) - GetHeight(T->l) == 2) {
//			if (x < T->r->data) {
//				//RL
//				T = RL(T);
//			}
//			else {
//				//RR
//				T = RR(T);
//			}
//		}
//	}
//	UpdateHeight(T);
//	return T;
//}
//AVLTree Delete(AVLTree T,int k)
//{
//    if(T==NULL)
//    {
//        printf("该数据不存在，无法删除\n");
//        return T;
//    }
//    else if (k < T->data)
//    {
//        T->l = Delete(T->l, k);
//        if (GetHeight(T->r) - GetHeight(T->l) > 1)
//        {
//            AVLNode* right = T->r;
//            if (GetHeight(right->r) >= GetHeight(right->l))
//            {//RR
//                T = RR(T);
//            }
//            else
//            {//RL
//                T = RL(T);
//            }
//        }
//
//    }
//    else if (k > T->data)
//    {
//        T->r = Delete(T->r, k);
//        if (GetHeight(T->l) - GetHeight(T->r) > 1)
//        {
//            AVLNode* left = T->l;
//            if (GetHeight(left->l) >= GetHeight(left->r))
//            {//LL
//                T = LL(T);
//            }
//            else
//            {//LR
//                T = LR(T);
//            }
//        }
//    }
//    else
//    {
//        if(T->l!=NULL&&T->r!=NULL)
//        {//root度为2
//            //找root度前驱
//            AVLNode* p=T->l;
//            while(p->r!=NULL)p=p->r;
//            //p就是root的前驱
//            T->data=p->data;
//            T->l=Delete(T->l,p->data);
//            //在root的左子树中删除了一个结点，可能导致root左右子树高度差扩大到2，root可能失衡
//            //可能出现RR/RL失衡
//            if(GetHeight(T->r)-GetHeight(T->l)>1)
//            {
//                AVLNode* right=T->r;
//                if(GetHeight(right->r)>= GetHeight(right->l))
//                {//RR
//                    T=RR(T); 
//                }
//                else
//                {//RL
//                    T=RL(T); 
//                }
//            }
//
//        }
//        else{
//            //度为1/0
//            AVLNode* p=T;//p指向要删除的结点
//            if(T->l!=NULL)T=T->l;
//            else T=T->r;
//            free(p);
//            p=NULL;
//        }
//    }
//    
//    UpdateHeight(T);
//    return T;
//
//}
//void InOrder(AVLTree T) {
//	if (T == NULL)return;
//	InOrder(T->l);
//	//计算平衡因子
//	int p = GetHeight(T->l) - GetHeight(T->r);
//	printf("%d %d\n", T->data, p);
//	InOrder(T->r);
//}
//int main() {
//    AVLTree T = NULL;
//    // 插入测试数据
//    T = Insert(T, 10);
//    T = Insert(T, 20);
//    T = Insert(T, 30);
//    T = Insert(T, 40);
//    T = Insert(T, 50);
//
//    printf("插入后遍历：\n");
//
//    printf("InOrder: "); InOrder(T); printf("\n");
//
//    // 删除测试
//    T = Delete(T, 30);
//    printf("\n删除30后遍历：\n");
//
//    printf("InOrder: "); InOrder(T); printf("\n");
//
//    return 0;
//}
#include<stdio.h>
#include<stdlib.h>
typedef struct AVLNode {
	int data;
	int h;
	struct AVLNode* l;
	struct AVLNode* r;
}AVLNode,*AVLTree;
int GetHeight(AVLNode* p) {
	if (p == NULL)return 0;
	return p->h;
}
void UpdataHeight(AVLNode* p) {
	if (p == NULL)return;
	int LHeight = GetHeight(p->l);
	int RHeight = GetHeight(p->r);
	return ((LHeight > RHeight) ? LHeight : RHeight) + 1;
}
//右旋
AVLTree LL(AVLNode* p) {
	AVLNode* temp = p->l;
	p->l = temp->r;
	temp->r = p;
	UpdataHeight(p);
	UpdataHeight(temp);
	return temp;
}
//左旋
AVLTree RR(AVLNode* p) {
	AVLNode* temp = p->r;
	p->r = temp->l;
	temp->l = p;
	UpdataHeight(p);
	UpdataHeight(temp);
	return temp;
}
AVLTree LR(AVLNode* p) {
	p->l = RR(p->l);
	return LL(p);
}
AVLTree RL(AVLNode* p) {
	p->r = LL(p->r);
	return RR(p);
}
AVLNode* CreateNode(int x) {
	AVLNode* p = (AVLNode*)malloc(sizeof(AVLNode));
	p->data = x;
	p->h = 1;
	p->l = p->r = NULL;
	return p;
}
AVLTree Insert(AVLTree T, int x) {
	if (T == NULL) {
		T = CreateNode(x);
		return T;
	}
	else if (x < T->data) {
		T->l = Insert(T->l, x);
		if (GetHeight(T->l) - GetHeight(T->r) == 2) {
			if (x < T->l->data) {
				T = LL(T);
			}
			else {
				T = LR(T);
			}
		}
	}
	else {
		T->r = Insert(T->r, x);
		if (GetHeight(T->r) - GetHeight(T->l) == 2) {
			if (x < T->r->data) {
				T = RL(T);
			}
			else {
				T = RR(T);
			}
		}
	}
	UpdataHeight(T);
	return T;
}
AVLTree Delete(AVLTree T, int x) {
	if (T == NULL) {
		printf("空树,无法删除\n");
		return T;
	}
	else if (x < T->data) {
		T->l = Delete(T->l, x);
		if (GetHeight(T->r) - GetHeight(T->l) == 2) {
			if (T->r && GetHeight(T->r->r) >= GetHeight(T->r->l)) {
				T = RR(T);
			}
			else {
				T = RL(T);
			}
		}
	}
	else if(x>T->data){
		T->r = Delete(T->r, x);
		if (GetHeight(T->l) - GetHeight(T->r) == 2) {
			if (T->l && GetHeight(T->l->l) >= GetHeight(T->l->r)) {
				T=LL(T);
			}
			else {
				T = LR(T);
			}
		}
	}
	else {
		//x==T->data
		if (T->l != NULL && T->r != NULL) {
			//找T的前驱
			AVLNode* p = T->l;
			while (p->r != NULL) {
				p = p->r;
			}
			T->data = p->data;
			T->l = Delete(T->l, p->data);
		}
		else {
			AVLNode* temp = T;
			if (T->l != NULL)T = T->l;
			else T = T->r;
			free(temp);
			temp = NULL;
		}
	}
	UpdataHeight(T);
	return T;
}
void InOrder(AVLTree T) {
	if (T == NULL)return;
	InOrder(T->l);
	int p = GetHeight(T->l) - GetHeight(T->r);
	printf("%d %d\n", T->data, p);
	InOrder(T->r);
}
int main() {
	AVLTree T = NULL;
    // 插入测试数据
    T = Insert(T, 10);
    T = Insert(T, 20);
    T = Insert(T, 30);
    T = Insert(T, 40);
    T = Insert(T, 50);

    printf("插入后遍历：\n");

    printf("InOrder: "); InOrder(T); printf("\n");

    // 删除测试
    T = Delete(T, 30);
    printf("\n删除30后遍历：\n");

    printf("InOrder: "); InOrder(T); printf("\n");

    return 0;
}
