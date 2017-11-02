/*Recursion count characters*/
#include <stdio.h>
#include <string.h>

int count(char *a, char c, int n)
{
	
	//char *p =a;
	if(!*a)
		return n;
	if(*a ==c)
		n= count(a+1,c,n+1);
	else
		n= count(a+1,c,n);
	return n;
}

int main()
{
	char a[50],c;
	int i=0;//Here this keeps count of the number of occurences.
	printf("Enter string\n");
	scanf("%s",a);
	printf("Enter character to find\n");
	scanf("%s",&c);
	printf("No : %d\n",count(a,c,i));

}