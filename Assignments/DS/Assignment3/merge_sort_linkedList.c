#include<stdio.h>
typedef struct node
{
    int data;
    struct node * next;
}*NODE;


NODE insertR(NODE first,int val)
{
    NODE temp=(struct node *) malloc(sizeof(struct node));

    temp->data=val;
    temp->next=NULL;

    if(first->next==NULL)
    {
        first->next=temp;
        temp->next=first;
        return first;
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

void display(NODE first)
{
    if(first==NULL)
        printf("\n\nempty");
    else
    {
        NODE cur=first->next;
        while(cur!=first)
        {
            printf("%d\t",cur->data);
            cur=cur->next;
        }
    }
}
NODE * merge(NODE first,NODE second)
{
    NODE ta,tb,sorted;
    ta=first->next;
    tb=second->next;
     sorted=(struct node *)malloc(sizeof(struct node));
    sorted->data=0;
    sorted->next=NULL;

    do
    {
        char a=ta->data;
        char b=tb->data;
        if(a>b)
        {
            sorted=insertR(sorted,b);
            tb=tb->next;
            (sorted->data)++;
        }
        else if(a<b)
        {
            sorted=insertR(sorted,a);
            ta=ta->next;
            (sorted->data)++;
        }
        else if(a==b)
        {
            sorted=insertR(sorted,a);
            ta=ta->next;
            tb=tb->next;
            (sorted->data)++;
        }
    }while(ta!=first && tb!=second);

    if(ta!=first)
    {
        while(ta!=first)
        {   char a=ta->data;
            sorted=insertR(sorted,a);
            ta=ta->next;
            (sorted->data)++;
        }
    }
    if(tb!=second)
    {
        while(tb!=second)
        {   char b=tb->data;
            sorted=insertR(sorted,b);
            tb=tb->next;
            (sorted->data)++;
        }
    }
    return sorted;

}

int main()
{
    NODE first;
    NODE second;
    NODE sorted;
    int ch,c1=0,c2=0;
    int val,val1;
    first=(struct node *)malloc(sizeof(struct node));
    first->data=0;
    first->next=NULL;
    second=(struct node *)malloc(sizeof(struct node));
    second->data=0;
    second->next=NULL;
     NODE ta;
     NODE tb;
    while(val!=-1)
    {
        scanf(" %d",&val);
        if(val!=-1)
        {first=insertR(first,val);first->data++;c1++;}

    }

    while(val1!=-1)
    {
        scanf(" %d",&val1);
        if(val1!=-1)
        {second=insertR(second,val1);second->data++;c2++;}
    }
    printf("%d %d\n",c1,c2);
    sorted=merge(first,second);

     display(sorted);

    NODE f,s,t;
    t=sorted->next;
    f=(struct node *)malloc(sizeof(struct node));
    f->data=0;
    f->next=NULL;
    s=(struct node *)malloc(sizeof(struct node));
    s->data=0;
    s->next=NULL;
    int i;

    for(i=0;i<c1;i++)
    {
        f=insertR(f,t->data);
        f->data++;
        t=t->next;
    }
    for(i=0;i<c2;i++)
    {
        s=insertR(s,t->data);
        s->data++;
        t=t->next;
    }
    if(t->next==NULL)
        printf("\n\nfdfgs");

    printf("\n\n");
    display(f);
    printf("\n\n");
   display(s);

}
