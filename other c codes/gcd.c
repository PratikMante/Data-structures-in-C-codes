#include<stdio.h>
int main()
{
    int a,b,i=1,j;
    printf("\nEnter 2 numbers:");
    scanf("%d%d",&a,&b);
    j=gcd(a,b,i);
    printf("gcd:%d",j);
    return 0;
}

int gcd(int a,int b,int i)
{
    int x;
    if(a%i==0 && b%i==0)
    {
        x=i;
        gcd(a,b,i++);
    }
    else if(a<=i && b<=i)
        gcd(a,b,i++);
    else
        return x;
}