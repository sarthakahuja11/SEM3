/*Recusrion Array sum */
#include <stdio.h>

int sum(int *a,int n)
{
	if(NULL == a || n <0)
		return 0;
	return a[n]+ sum(a,n-1);
}

int main()
{
	int a[20],n,i=0;
	printf("Number of element\n");
	scanf("%d",&n);
	printf("Enter the elements\n");
	for(i =0; i < n; i++)
	{
		scanf("%d",&a[i]);
	}
	printf("Sum : %d\n", sum(a,n-1));
	return 0;
}