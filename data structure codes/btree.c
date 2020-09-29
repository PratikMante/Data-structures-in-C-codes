#include<stdio.h>
#include<stdlib.h>
struct btree
{
  int info;
  struct btree *left;
  struct btree *right;
  int rt;
  int lt;
};
struct btree *head,*p;
void addnode(int);
void inorder(struct btree *);
void preorder(struct btree *);

int main()
{
  int ch,val;
  head=malloc(sizeof(struct btree));
  head->left=p;
  head->right=head;
  head->lt=0;head->rt=1;
  do
  {
     printf("\nTHREADED BINARY TREE");
     printf("\n1.New Node");
     printf("\n2.Inorder Traversing");
     printf("\n3.Preorder traversing");
     printf("\n0.Exit");
     printf("\nEnter your choice:");
     scanf("%d",&ch);
     switch(ch)
     {
         case 1:
         printf("\nEnter value:");
         scanf("%d",&val);
         addnode(val);
         break;
         
         case 2:
         printf("\nInorder Traversal:");
         inorder(p);
         break;
         
         case 3:
         printf("\nPreorder Traversal:");
         preorder(p);
         break;
     }
  }while(ch);
}

void addnode(int v)
{
    struct btree *r,*q;
    q=p;
    r=malloc(sizeof(struct btree));
    r->info=v;
    r->rt=1;
    r->lt=1;
    if(p==NULL)
    {
        p=r;
        r->left=head;
        r->right=head;
        //return;
    }
    while(q!=head)
    {
        if(q->info>v && q->lt==0)
           q=q->left;
        else if(q->info<v && q->rt==0)
           q=q->right;
        else
           break;
    }
    if(q->info>v)
    {
        q->lt=0;
        r->right=q;
        r->left=q->left;
        q->left=r;
        //return;
    }
    else if(q->info<v)
    {
        q->rt=0;
        r->right=q->right;
        r->left=q;
        q->right=r;
        //return;
    }
}

void inorder(struct btree *q)
{
    int flag=0;
    while(q!=head)
    {
        if(flag==0)
        {
            while(q->lt==0)
               q=q->left;
        }
        printf("%d\t",q->info);
        flag=q->rt;
        q=q->right;
    }
}

void preorder(struct btree *q)
{
    int flag=0;
    while(q!=head)
    {
        while(flag==0)
        {
            printf("%d\t",q->info);
            if(q->lt==0)
              q=q->left;
            else
              break;
        }
        flag=q->rt;
        q=q->right;
    }
}