#include<stdio.h>
int main()
{
    int n,m,x,l,i;
    int j[50];
    printf("\nEnter total number of soldiers:");
    scanf("%d",&n);
    printf("\nEnter a number less than n to remove soldier:");
    scanf("%d",&m);
    printf("\nEnter a number from where you wish to start:");
    scanf("%d",&x);
    for(i=1;i<=n;i++)
    {
        j[i-1]=i;
    }
    j[n]=99;
    i=0;
    x=x-1;
    while(j[1]!=99)
    {
        j[x];
        if(i<=m-1)
        {
            if(j[x]==99)
            {
               x=0;
            }
            else
              x++;
            i++;
        }
        else
         {
            i=0;
            l=x;
            while(j[l]!=99)
            {
               j[l]=j[l+1];
               l++;
            }
         }
    }
    printf("\nSoldier number %d will get help.",j[0]);
}
