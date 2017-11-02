/* Recursion Fibonnaci series */
#include <stdio.h>

int Fib(int n){
	if(n ==0 || n==1)
	{
		return n;
	}
	else
	{
		return Fib(n-1)+Fib(n-2);
	}
}

int main()
{
	int n,i;
	printf("Enter limit\n");
	scanf("%d",&n);
	for(i = 0;i<n;i++)
	{
		printf("%d\n",Fib(i));
	}

}