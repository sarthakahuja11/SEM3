//lab7-q1
//I have pointed rear and front both to middile of array this way we can add left or right easily
#include <stdio.h>

# define MAX 100

typedef struct
{
	int a[MAX];
	int front;
	int rear;
} Q;

Q q;


void addright(int x)
{
	if (q.rear == MAX)
		printf("Full from right\n");
	else
	{
		q.a[++q.rear] = x;
		if (q.front ==-1+MAX/2)
			q.front =0+MAX/2;
	}
}
void addleft(int x)
{
	if (q.rear ==-1+MAX/2 && q.front ==-1+MAX/2)
		{q.a[--q.front] = x;
			q.rear--;}
		
	else if (q.front ==0)
		printf("Full from left\n");
	else
		q.a[--q.front] = x;
}
void deleteleft ()
{
	int x;
	if (q.rear ==-1+MAX/2 && q.front ==-1+MAX/2)
	{
		printf("\nEmpty dequeue\n");
	}
	else if (q.front == q.rear)
	{
		x = q.a[q.front];
		q.front = q.rear =-1+MAX/2;
		printf("Deleted element is %d\n", x);
	}
	else
		printf("Deleted element is %d\n",  q.a[q.front++]);
}

void deleteright()
{
	int x;
	if (q.rear ==-1+MAX/2 && q.front ==-1+MAX/2)
	{
		printf("Empty!");
	}
	else if (q.front == q.rear)
	{
		x = q.a[q.front];
		q.front = q.rear =-1+MAX/2;
		printf("Deleted element is %d\n", x);
	}
	else
	{
		printf("Deleted element is %d\n", q.a[q.rear--]);
	}
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
			printf("%d ", q.a[i]);
			printf("\n\n");
	}
}

int main()
{
	q.front =-1+MAX/2;
	q.rear =-1+MAX/2;
	int ch=0, x;
	while (ch!=6)
        {
                printf("1.add Left\n2.add Right\n3.Delete Left\n4.Delete Right\n5.Display\n6.exit\n");
                scanf("%d", &ch);
                switch (ch)
                {
                         case 1:
                               printf("Enter element : ");
                               scanf("%d", &x);
                              addleft(x);
                              display();
                               break;
                         case 2:
                               printf("Enter element : ");
							   scanf("%d", &x);
							   addright(x);
							   display();
                               break;
                         case 3:
                               deleteleft();
                               display();
                               break;
                         case 4:
                               deleteright();
                               printf("Deleted element is %d\n", x);
                               display();
                               break;                              
                         case 5:
                               display();
                               break;
                        
                 }
	 }
	return 0;
}
