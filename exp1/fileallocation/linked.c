#include<stdio.h>
#include<stdlib.h>
void main()
{
	int f[50],i,st,len,j,c,p,a,k;
	for(i=0;i<50;i++)
		f[i]=0;
	printf("Enter how many blocks already allocated:");
	scanf("%d",&p);
	printf("Enter blocks already allocated:");
	for(i=0;i<p;i++)
	{
		scanf("%d",&a);
		f[a]=1;
	}
	x:printf("Enter index starting block and length:");
	scanf("%d%d",&st,&len);
	k=len;
	if(f[st]==0)
	{
		for(j=st;j<(st+k);j++)
		{
			if(f[j]==0)
			{
				f[j]=1;
				printf("%d------->%d\n",j,f[j]);
			}
			else
			{
				printf("%d block is already allocated\n",j);
				k++;
			}
		}
	}
	else
	{
		printf("%d starting block is already allocated\n",st);
	}
	printf("Do you want to enter more file(Yes-1/No-0:)");
	scanf("%d",&c);
	if(c==1)
		goto x;
	else
		exit(0);
}


/*

------------OUTPUT----------

Enter how many blocks already allocated:3
Enter blocks already allocated:4 7 9
Enter index starting block and length:3 7
3------->1
4 block is already allocated
5------->1
6------->1
7 block is already allocated
8------->1
9 block is already allocated
10------->1
11------->1
12------->1
Do you want to enter more file(Yes-1/No-0:)0

*/
