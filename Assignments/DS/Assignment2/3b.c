#include<stdio.h>
#include<stdlib.h>

int max=10;

push(int * stack,int *top,int element)
{
	if(*top==max-1)
	{
		max+=10;
		stack=realloc(stack,max*sizeof(int));
		printf("\nSize increased by 10\n");
	}
		stack[++(*top)]=element;
}

int pop(int * stack,int *top)
{
	if(*top==-1)
		printf("Underflow\n");
	else
		return stack[(*top)--];
}

display(int *stack,int top)
{
	int i=0;
	for(;i<= top;i++)
		printf("%d ",stack[i]);
}
main()
{
	int * stack=calloc(10,sizeof(int));
	int top=-1,element;
	int i=0;
	while(i!=4)
	{
		printf("\n1. Push\n2. Delete\n3. Display\n4. Exit\n");
		scanf("%d",&i);
		switch(i)
		{
			case 1: printf("Enter element\n");
					scanf("%d",&element);
					push(stack,&top,element);
					break;
			case 2: pop(stack,&top);
					break;
			case 3: display(stack,top);
					break;
			case 4:;
		}
	}
}