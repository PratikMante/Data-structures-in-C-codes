#include<stdio.h>
int main()
{ 
char str[]="I am honest student of vit pune" ;//Declare string
int ascii[26]; //Declare variable to store ascii of character
int i=0,x,pc=0;
int temp,j=0;
int bin[26][12];
int encoded[26][17],c,c1,c2,c3;
while(str[i]!='\0')
 {
	if(str[i]!=32)	
	{
		ascii[j]=str[i];
		printf("\n%d",ascii[j]);
		j++;
	}
  i++;
 }
 printf("\n");
for(i=1;i<26;++i)
 {
	temp=ascii[i-1];
	printf("%d ",temp);
	j=8;
	
	    while(temp/2 != 0)
    	{
    	 
		    bin[i][j]=temp%2;
	    	temp=temp/2;
	      
	    	j--;
	    
    	}
	
	    bin[i][j]=temp%2;
	
	for(j=1;j<=8;j++)	
	printf("%d",bin[i][j]);
	printf("\n");
 }
 printf("\n");
 
 for(i=1;i<26;i++)
 {
    encoded[i][1]=bin[i][1]^bin[i][2]^bin[i][4]^bin[i][5]^bin[i][7];
    encoded[i][2]=bin[i][1]^bin[i][3]^bin[i][4]^bin[i][6]^bin[i][7];
    encoded[i][4]=bin[i][2]^bin[i][3]^bin[i][4]^bin[i][8];
    encoded[i][8]=bin[i][5]^bin[i][6]^bin[i][7]^bin[i][8];
    encoded[i][3]=bin[i][1];
    encoded[i][5]=bin[i][2];
    encoded[i][6]=bin[i][3];
    encoded[i][7]=bin[i][4];
    encoded[i][9]=bin[i][5];
    encoded[i][10]=bin[i][6];
    encoded[i][11]=bin[i][7];
    encoded[i][12]=bin[i][8];
 }
 for(i=1;i<26;i++)
 {
     printf("%d",encoded[i][1]);
     printf("%d",encoded[i][2]);
     printf("%d",encoded[i][4]);
     printf("%d",encoded[i][8]);
     printf("\n");
 }
 for(i=1;i<26;i++)
 {
     for(j=1;j<=17;j++)
     {
         printf("%d",encoded[i][j]);
     }
     printf("\n");
 }
 encoded[3][3]=1;//error introduced
 for(i=1;i<26;i++)
    {
        if((encoded[i][1]+encoded[i][3]+encoded[i][5]+encoded[i][7]+encoded[i][9]+encoded[i][11])%2==1)
            pc=pc+1;
        if((encoded[i][2]+encoded[i][3]+encoded[i][6]+encoded[i][7]+encoded[i][10]+encoded[i][11])%2==1)
            pc=pc+2;
        if((encoded[i][4]+encoded[i][5]+encoded[i][6]+encoded[i][7]+encoded[i][12])%2==1)
            pc=pc+4;
        if((encoded[i][8]+encoded[i][9]+encoded[i][10]+encoded[i][11]+encoded[i][12])%2==1)
            pc=pc+8;
        if(pc==0)
        {
            printf("\nNo error in character %c",ascii[i]);
        }
        else
        {
            printf("\nError at bit number %d",pc);
            if(encoded[i][pc]==1)
                encoded[i][pc]=0;
            else
                encoded[i][pc]=1;
            printf("\nCorrect code:");
            for(j=1;j<=13;j++)
            {
                printf("%d",encoded[i][j]);
            }
            printf("\n");
        }
        pc=0;
    }
 return 0;
}
