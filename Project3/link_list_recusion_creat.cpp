#include<stdio.h>
#include<stdlib.h>

typedef struct node {
	int data;
	struct node *next;
}node,*list;

void creat(node *np,int a) {
	if (a == 0) return;
	//要点:千万不要写成np,因为np已经在外面分配了堆内存,
	//如果在此处为np分配堆内存,那么之后的操作都是对另一块内存的操作,
	//而不是对主函数里面的np的操作,切记诶切记
	np->next = (node*)malloc(sizeof node);
	(np)->data = a--;
	creat((np)->next,a);
}

int main() {
	list np = (node*)malloc(sizeof node);
	creat(np,5);
	puts("a");
}