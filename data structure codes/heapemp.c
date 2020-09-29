#include<stdio.h>
#include<string.h>
typedef struct emp{
    char name[20];
    int num;
    int salary;
}emp;
int main()
{
    emp e[5],temp[1];
    int i,j,k,l,n,ch;
    n=5;
    do
    {
        printf("\n1 Heap Sort\n2 Bubble Sort\n3Exit");
        printf("\nEnter choice:");
        scanf("%d",&ch);
        switch(ch)
    {
    case 1:    
    for(i=0;i<5;i++)
    {
        printf("\n Enter number:");
        scanf("%d",&e[i].num);
        printf("\n Enter name:");
        scanf("%s",&e[i].name);
        printf("\n Enter salary:");
        scanf("%d",&e[i].salary);
    }
   for(i=0;i<n;i++)
   {
       k=i;
       do
       {
           l=(k-1)/2;
           if(e[l].num<e[k].num)
           {
               temp[0]=e[l];
               e[l]=e[k];
               e[k]=temp[0];
           }
           k=l;
       }while(k!=0);
   }
   
   printf("current sort:");
   for(i=0;i<n;i++)
      printf("%d\t",e[i].num);
      
   for(j=n-1;j>=0;j--)
   {
       temp[0]=e[0];
       e[0]=e[j];
       e[j]=temp[0];
       l=0;
       do
       {
           k=2*l+1;
           if((e[k].num<e[k+1].num)&&k<j-1)
             k++;
           if((e[l].num<e[k].num)&&k<j)
           {
               temp[0]=e[l];
               e[l]=e[k];
               e[k]=temp[0];
           }
           l=k;
       }while(k<j);
   }
   
    for(i=0;i<5;i++)
    {
        printf("\n num: %d",e[i].num);
        printf("\n name: %s",e[i].name);
        printf("\n salary: %d",e[i].salary);
    }
    break;
    case 2:
    for(i=0;i<5;i++)
    {
        printf("\n enter employee number:");
        scanf("%d",&e[i].num);
        printf("\n enter employee name:");
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
                temp[0]=e[l];
                e[l]=e[l+1];
                e[l+1]=temp[0];
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
    break;
    default:
      printf("Incorrect choice");
      break;
    }
    }while(ch!=3);
}

