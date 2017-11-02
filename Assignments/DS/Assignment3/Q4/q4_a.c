#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node{
	char data[40];
	struct node * link;
} * Node;

Node insert(Node head, char s[40])
{
	Node temp = malloc(sizeof(struct node));
	temp->link=NULL;
	strcpy(temp->data,s);
	if(!head)
		return temp;
	Node cur=head;
	while(cur->link)
		cur=cur->link;
	cur->link=temp;
	return head;
}

void display(Node head)
{
	Node cur=head;
	if(!head)
	{
		printf("Empty Link List\n");
		return;
	}
	while(cur)
		{
			printf("%s\n",cur->data);
			cur=cur->link;}
}

void main(){
	char data[20][40];
	int link [20];
	int i,n,first;
	printf("Enter n\n");
	scanf("%d",&n);
	printf("Enter data and link\n");
	for (i = 1; i < n+1; ++i)
	{
		scanf("%s",data[i]);
		scanf("%d",&link[i]);
	}

	for (i = 1; i < n+1; ++i)
	{	if(link[i]==-1)
		{
			printf("%d\n",i);
			continue;}
		printf("%d\t%s\t%d\n",i,data[i],link[i]);
		
	}

	printf("Enter first\n");
	scanf("%d",&first);

	Node head=NULL;
	i=first;
	while(link[i]!=0 && i!=-1)
	{
		head=insert(head,data[i]);
		i=link[i];
	}

	display(head);
}

//	HAT 11 NULL -1 CAT 4 EAT 9 NULL -1 NULL -1 WAT 0 BAT 3 FAT 1 NULL -1 VAT 7
