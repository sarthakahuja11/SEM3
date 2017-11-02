#include<stdio.h>
typedef struct node
{
    int data;
    struct node * rl;
    struct node * ll;
}*NODE;
NODE create()
{
    NODE p;
    int x;
    scanf("%d",&x);
    if(x==-1)
        return NULL;
    p=(struct node *)malloc(sizeof(struct node));
    p->data=x;
    printf("\nenter left children");
    p->ll=create();
    printf("\nenter right child nodes");
    p->rl=create();
    return p;
}
void inorder(NODE root)
{
    if(root==NULL)
    {return;}
    if(root!=NULL)
    {
        inorder(root->ll);
        printf("%d\t",root->data);
        inorder(root->rl);
    }
}
void preorder(NODE root)
{
    if(root==NULL)
    {return;}
    if(root!=NULL)
    {
         printf("%d\t",root->data);
        inorder(root->ll);
        inorder(root->rl);
    }
}
void postorder(NODE root)
{
    if(root==NULL)
    {return;}
    if(root!=NULL)
    {
        inorder(root->ll);
        inorder(root->rl);
        printf("%d\t",root->data);
    }
}
int main()
{
    NODE root=NULL;
    root=create(root);
    printf("\nin order\n");
    inorder(root);
    printf("\npre order\n");
    preorder(root);
    printf("\npost order\n");
    postorder(root);
    return 0;
}
