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
void push(NODE s[],int * top,NODE val)
{
    s[++(*top)]=val;
}
NODE pop(NODE s[],int *top)
{
    return(s[(*top)--]);
}
void iter_inorder(NODE root)
{
    NODE stack[20],cur=root;
    int top=-1;
    if(root==NULL)
        printf("\nempty");
    while(1)
    {
        while(cur)
        {
            push(stack,&top,cur);
            cur=cur->ll;
        }
        if(top>=0)
        {
            cur=pop(stack,&top);
            printf("%d\t",cur->data);
            cur=cur->rl;
        }
        else if(top==-1)
            break;
    }
}
void iter_preorder(NODE root)
{
    NODE stack[20],cur=root;
    int top=-1;
    if(root==NULL)
        printf("\nempty");
    while(1)
    {
        while(cur)
        {
            printf("%d\t",cur->data);
            push(stack,&top,cur);
            cur=cur->ll;
        }
        if(top>=0)
        {
            cur=pop(stack,&top);
            cur=cur->rl;
        }
        else if(top==-1)
            break;
    }
}

// An iterative function to do postorder traversal of a given binary tree
void iter_postorder(NODE root)
{
    // Check for empty tree
    if (root == NULL)
        return;

   NODE stack[20],cur=root;
   int top=-1;
    do
    {
        // Move to leftmost node
        while (cur)
        {
            // Push root's right child and then root to stack.
            if (cur->rl)
                push(stack,&top,cur->rl);
            push(stack, &top,cur);

            // Set root as root's left child
            cur = cur->ll;
        }

        // Pop an item from stack and set it as root
        cur = pop(stack,&top);

        // If the popped item has a right child and the right child is not
        // processed yet, then make sure right child is processed before root
        if (cur->rl && stack[top] == cur->rl)
        {
            pop(stack,&top);  // remove right child from stack
            push(stack, &top,cur);  // push root back to stack
            cur = cur->rl; // change root so that the right
                                // child is processed next
        }
        else  // Else print root's data and set root as NULL
        {
            printf("%d\t", cur->data);
            cur = NULL;
        }
    } while (top!=-1);
}
int main()
{
    NODE root=NULL;
    root=create(root);
    printf("\ninorder\n");
    iter_inorder(root);
    printf("\npreorder\n");
    iter_preorder(root);
     printf("\npostorder\n");
    iter_postorder(root);
}
