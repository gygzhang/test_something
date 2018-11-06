#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define  MAX 10
#define OK 1
#define ERROR 0

typedef struct b_t {
	int data;	// save the node's data
	struct b_t * lchild;
	struct b_t * rchild;
}Tree_node, *T_node;	//	node of tree

typedef struct STACK {
	int size;
	T_node * base;
	T_node *top;
}stack;


void Creat_tree(T_node * tree) {
	int data;
	scanf_s("%d", &data);
	if (data == 0)
		tree = NULL;
	else {
		if (!((*tree) = (T_node)malloc(sizeof(Tree_node))))
			exit(0);
		(*tree)->lchild = (*tree)->rchild = NULL;
		(*tree)->data = data;
		Creat_tree(&(*tree)->lchild);
		Creat_tree(&(*tree)->rchild);
	}

}


int Show_tree_FirstOrder(T_node  tree, int(*V)(int e)) {
	if (tree) {	//node shouldn't  NULL
		if (V((*tree).data))	//Number of data 
			if (Show_tree_FirstOrder((*tree).lchild, V))	//recusion for left	child tree and the node shouldn't NULL
				if (Show_tree_FirstOrder((*tree).rchild, V))	//recusion for right
					return OK;
		return ERROR;
	}
	else return OK;


}
int PrintElement(int e) {
	printf(" %d ", e);
	return OK;
}

int MidOrder(T_node tree, int(*V)(int e)) {
	//middle of review the tree
	if (tree) {
		if (MidOrder((*tree).lchild, V))
			if (V((*tree).data))
				if (MidOrder((*tree).rchild, V))
					return OK;
		return ERROR;
	}
	else return OK;
}

int FinalOrder(T_node tree, int(*V)(int e)) {
	if (tree) {
		if (FinalOrder((*tree).lchild, V))
			if (FinalOrder((*tree).rchild, V))
				if (V((*tree).data))
					return OK;
		return ERROR;
	}
	else return OK;
}

int InitStack(stack *s) {
	s->base = (T_node *)malloc(MAX * sizeof(T_node));
	if (!s->base)
		return ERROR;
	s->top = s->base;
	s->size = MAX;
	return OK;
}

int Push(stack * s, T_node node) {
	if (s->top - s->base >= s->size)
		return ERROR;
	*(s->top)= node;
	//printf("%d\n", (*s).top);
	s->top++;
	printf("%d", (*node).data);
	return OK;
}

int Norecu_FOrder(T_node tree, int(*V)(int e)) {
	stack s;
	printf("%d\n", InitStack(&s));
	Push(&s, tree);
	return 0;
}


int main(void) {
	T_node tree;
	Creat_tree(&tree);
	Show_tree_FirstOrder(tree, PrintElement);	//the first way to view
	printf("\n");
	MidOrder(tree, PrintElement);	//middle of review the tree
	printf("\n");
	FinalOrder(tree, PrintElement);	//final visit root node way
	printf("\n");

	Norecu_FOrder(tree, PrintElement);

	return OK;
}

