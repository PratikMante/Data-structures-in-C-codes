#include<stdio.h>
int fib(int);
int main()
{
    int n;
    printf("\n enter a number:");
    scanf("%d",&n);
    fib(n);
    printf("series=%d",fib(n));
}
int fib(int n)
{
    if(n>0)
    {
        return(fib(n-1)+fib(n-2));
    }
    else 
    return(1);
}