#include<stdio.h>
int k;
int m=0;//starting point of queue
typedef struct jobs
{
  int no;
  int time;
};

struct jobs enqueue(struct jobs j,struct jobs l)
{
    j=l;
    k++;
    return j;
}

void dequeue()
{
    m++;
}

int main()
{
    struct jobs j[100],temp;
    int v;
    int i,n,l;
    printf("\nEnter number of jobs:");
    scanf("%d",&l);
    printf("\nEnter fixed time:");
    scanf("%d",&n);
    v=l;
    for(i=0;i<l;i++)//time allocation for each job
    {
        printf("\nEnter time for job j%d:",i);
        scanf("%d",&j[i].time);
        j[i].no=i;
    }
    
    k=l;//end point of queue
    while(v!=0)
    {
        if(j[m].time==n ||j[m].time<n)
         {
             printf("\nJob of %d done",j[m].no);
             dequeue();
             v--;
         }
         else 
         {
             j[m].time=j[m].time-n;
             j[k]=enqueue(temp,j[m]);
             dequeue();
         }
        
    }
    
}