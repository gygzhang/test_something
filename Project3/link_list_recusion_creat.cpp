#include<stdio.h>
#include<stdlib.h>

typedef struct node {
	int data;
	struct node *next;
}node,*list;

void creat(node *np,int a) {
	if (a == 0) return;
	//Ҫ��:ǧ��Ҫд��np,��Ϊnp�Ѿ�����������˶��ڴ�,
	//����ڴ˴�Ϊnp������ڴ�,��ô֮��Ĳ������Ƕ���һ���ڴ�Ĳ���,
	//�����Ƕ������������np�Ĳ���,�м����м�
	np->next = (node*)malloc(sizeof node);
	(np)->data = a--;
	creat((np)->next,a);
}

int main() {
	list np = (node*)malloc(sizeof node);
	creat(np,5);
	puts("a");
}