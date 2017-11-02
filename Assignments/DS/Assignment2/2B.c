#include <stdio.h>

double comb(double n,double r)
{
    if(r==1)
        return n;
    else
    {
        return ((n/r)*(comb(n-1,r-1)));
    }
}
int main()
{
    double n,r;
    scanf("%lf %lf",&n,&r);
    double a = comb(n,r);
    printf("%lf\n",a);
    return 0;
}
