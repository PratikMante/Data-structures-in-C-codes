
#include<stdio.h>
#include<string.h>
int top=-1;
int k=0;

  char stack[50][50];
  char sign[]={'+','-','/','*'};
  
void push(char str[]);
void pop(char *str);

int main()
{
   char s[50];
   printf("\nEnter the equation in postfix form :");
   fgets(s,50,stdin);
   s[strlen(s)]='\0';
   push(s);
}

void push(char str[])
{
   int i=0,j=0,flag=0,length=0;
   char new1[50],new2[50];
   while(str[i]!='\0')
     {
         for(j=0;j<4;j++)
         {
          if(str[i]==sign[j])
          {
            flag=1;
            break;
          }
         } 
        if(flag)
        {
            pop(new1);
            pop(new2);
            length=strlen(new2);
            new2[length++]=str[i];
            new2[length]='\0';
            strcat(new2,new1);
            if(top>=50)
              printf("Stack Overflow");
            else
            {
                top++;
                strcpy(stack[top],new2);
            }
        }
        else
        {
            new1[0]=str[i];
            new1[1]='\0';
            if(top>=49)
              printf("Stack Overflow");
            else
            {
                top++;
                strcpy(stack[top],new1);
            }
        }
        flag=0;
        i++;  
     }
     for(i=0;i<top;i++)
     {
         printf("%s",stack[i]);
     }
   printf("\n");
}

void pop(char *str)
{
   char h[50];
   int j=0;
   if(top==-1)
   {
       printf("Stack Underflow");
   }
   else
   {
       strcpy(str,stack[top]);
       top--;
   }
}