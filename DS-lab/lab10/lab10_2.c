#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int data;
    struct node * rl;
    struct node * ll;
}NODDE;
typedef NODDE *NODE; 
NODE create(NODE root,int val)
{
    NODE p;
    if(root==NULL)
    {
        root=(NODE)malloc(sizeof(NODE));
        root->data=val;
        root->ll=root->rl=NULL;
    }
    else if(val>root->data)
        root->rl=create(root->rl,val);
    else if(val<root->data)
        root->ll=create(root->ll,val);
    return root;
}
int inorder(NODE root,int sch)
{
    static int flag=0;
    if(root==NULL)
    return flag;
    if(root!=NULL)
    {
        inorder(root->ll,sch);
        if(root->data==sch)
           { flag=1;
            return flag;
           }
        else flag=0;
        inorder(root->rl,sch);
    }
}
int iter_inorder(NODE root,int sch)
{
    NODE cur=root;
    int flag=0;

    while(cur!=NULL)
    {
        if(cur->data==sch)
        {
            flag=1;
            return flag;
        }
        else if(cur->data>sch)
        {
            cur=cur->ll;
        }
        else
            cur=cur->rl;
    }

}
int main()
{
    NODE root=NULL;
    int i,val,sch;
    for(i=0;i<5;i++)
    {
    scanf("%d",&val);
    root=create(root,val);
    }
    scanf("%d",&sch);
    //int res=inorder(root,sch);
    int res=iter_inorder(root,sch);
    if(res==1)
        printf("found");
    else
        printf("not found");
}
