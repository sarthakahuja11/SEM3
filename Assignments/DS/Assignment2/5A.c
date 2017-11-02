#include<ctype.h>
#include<stdio.h>
#include<conio.h>
#define MAX 20
#include<string.h>

void convert_postfix(char x);
char stack[MAX][MAX];
void prefix_to_postfix(char prefix[],char postfix[]);

int top;
/* Array 'stack[][]' is being used as a stack of strings */

void main()
{
    char postfix[30],prefix[30];
    clrscr();
    printf("\nEnter a prefix expression :");
    gets(prefix);
    prefix_to_postfix(prefix,postfix);
    printf("\nPostfix :    %s",postfix);
    getch();
}

   void prefix_to_postfix(char prefix[],char postfix[])
     {
       char x,st1[20];
       int i;
       top=-1;
       for(i=strlen(prefix)-1;i>=0;i--) //scan the prefix string from
         {                              //right to left.
          x=prefix[i];
          if(isalnum(x))
            {
            /* convert token to string form */
            st1[0]=x;
            st1[1]='\0';
            // push the operand on the stack s2
            top=top+1;
            strcpy(stack[top],st1);
             }
        else  // if operator, convert to postfix
             {
              convert_postfix(x);
             }
          }
    //Result is on top of the stack
    strcpy(postfix,stack[top]);
}



void convert_postfix(char x)
{       char st1[30],st2[30];
    st2[0]=x;
    st2[1]='\0';
    strcpy(st1,stack[top]);
    strcat(st1,stack[top-1]);
    strcat(st1,st2);
    top=top-1;
    strcpy(stack[top],st1);
}


