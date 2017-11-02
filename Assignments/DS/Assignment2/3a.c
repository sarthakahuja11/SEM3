#include<stdio.h>
#define MAX 1000

int top[2]={-1,MAX};
int a[MAX];
int flag=0;

int push(int s,int element)
{
    if(s==1)
    {   if(top[0]+1==top[1] || top[0]==MAX)
            flag=1;
        else
            flag=0;
        if(flag)
            {
                printf("Stack Overflow\n");
                s=0;
                return s;
            }

        a[++top[0]]=element;
    }
    if(s==2)
    {   if(top[1]-1==top[0] || top[1]==-1)
            flag=1;
        else
            flag=0;
        if(flag)
            {
                printf("Stack Overflow\n");
                s=0;
                return s;
            }

        a[--top[1]]=element;//Associativity issue, left right

    }
    return s;
}

void pop(s)
{
    if(s==1)
    {
        if(top[0]==-1)
            printf("Stack Underflow\n");
        else
            --top[0];//Associativity issue

    }
    if(s==2)
    {
         if(top[1]==MAX)
            printf("Stack Underflow\n");
            else
                --top[1];//Bug ( should be ++)
    }
}

void display()
{
    int i;
    for(i=0;i<MAX;i++)
        printf("%d ",a[i]);
}
void main()
{
    int s,v,i=0;
while(i!=4)
{
    printf("\n1.Push(s,element)\n2.Pop (s)\n3.Display\n4.Exit\n");
    scanf("%d",&i);
    switch(i)
    {
        case 1: printf("Enter values (s,element)\n");
                scanf("%d",&s);
                scanf("%d",&v);
                s=push(s,v);
                if(s==0)
                    printf("s is set to zero");
                break;
        case 2: printf("Enter values (s)\n");
                scanf("%d",&s);
                pop(s);
                break;
        case 3: display();
                break;
        case 4:;
    }
}



}
