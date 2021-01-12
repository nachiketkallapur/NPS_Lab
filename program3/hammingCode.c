#include <stdlib.h>
#include<stdio.h>
int main()
{
	int a[4],b[4],r[3],s[3],i,q[3],c[7];
	printf("\nenter 4 bit data word:\n");
	for(i=3;i>=0;i--)
	{
		scanf("%d",&a[i]);
	}	
	r[0]=(a[3]+a[1]+a[0])%2;
	r[1]=(a[0]+a[2]+a[3])%2;
	r[2]=(a[1]+a[2]+a[3])%2;
	printf("\n\nthe 7bit hamming code word: \n");
	for(i=3;i>=0;i--)
	{
		printf("%d\t",a[i]);
	}
	for(i=2;i>=0;i--)
	{
		printf("%d\t",r[i]);
	}
	printf("\n");
	printf("\nenter the 7bit recieved codeword: ");
	for(i=7;i>0;i--)
		scanf ("%d",&c[i]);
	b[3]=c[7];b[2]=c[6];b[1]=c[5];b[0]=c[4];
	r[2]=c[3];r[1]=c[2];r[0]=c[1];
	//calculating syndrome bits
	s[0]=(b[0]+b[1]+b[3]+r[0])%2;
	s[1]=(b[0]+b[2]+b[3]+r[1])%2;
	s[2]=(b[1]+b[2]+b[3]+r[2])%2;
	printf("\nsyndrome is: \n");
	for(i=2;i>=0;i--)
	{
		printf("%d",s[i]);
	}
	if((s[2]==0) && (s[1]==0) && (s[0]==0))
	printf("\n RECIEVED WORD IS ERROR FREE\n");
	if((s[2]==1)&&(s[1]==1)&&(s[0]==1))
	{
		printf("\nError in received codeword, position- 7th bit from right\n");
		if(c[7]==0)
			c[7]=1;
		else
			c[7]=0;
		printf("\n Corrected codeword is\n");
		for(i=7;i>0;i--)
			printf("%d \t", c[i]);
	}
	if((s[2]==1)&&(s[1]==1)&&(s[0]==0))
	{
		printf("\nError in received codeword, Position- 6th bit from right\n");
		if(c[6]==0)
			c[6]=1;
		else
			c[6]=0;
		printf("\n Corrected codeword is\n");
		for(i=7;i>0;i--)
			printf("%d \t", c[i]);
	}
	if((s[2]==1)&&(s[1]==0)&&(s[0]==1))
	{
		printf("\nError in received codeword, Position- 5th bit from right\n");
		if(c[5]==0)
			c[5]=1;
		else
			c[5]=0;
		printf("\n Corrected codeword is\n");
		for(i=7;i>0;i--)
			printf("%d \t", c[i]);
	}
	if((s[2]==1)&&(s[1]==0)&&(s[0]==0))
	{
		printf("\nError in received codeword, Position- 4th bit from right\n");
		if(c[4]==0)
			c[4]=1;
		else
			c[4]=0;
		printf("\n Corrected codeword is\n");
		for(i=7;i>0;i--)
			printf("%d \t", c[i]);
	}
	if((s[2]==0)&&(s[1]==1)&&(s[0]==1))
	{
		printf("\nError in received codeword, Position- 3rd bit from right\n");
		if(c[3]==0)
			c[3]=1;
		else
			c[3]=0;
		printf("\n Corrected codeword is\n");
		for(i=7;i>0;i--)
			printf("%d \t", c[i]);
	}
	if((s[2]==0)&&(s[1]==1)&&(s[0]==0))
	{
		printf("\nError in received codeword, Position- 2nd bit from right\n");
		if(c[2]==0)
			c[2]=1;
		else
			c[2]=0;
		printf("\n Corrected codeword is\n");
		for(i=7;i>0;i--)
			printf("%d \t", c[i]);
	}
	if((s[2]==0)&&(s[1]==0)&&(s[0]==1))
	{
		printf("\nError in received codeword, Position- 1st bit from right\n");
		if(c[1]==0)
			c[1] =1;
		else
			c[1]=0;
		printf("\n Corrected codeword is\n");
		for(i=7;i>0;i--)
			printf("%d \t", c[i]);
	}
	return(1);
}//End of Hamming code program*/