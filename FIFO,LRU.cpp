#include<stdio.h>
#include<stdlib.h>
void FIFO(char s[],char F[],int l,int f)
{
	int i,j=0,k,flag=0;
	printf("PAGE\t FRAMES\t FAULTS");
	for(i=0;i<1;i++)
	{
		for(k=0;k<f;k++)
		if(F[k]==s[i])
		flag=1;
		printf("\n%c\t",s[i]);
		if(flag==0)
		{
			F[j++]=s[i];
			printf("%s",F);
			printf("\t page fault");
		}
		else
		{
			flag=0;
			printf("%s",F);
			printf("\t page hit");
		}
		if(j==f)
		j=0;
	}
}
void lru(char s[],char F[],int l,int f)
{
	int i,j=0,k,m,flag=0,cnt=0,top=0;
	printf("\n\t PAGE\t FRAMES\t FAULTS");
	for(i=0;i<l;i++)
	{
		for(k=0;k<f;k++)
		if(F[k]==s[i])
		{
			flag=1;
			break;
		}
		printf("\n%c\t",s[i]);
		if(j!=f&&flag!=1)
		{
			F[top]=s[i];
			j++;
			if(j!=f)
			top++;
		}
		else
		{
			if(flag!=1)
			{
				for(k=0;k<top;k++)
				F[k]=F[k+1];
				F[top]=s[i];
			}
			if(flag==1)
			{
				for(m=k;m<top;m++)
				F[m]=F[m+1];
				F[top]=s[i];
			}
		}
		for(k=0;k<f;k++)
		{
			printf("%c",F[k]);
		}
		if(flag==0)
		{
			printf("\t page fault%d",cnt);
			cnt++;
		}
		else
		printf("\tno page hit");
		flag=0;
	}
}
int main()
{
	int ch,i,l,f;
	char F[10],s[25];
	printf("enter the no of frames:");
	scanf("%d",&f);
	F[f]='\0';
	printf("enter the length of the string:");
	scanf("%d",&l);
	printf("enter the string:");
	scanf("%s",s);
	while(1)
	{
		printf("\n enter :\n1:FIFO\n2:LRU\n3:EXIT\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:for(i=0;i<f;i++)
			F[i]=-1;
			FIFO(s,F,1,f);
			break;
			case 2:for(i=0;i<f;i++)
			F[i]=-1;
			lru(s,F,1,f);
			break;
			case 3:exit(0);
		}
	}
}