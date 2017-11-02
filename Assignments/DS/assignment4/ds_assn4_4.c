#include<stdio.h>
int inorder(int arr[],int pos,int sch)
{
    static int flag=0;
   int i,j;
i = 2*pos + 1;
if(arr[i] != 0)
inorder(arr,i,sch);

//printf("\t %d",arr[pos]);
if(arr[pos]==sch)
{flag=1; return;}

j = 2*pos +2;
if(arr[j] != 0)
inorder(arr,j,sch);
}
int main()
{
    int tree[20]={0};
    int val,i,c=0;
    char ch;
    i=0;
    printf("\nenter root value");
    scanf("%d",&tree[i++]);
    c++;
    while(ch!='n')
    {
        printf("\nenter");
        scanf("%d",&tree[i++]);
        c++;
        printf("\n enter more?");
        scanf(" %c",&ch);
    }
   for(i=0;i<c;i++)
    printf("%d\t",tree[i]);
    printf("\n\n\n");
    int f=inorder(tree,0,30);
    if(f)
        printf("\n\nfound");
    else
        printf("\n\nnot found");
}
