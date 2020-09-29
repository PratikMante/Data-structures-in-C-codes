#include<stdio.h>
#include<curses.h>
#include<string.h>
typedef struct prof
{
    char a[200],b[200];
}prof;
int main()
{
    prof p[20],q[20],r[20],s[20];
    int i,j,k=0,l,n,m;
    char c;
    printf("\n enter number of entries you wish to make:");
    scanf("%d",&m);
    //while((c= getchar()) != '\n' && c != EOF);
    printf("NOTE: For entering name of professor enter it with designation as main professor");
    getchar();
    flushinp();
    for(i=0;i<m;i++)
    {
        puts("\n Enter name of professor with designation:");
        gets(p[i].a);
    }
    for(i=0;i<m;i++)
    {
        if(strncmp(p[i].a,"professor",9)==0)
        {
         strcpy(q[i].a,p[i].a);
        }
    }
      for(i=0;i<m;i++)
    {
        if(strncmp(p[i].a,"assistant",9)==0)
        {
         strcpy(r[i].a,p[i].a);
        }
    } 
    for(i=0;i<m;i++)
    {
        if(strncmp(p[i].a,"associate",9)==0)
        {
         strcpy(s[i].a,p[i].a);
        }
    }
    
    return(0);
}    