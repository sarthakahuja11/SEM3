#include<stdio.h>

#define max 5

push(int stack[],int *top,int element)
{
	if(*top==max-1)
		printf("Stack Overflow");
	else
		stack[++(*top)]=element;
}

int stackPop(int stack[],int *top)
{
	if(*top==-1)
		printf("Stack Underflow");
	else
		return stack[(*top)--];
}


int queueDelete(int stackQ[max],int temp[max],int * topQ,int *topT)
{
	while(*topQ!=-1)
	{
		push(temp,topT,stackPop(stackQ,topQ));
	}
	if(*topT!=-1)
	printf("Element deleted is %d\n",stackPop(temp,topT));
	while(*topT!=-1)
	{
		push(stackQ,topQ,stackPop(temp,topT));
	}
}

display(int stack[],int top)
{
	int i;
	for(i=0;i<=top;i++)
		printf("%d ",stack[i]);
}

main()
{
	int stackQ[max];
	int temp[max];
	int topQ=-1,topT=-1;
	int i=0,element;
	while(i!=4)
	{
		printf("1. Push\n2. Delete\n3. Display\n4. Exit\n");
		scanf("%d",&i);
		switch(i)
		{
			case 1: printf("Enter element\n");
					scanf("%d",&element);
					push(stackQ,&topQ,element);
					break;
			case 2: queueDelete(stackQ,temp,&topQ,&topT);
					break;
			case 3: display(stackQ,topQ);
					break;
			case 4:;
		}
	}
}
