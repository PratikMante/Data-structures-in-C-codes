#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
 int data;
 struct node *next;
 struct node *previous;
}n;

void insert(n *value,int data)
{
 while(value->next != NULL)
  {
   value=value -> next;
  }
  value->next =(n *)malloc(sizeof(n));
  value->next->previous = value;
  value= value->next;
  value->data =data;
  value->next = NULL;
}

void merge(n *n1,n *n2)
{
    n *temp,*new1;
    temp=(n*)malloc(sizeof(n));
    while(n1->next!=NULL)
    {
        if(n1 -> data > n2 -> data)
        {
            new1=(n*)malloc(sizeof(n));
            new1->next=n1->previous;
            new1->data=n2->data;
            temp->next=n1->previous->next;
            new1->previous=temp->next;
            n2=n2->next;
        }
        n1=n1->next;
    }
    n1->next=n2;
    
}

void display(n *n1)
{
    while(n1->next!=NULL)
    {
       printf("%d",n1->data);
       n1=n1->next;
    }   
}

int main()
{
 n *first1,*first2,*last,*last1;
 int i=0,data;
 first1 =(n *)malloc(sizeof(n));
 last=first1;
 last -> next =NULL;
 last -> previous=NULL;
 first2 =(n *)malloc(sizeof(n));
 last1=first2;
 last1 -> next =NULL;
 last1 -> previous=NULL;
 printf("\nEnter 5 values in sorted manner for doubly linked list 1:");
 while(i<5)
  {
    scanf("%d",&data);
    insert(first1,data);
    i++;
  }
  i=0;
  printf("\nEnter another 5 values in sorted manner for doubly linked list 2:");
 while(i<5)
  {
    scanf("%d",&data);
    insert(first2,data);
    i++;
  }
  merge(first1,first2);
  display(first1);
}