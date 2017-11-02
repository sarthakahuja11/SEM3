#include<stdio.h>
typedef struct node
{
    int petrol;
    int dist;
    struct node * next;
}*NODE;

NODE insertR(NODE first,int val1,int val2)
{
    NODE temp=(struct node *) malloc(sizeof(struct node));

    temp->petrol=val1;
    temp->dist=val2;
    temp->next=NULL;

    if(first==NULL)
    {
        temp->next=temp;
        return temp;
    }
    else
    {
        NODE cur=first;
        while(cur->next!=first)
            cur=cur->next;
        cur->next=temp;
        temp->next=first;
        return first;
    }
}
int travel(NODE list)
{
    int start=0,flag=0;
    NODE cur=list;
    NODE cur2=cur;
    int cur_petrol=0;

    do
    {
        do
        {
            cur_petrol+=cur2->petrol-cur2->dist;
            if(cur_petrol<0)
                {flag=0;break;}
            else
                {cur2=cur2->next;flag=1;}
        }while(cur2!=cur);
        if(flag==1)
            break;
        else
        {
            cur=cur->next;
            cur_petrol=0;
            flag=0;
            start++;
            cur2=cur;
        }
    }while(cur->next!=list);
    return start;
}

void display(NODE first)
{
    if(first==NULL)
        printf("\n\nempty");
    else
    {
        NODE cur=first;
        while(cur->next!=first)
        {
            printf("%d %d\t",cur->petrol,cur->dist);
            cur=cur->next;
        }
        printf("%d %d\t",cur->petrol,cur->dist);
    }
}
int main()
{
    NODE a=NULL;
    //a=insertR(a,0,0);
    a=insertR(a,4,6);
    a=insertR(a,6,5);
    a=insertR(a,7,3);
    a=insertR(a,4,6);
    a=insertR(a,4,5);
    int pos=travel(a);
    printf("\n%d",pos);
}
