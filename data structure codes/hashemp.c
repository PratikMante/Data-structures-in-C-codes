#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define limit 10
enum type{EMPTY,FULL,DELETED};
struct emp
{
    int id;
    char name[20];
};
typedef struct rec
{
    struct emp data;
    enum type status;
}hasher[limit];

int hash(int key)
{
    int m;
    m=mid(key);
    return(m%limit);
}

int mid(int e)
{
    int a[]={1,10,100,1000,10000,100000,1000000,10000000};
    int square,next,trim,digit=0,x,i;
    square=e*e;
    x=square;
    while(x!=0)
    {
        x=x/10;
        digit++;
    }
    trim=(digit/2);
    square=square/a[trim];
    for(i=0;i<digit;i++)
    {
        next+=(square%(a[trim])*a[i]);
        square=square/10;
    }
    return(next);
}

void insert(int a,char s[],struct rec hasher[])
{
    int i,h,k,j;
    k=mid(a);
    h=hash(k);
    j=h;
    for(i=0;i<limit-1;i++)
    {
        if(hasher[j].status==EMPTY || hasher[j].status==DELETED)
        {
            hasher[j].data.id=a;
            strcpy(hasher[j].data.name,s);
            hasher[j].status=FULL;
            printf("\nRecord inserted\n");
            return;
        }    
        if(hasher[j].data.id==a)
        {
            printf("\nDuplicate");
            return;
        }
        j=(h+i)%limit;
    }
}

void search(int a,struct rec hasher[])
{
    int i,h,k,j;
    k=mid(a);
    h=hash(k);
    j=h;
    for(i=0;i<limit-1;i++)
    {
        if(hasher[j].status==EMPTY)
        {
            printf("\nrecord empty");
            break;
        }
        if(hasher[j].data.id==a)
        {
            printf("\nRecord found!!!");
            printf("\nEmployee found at %d",j);
            printf("\nEmployee name: %s \n",hasher[j].data.name);
            break;
        }
        j=(h+1)%limit;
    }
}

void display(struct rec hasher[])
{
    int i;
    for(i=0;i<limit;i++)
    {
        if(hasher[i].status==FULL)
        {
            printf("\nEmployee id:%d\n",hasher[i].data.id);
            printf("\nEmployee name: %s\n",hasher[i].data.name);
        }
    }
}

void delet(int a,struct rec hasher[])
{
    int i,j,h,k;
    k=mid(a);
    h=hash(k);
    j=h;
    for(i=0;i<limit-1;i++)
    {
        if(hasher[j].status==EMPTY)
        {
            printf("\nrecord empty\n");
            break;
        }
        if(hasher[j].data.id==a)
        {
            hasher[j].status=DELETED;
            printf("\nRecord deleted\n");
            break;
        }
        j=(h+1)%limit;
    }
}

int main()
{
    int i,j,c,a;
    char s[20];
    struct rec hasher[limit];
    struct emp e;
    for(i=0;i<limit-1;i++)
    {
        hasher[i].status=EMPTY;
    }
    while(1)
    {
        printf("\n1 Insert\n2 Search\n3 Delet\n4 Display\n5 Exit\n Enter choice:\n");
        scanf("%d",&c);
        switch(c)
        {
            case 1:
              printf("\nEnter employee id:");
              scanf("%d",&e.id);
              printf("\nEnter name of the employee:");
              scanf("%s",&e.name);
              a=e.id;
              strcpy(s,e.name);
              insert(a,s,hasher);
              break;
            case 2:
              printf("\nEnter employee id to be searched:");
              scanf("%d",&a);
              search(a,hasher);
              break;
            case 3:
              printf("\nEnter employee id to deleted:");
              scanf("%d",&a);
              delet(a,hasher);
              break;
            case 4:
              printf("\nEmployee Record:");
              display(hasher);
              break;
            case 5: 
              exit(1);
        }
    }
}