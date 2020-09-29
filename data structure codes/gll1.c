#include <stdio.h>
//#include<conio.h>
#include<stdlib.h>
#include<string.h>
//#include <malloc.h>
 
struct node * createNode(char a, int b);
struct node * createGLL(char str[]);
int equal(struct node *, struct node *);
void display(struct node *);
 
struct node
{
    int flag;
    char data;
    struct node *link;
    struct node *next;
 
} *q;
 
int i = 0;
 
int main()
{
    char s[50];
    int ch1, ch2;
 
    struct node *s1, *s2;
 
    do
    {
         
        printf("\n1)Create GLL\n3)Display\n4)Exit\n");
        printf("\nEnter your choice: \n ");
        scanf("%d", &ch1);
 
        switch (ch1)
        {
        case 1: i = 0;
            printf("Enter 1st GLL:");
            gets(s);
            gets(s);
            s1 = createGLL(s);
            break;
       
 
        case 3:
            printf("The 1st GLL is:  ");
            display(s1);
            break;
 
        case 4:printf("EXIT!!\n");
            break;
        
                
 
        default:printf("\n Enter valid choice!\n");
        }
        printf("\nDo you want to continue?YES(1) NO(0)\n");
 
        scanf("%d", &ch2);
 
    } while (ch2 == 1);
 
}
 
struct node * createGLL(char str[])
{
    struct node *start = NULL, *new = NULL;
 
    while (str[i] != '\0' && str[i] != ')')
    {
        if (str[i] != '(' && str[i] != ',')
        {
             
            new = createNode(str[i], 0);
 
            if (start == NULL)
                start = new;
            else
            {
                q = start;
                while (q->next != NULL)
                    q = q->next;
                q->next = new;
            }
        }
        else if (str[i] == '(')
        {
            i++;
 
            new = createNode('#', 1);
 
            if (start == NULL)
                start = new;
            else
            {
                q = start;
                while (q->next != NULL)
                    q = q->next;
                q->next = new;
            }
 
            new->link = createGLL(str);
        }
        i++;
    }
    return start;
}
 
struct node * createNode(char a, int b)
{
    struct node *n;
    n = (struct node *) malloc(sizeof(struct node));
 
    if (n == NULL)
        printf(" No available memory!\n");
    else
    {
        n->flag = b;
        n->data = a;
        n->link = NULL;
        n->next = NULL;
    }
    return n;
}
 
 
int equal(struct node * p, struct node * q)
{
    int x;
    if (p == NULL && q == NULL)
        return(1);
 
    if (p != NULL && q != NULL && p->flag == q->flag)
    {
        if (p->flag == 0)
        {
            if (p->data == q->data)
                x = 1;
            else
                x = 0;
        }
        else
            x = equal(p->link, q->link);
 
        if (x == 1)
            return(equal(p->next, q->next));
    }
    return(0);
}
 
 
void display(struct node *p)
{
    while (p != NULL)
    {
        if (p->flag == 0)
        {
            printf("%c", p->data);
            if (p->next != NULL)
                printf(", ");
        }
        else if (p->flag == 1)
        {
            printf("(");
            display(p->link);
            printf("), ");
        }
        p = p->next;
    }
}



// Delete first item
/*void deleteFirst()
{
    // Save reference to head
    struct node *temp = head;

    // Point head to head's next
    head = head->next;

    // Free memory used by temp
    temp = NULL;
    delete temp;

    printf( "Deleted successfully"\n);
}*/
