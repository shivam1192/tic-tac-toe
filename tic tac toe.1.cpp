#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
void shape(int i,int j,int n);
void dia(int i,int j,int n,int k);
void ticd(int n,int k);
char ar[3][3];
int sum[8]={0,0,0,0,0,0,0,0},summ[8]={0,0,0,0,0,0,0,0};
int main()
{
	int i,j=0,x,v,fr[20],slash=0,flash=0,s,y,clash=0,g,llash=0,k;
	char ply1[10],ply2[10];
	k:
	printf("TIC TAC TOE GAME\n\n");
	printf("press 1 for playing the game\npress 2 for instruction\npress 3 for exit");
	scanf("%d",&y);
	if(y<=0||y>=4)
	{
		system("cls");
		printf("PLEASE SELECT VALID KEY\n\n");
		goto k;
	}
	system("cls");
	if(y==1)
	{
		llash:
    printf("ENTER PLAYER 1 NAME=");
	scanf("%s",ply1);
	printf("\n");
	printf("ENTER PLAYER 2 NAME=");
	scanf("%s",ply2);
	printf("\n\nENTER ANY KEY TO CONTINUE");
	getch();
	system("cls");
	clash:
			for(g=0;g<8;g++)
		{
			sum[g]=0;summ[g]=0;
		}
	clash++;
	ticd(0,0);
	for(i=0,v=0;i>=0,v>=0;i++,v++)
	{
		int n,m;
		slash:
		printf("%s turn:",ply1);
		scanf("%d",&n);
		fr[v]=n;v++;
		if(i==0&&(n>9||n<=0))
		{
			printf("wrong move\n");
			goto slash;
		}
		j++;s=0;
		 while(s<v-1) 
		{
		if(fr[s]==n||(n>9||n<=0))
			{
				printf("wrong move\n");
				j--;
				goto slash;
			}
			s++;
		}
		ticd(n,j);
	if(n==1||n==2||n==3)
	sum[0]++;
	if(n==4||n==5||n==6)
	sum[1]++;
	if(n==7||n==8||n==9)
	sum[2]++;
	if(n==1||n==4||n==7)
	sum[3]++;
	if(n==2||n==5||n==8)
	sum[4]++;
	if(n==3||n==9||n==6)
	sum[5]++;
    if(n==1||n==5||n==9)
	sum[6]++;
	if(n==3||n==5||n==7)
	sum[7]++;
	if(sum[0]==3||sum[1]==3||sum[2]==3||sum[3]==3||sum[4]==3||sum[5]==3||sum[6]==3||sum[7]==3)
		{
			printf("congratulation %s win\n\nPress 1 for continue the game\nPress 2 for exit the game",ply1);
			flash++;
			scanf("%d",&y);
				system("cls");
			if(y==1)
			goto clash;
			else
			break;
		}
		flash:
		printf("%s turn:",ply2);
		scanf("%d",&m);
		fr[v]=m;
		j++;s=0;
				while(s<v)
		{
			if(fr[s]==m||(m>9||m<=0))
			{
				printf("wrong move\n");
				j--;
				goto flash;
			}s++;
		}
		ticd(m,j);
	if(m==1||m==2||m==3)
	summ[0]++;
	if(m==4||m==5||m==6)
	summ[1]++;
	if(m==7||m==8||m==9)
	summ[2]++;
	if(m==1||m==4||m==7)
	summ[3]++;
	if(m==2||m==5||m==8)
	summ[4]++;
	if(m==3||m==9||m==6)
	summ[5]++;
    if(m==1||m==5||m==9)
	summ[6]++;
	if(m==3||m==5||m==7)
	summ[7]++;
    if(summ[0]==3||summ[1]==3||summ[2]==3||summ[3]==3||summ[4]==3||summ[5]==3||summ[6]==3||summ[7]==3)
		{
			printf("congratulation %s win\n\nPress 1 for continue the game\nPress 2 for exit the game",ply2);
			slash++;
				scanf("%d",&y);
				system("cls");
			if(y==1)
			goto clash;
			else
			break;
		}
		else if(i==8)
		{
			printf("draw");
			break;
		}
	}
	if(y==2)
	printf("TOTAL MATCH PLAYED %d\n\nMATCH WINS BY %s:%d\n\nMATCH WINS BY %s:%d",clash,ply1,flash,ply2,slash);
}
else if(y==2)
{
	printf("INSTRUCTION:\n\n\n\n\nFrom the keyboard press the numberic key in which you want to insert zero or cross\nPlayer 1 always has cross while player 2 has zero as there tic tok toe symbol\npress 1 for continue the game\npress 2 for exit the game\n");
	scanf("%d",&y);
	system("cls");
	if(y==1)
	goto llash;
}
}
void ticd(int n,int k)
{
	int i,j;
	if(n==0)
	{
			for(i=1;i<4;i++)
			{
				for(j=1;j<4;j++)
					shape(i,j,n);
				printf("\n");
			}	
	}
	else
	{
			for(i=1;i<4;i++)
			{
				for(j=1;j<4;j++)
					dia(i,j,n,k);
				printf("\n");
			}
	}
}

void shape(int i,int j,int n)
{
	    static int t=0;
		t++;
		if(t==10)
		t=1;
		if(i!=3&&j!=3)
    {
    printf("%d___",t);
   	printf("|");
    }
    else if(i==3&&j!=3)
    printf("%d   |",t);
	else if(j==3&&i!=3) 
	printf("%d___",t);
	else
	printf("%d",t);
}

void dia(int i,int j,int n,int k)
{
	if((n<4&&j==n&&i==1)||((n>3&&n<7)&&i+j+1==n&&i==2)||(n>6&&i+j+3==n&&i==3))
	{
	 if(k%2==0)
	  ar[i][j]='0';	
	 else
	  ar[i][j]='*';	
	}
    else
     ar[i][j]=' ';
	if(i!=3&&j!=3)
    {
     printf("%c___",ar[i][j]);
     printf("|");
    }
    else if(i==3&&j!=3)
    printf("%c   |",ar[i][j]);
	else if(j==3&&i!=3) 
	printf("%c___",ar[i][j]);
	else
	printf("%c",ar[i][j]);
}
