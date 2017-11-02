#include<stdio.h>
typedef struct node
{
    int data;
    struct node * next;
}*NODE;
NODE insertF(NODE first,int val)
{
    NODE temp=(struct node *) malloc(sizeof(struct node));

    temp->data=val;
    temp->next=NULL;

    if(first==NULL)
       {
        return temp;
       }
    else
    {
        temp->next=first;
        return temp;
    }
}
NODE insertR(NODE first,int val)
{
    NODE temp=(struct node *) malloc(sizeof(struct node));

    temp->data=val;
    temp->next=NULL;

    if(first==NULL)
    {
        return temp;
    }
    else
    {
        NODE cur=first;
        while(cur->next!=NULL)
            cur=cur->next;
        cur->next=temp;
        return first;
    }
}

void display(NODE first)
{
    if(first==NULL)
        printf("\n\nempty");
    else
    {
        NODE cur=first;
        while(cur!=NULL)
        {
            printf("%d",cur->data);
            cur=cur->next;
        }
        //printf("%d\t",cur->data);
    }
}
static void reverse(NODE * head_ref)
{
    NODE prev   = NULL;
   NODE current = *head_ref;
    NODE next;
    while (current != NULL)
    {
        next  = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head_ref = prev;
}
NODE add(NODE a,NODE b)
{

    NODE temp,c=NULL;
    int s=0,car=0,rem=0;
    if(a==NULL)
        return b;
    if(b==NULL)
        return a;
    else
    {
        while(a&&b)
        {

             s=a->data+b->data+car;
             car=s/10;
             rem=s%10;
             c=insertF(c,rem);
             a=a->next;
             b=b->next;
        }
        while(a)
        {
            s=a->data+car;
            car=s/10;
            rem=s%10;
            c=insertF(c,rem);
            a=a->next;
        }
        while(b)
        {
            s=b->data+car;
            car=s/10;
            rem=s%10;
            c=insertF(c,rem);
            b=b->next;

        }
        if(car>0)
        {
            c=insertF(c,car);
        }
        return c;
    }

}
NODE multiply(NODE m,int n)
{
    NODE prod=NULL;
    int i;
    for(i=0;i<2;i++)
    {
    prod=add(prod,m);
    }
    for(i=0;i<n-2;i++)
    {
        reverse(&prod);
        prod=add(prod,m);
    }

    return prod;
}
int main()
{
    char arr[50],arr1[50];
    NODE a,b,c,d;
    a=NULL;
    b=NULL;
    d=NULL;
    int i=0;
    scanf("%s",arr);
    i=0;
    while(arr[i]!='\0')
    {

        d=insertR(d,arr[i]-'0');
        i++;
    }
    strrev(arr);
    i=0;
    while(arr[i]!='\0')
    {

        a=insertR(a,arr[i]-'0');
        i++;
    }
    i=0;
    scanf("%s",arr1);
    strrev(arr1);
    while(arr1[i]!='\0')
    {

        b=insertR(b,arr1[i]-'0');
        i++;
    }
    c=add(a,b);
    display(c);
    int m;
    printf("\n");
    scanf("%d",&m);
    NODE prod=multiply(a,m);
    display(prod);
}

