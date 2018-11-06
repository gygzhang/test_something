#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define  MAX 10

typedef struct b_t {
	int data;	// save the node's data
	struct b_t * lchild;
	struct b_t * rchild;
}Tree_node, *T_node;	//	node of tree


void Creat_tree(Tree_node* tree) {
	printf("%p\n", tree);
	int data;
	scanf_s("%d", &data);
	if (data == 0)
		tree = NULL;
	else {
		if (!(tree = (T_node)malloc(sizeof(Tree_node))))
			exit(0);
		//>data = 15;
		//(tree)->lchild = (tree)->rchild = NULL;
		//printf("%p\n", tree);
		//tree->lchild = (Tree_node*)malloc(sizeof Tree_node);
		//tree->rchild = (Tree_node*)malloc(sizeof Tree_node);
		
		(*tree).data = data;
		//printf("(tree): %d\n", tree->data);
		Creat_tree((tree)->lchild);
		Creat_tree((tree)->rchild);
		puts("aa");

	}
}

void Show_tree(Tree_node *tree) {
	//printf("%d->", (*tree).data);
	if(tree)printf("%d->", tree->data);
		while(tree){			
			Show_tree(tree->lchild);
			Show_tree(tree->rchild);
		}
}


int main(void) {
	Tree_node* tree = (Tree_node*)malloc(sizeof Tree_node);
	
	//printf("%p\n", tree);	
	//tree = NULL;
	//printf("%p\n", tree);
	Creat_tree(tree);
	//printf("%d\n", tree->lchild);
	puts("ss");
	//Show_tree(tree);

	return 0;
}
