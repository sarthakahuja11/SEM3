#include <stdio.h>
#include <stdlib.h>
#define MAX 10
typedef struct{
	int data[MAX];
	int f,r;
}DeQueue;

typedef enum{False,True}Bool;

Bool isEmpty(DeQueue dq)
{
	if(dq.f==dq.r)
	{
		//printf("Empty");
		return True;
	}
	return False;
}


int deleteLeft(DeQueue* dq)
{
	if(isEmpty(*dq)==False)
	{
		return dq->data[dq->f++];
	}
	dq->f=dq->r=-1;
	return 0;
}
int deleteRight(DeQueue* dq)
{
	if(isEmpty(*dq)==False)
	{
		return dq->data[dq->r--];
	}
	dq->f=dq->r=-1;
	return 0;
}
void addLeft(DeQueue* dq,int item)
{
	if(dq->f==dq->r && dq->f==-1)
	{
		dq->data[++dq->r]=item;
	}
	else
	{
		if(dq->f>=0)
		{
			dq->data[dq->f--]=item;
		}
		else
		{
			printf("cannot add to left");
		}
	}
}
void addRight(DeQueue* dq,int item)
{
	if(dq->r==MAX)
	{
		printf("Cannot Add to right");
	}
	else
	{
		dq->data[++dq->r]=item;
	}
}
void disp(DeQueue dq)
{
	if(isEmpty(dq)==False)
	{
		int i=0;
		for(i=dq.f+1;i<=dq.r;i++)
		{
			printf("%d ",dq.data[i]);
		}
	}
	else
		printf("Empty\n");

}

int main()
{
	DeQueue dq;
	dq.f=dq.r=-1;
	int ans=1;
	int item;
	do
	{
		printf("\n1.delLeft \n2.addLeft \n3.delRight \n4.addRight \n5.disp \n6.Exit \nEnter Ans= ");
		int ch;
		scanf("%d",&ch);

		switch(ch)
		{
		case 1:
			printf("%d ",deleteLeft(&dq));
			break;
		case 2:
			printf("Enter value: ");
			scanf("%d",&item);
			addLeft(&dq,item);
			break;
		case 3:
			printf("%d ",deleteRight(&dq));
			break;
		case 4:
			printf("Enter value: ");
			scanf("%d",&item);
			addRight(&dq,item);
			break;
		case 5:
			disp(dq);
			break;
		case 6:
			ans=0;
			break;

		}
	}while(ans==1);
	return 0;
}

