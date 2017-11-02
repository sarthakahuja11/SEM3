/* Used the addition program at http://www.geeksforgeeks.org/add-two-numbers-represented-by-linked-lists/

which works. Modified it to include multiplication.

Please test the multiplication function for more test cases. Normal style multiplication. Read the numbers from right to left. */




#include<stdio.h>
#include<stdlib.h>

/* Linked list node */
struct node
{
    int data;
    struct node* next;
};

/* Function to create a new node with given data */
struct node *newNode(int data)
{
    struct node *new_node = (struct node *) malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

/* Function to insert a node at the beginning of the Doubly Linked List */
void push(struct node** head_ref, int new_data)
{
    /* allocate node */
    struct node* new_node = newNode(new_data);

    /* link the old list off the new node */
    new_node->next = (*head_ref);

    /* move the head to point to the new node */
    (*head_ref)    = new_node;
}

/* Adds contents of two linked lists and return the head node of resultant list */
struct node* addTwoLists (struct node* first, struct node* second)
{
    struct node* res = NULL; // res is head node of the resultant list
    struct node *temp, *prev = NULL;
    int carry = 0, sum;

    while (first != NULL || second != NULL) //while both lists exist
    {
        // Calculate value of next digit in resultant list.
        // The next digit is sum of following things
        // (i)  Carry
        // (ii) Next digit of first list (if there is a next digit)
        // (ii) Next digit of second list (if there is a next digit)
        sum = carry + (first? first->data: 0) + (second? second->data: 0);

        // update carry for next calulation
        carry = (sum >= 10)? 1 : 0;

        // update sum if it is greater than 10
        sum = sum % 10;

        // Create a new node with sum as data
        temp = newNode(sum);

        // if this is the first node then set it as head of the resultant list
        if(res == NULL)
            res = temp;
        else // If this is not the first node then connect it to the rest.
            prev->next = temp;

        // Set prev for next insertion
        prev  = temp;

        // Move first and second pointers to next nodes
        if (first) first = first->next;
        if (second) second = second->next;
    }

    if (carry > 0)
      temp->next = newNode(carry);

    // return head of the resultant list
    return res;
}


struct node* multiplyll(struct node*a,struct node*b)
{
struct node*pb=b;
struct node*pa=a;
int product,carry;
struct node*res=NULL;
struct node*temp=NULL;
struct node*pro=NULL;
struct node*prev=NULL;
int i=0;

while(pb)
{
prev=NULL;
res=NULL;
temp=NULL;
pa=a;
carry=0;
product=0;
for(int j=0;j<i;j++)
{
temp=newNode(0);
if(res==NULL)
res=temp;
else
prev->next=temp;
prev=temp;
}
//printf("Zeroes");
//printList(res);
while(pa)
{

product=carry+((pa?pa->data:0)*(pb?pb->data:0));
carry=product/10;
product=product%10;
temp=newNode(product);

if(res==NULL)
res=temp;
else
prev->next=temp;

prev=temp;
if(pa)
pa=pa->next;
}

if(carry>0)
temp->next=newNode(carry);
//printf("Res before \n");
//printList(res);
pro=addTwoLists(pro,res);
//printList(pro);

pb=pb->next;
i++;



}
return pro;
}


// A utility function to print a linked list
void printList(struct node *node)
{
    while(node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

/* Driver program to test above function */
int main(void)
{
    struct node* res = NULL;
    struct node* first = NULL;
    struct node* second = NULL;

    // create first list 7->5->9->4->6
    push(&first, 6);
    push(&first, 4);
    push(&first, 9);
    push(&first, 5);
    push(&first, 7);
    printf("First List is ");
    printList(first);

    // create second list 8->4
    push(&second, 4);
    push(&second, 8);
    printf("Second List is ");
    printList(second);

    // Add the two lists and see result
    res = addTwoLists(first, second);
    printf("Resultant list is ");
    printList(res);

    res=multiplyll(first,second);
    printf("\n");
    printList(res);
   return 0;
}
