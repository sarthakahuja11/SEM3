//lab7-q1
//I have pointed rear and front both to middile of array this way we can add left or right easily
#include <stdio.h>
#include<string.h>
# define MAX 100

typedef struct
{
	char a[MAX][20];
	int front;
	int rear;
} Q;

Q q;


void addright(char x[])
{
	if (q.rear == MAX)
		printf("Full from right\n");
	else
	{
		strcpy(q.a[++q.rear],x);
		if (q.front ==-1+MAX/2)
			q.front =0+MAX/2;
	}
}

void addleft(char x[])
{
	if (q.rear ==-1+MAX/2 && q.front ==-1+MAX/2)
		{strcpy(q.a[--q.front],x);
			q.rear--;}
		
	else if (q.front ==0)
		printf("Full from left\n");
	else
		strcpy(q.a[--q.front],x);
}

void deleteleft ()
{
	char x[20];
	if (q.rear ==-1+MAX/2 && q.front ==-1+MAX/2)
	{
		printf("\nEmpty dequeue\n");
	}
	else if (q.front == q.rear)
	{
		strcpy(x,q.a[q.front]);
		q.front = q.rear =-1+MAX/2;
		printf("Deleted element is %s\n", x);
	}
	else
		printf("Deleted element is %s\n",  q.a[q.front++]);
}

void display()
{
	int i;
	if (q.front ==-1+MAX/2 && q.rear ==-1+MAX/2)
		printf("\nEmpty dequeue\n");
	else
	{
		printf("\nDequeue is\n");
		for (i=q.front; i<=q.rear; i++)
			printf("%s ", q.a[i]);
			printf("\n\n");
	}
}

int main()
{
	q.front =-1+MAX/2;
	q.rear =-1+MAX/2;
	int ch=0;
	char x[20];
	while (ch!=5)
        {
                printf("1.add Left\n2.add Right\n3.Delete Left\n4.Display\n5.exit\n");
                scanf("%d", &ch);
                switch (ch)
                {
                         case 1:
                               printf("Enter element : ");
                               scanf("%s", x);
                              addleft(x);
                              display();
                               break;
                         case 2:
                               printf("Enter element : ");
							   scanf("%s", x);
							   addright(x);
							   display();
                               break;
                         case 3:
                               deleteleft();
                               display();
                               break;
                         /*case 4:
                               deleteright();
                               display();
                               break;  */                            
                         case 4:
                               display();
                               break;
                        
                 }
	 }
	return 0;
}
















/*void deleteright()
{
	char x[20];
	if (q.rear ==-1+MAX/2 && q.front ==-1+MAX/2)
	{
		printf("Empty!");
	}
	else if (q.front == q.rear)
	{
		strcpy(x,q.a[q.front]);
		q.front = q.rear =-1+MAX/2;
		printf("Deleted element is %s\n", x);
	}
	else
	{
		printf("Deleted element is %s\n", q.a[q.rear--]);
	}
}*/
