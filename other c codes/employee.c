#include<stdio.h>
typedef struct emp
{
    char name[20];
    int num;
    int salary;
}emp;
int main()
{
    emp e[20],k;
    int i,j=0,l;
    for(i=0;i<5;i++)
    {
        printf("\n enter employee number:");
        scanf("%d",&e[i].num);
        prinf("\n enter employee name:");
        scanf("%s",&e[i].name);
        printf("\n enter employee salary:");
        scanf("%d",&e[i].salary);
        printf("\n ----------------------------");
    }
    for(i=0;i<4;i++)
    {
        for(l=0;l<4-i;l++)
        {
            if(e[l].num > e[l+1].num)
            {
                k=e[l];
                e[l]=e[l+1];
                e[l+1]=k;
                j=j+1;
            }
        }
    }
   for(i=0;i<5;i++)
    {
        printf("\n employee number: %d",e[i].num);
        printf("\n employee name: %s",e[i].name);
        printf("\n employee salary: %d",e[i].salary);
        printf("\n ----------------------------");
    } 
    printf("\n total number of swaps: %d",j);
}