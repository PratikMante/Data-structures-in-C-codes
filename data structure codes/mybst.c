#include<stdio.h>
#include<stdlib.h>

int top=-1;

typedef struct bst
{
    int data;
    struct bst *lchild,*rchild;
}node;

node x[50];

void push(node *temp)
{
    top++;
    x[top]=temp;
}

void pop()
{
   top--;
   return (x[top]);
}

node *getnode()
{
    node *temp;
    temp=(node *)malloc(sizeof(node));
    temp->lchild=NULL;
    temp->rchild=NULL;
    return temp;
}

void create(node *root,node *newnode)
{
    if(newnode->data < root->data)
    {
        if(root->lchild == NULL)
          root->lchild = newnode;
        else
         create(root->lchild,newnode)
    }
    if(newnode->data > root->data)
    {
        if(root->rchild==NULL)
          root->rchild=newnode;
        else
          create(root->rchild,newnode)
    }
}

void preorder(node *temp)
{
    while(1)
    {
        while(temp!=NULL)
        {
            printf("%d\t",temp->data);
            if(temp->rchild!=NULL)
               push(temp->rchild);
            temp=temp->lchild   
        }
        temp=pop();
    }
}

void postorder(node *temp)
{
    while(1)
    {
        while(temp!=NULL)
        {
            if(temp->lchild!=NULL)
            {
                push(temp);
                temp=temp->lchild;
            }
            else if(temp->rchild!=NULL)
            {
                temp=temp->rchild;
                push(temp);
                if(temp->lchild!=NULL)
                {
                    temp=temp->lchild;
                    push(temp);
                }
            }
        }
        printf("%d\t",temp->data);
        temp=pop();
    }
}

int count(node *temp)
{
     int c=1;
     if(temp==NULL)
       return 0;
     else
     {
         c=c+count(temp->lchild);
         c=c+count(temp->rchild);
         return c;
     }
}

int main()
{
    int c=1;
    int key;
    node *newnode,*root,*tmp,*parent;
    do
    {
        newnode=getnode();
        printf("\nEnter the element:");
        scanf("%d",&newnode->data);
        if(root==NULL)
          root=newnode;
        else
          create(root,newnode);
        printf("To continue entering elements press 1 or else enter 0:");
        scanf("%d",&c);
    }while(c==1);
    if(root==NULL)
      printf("\nTree not formed");
    else
    {
        printf("\nPreorder:");
        preorder(root);
        printf("\nPostorder:");
        postorder(root);
        c=count(root);
        printf("\nTotal number of nodes: %d",c);
        
    }
}