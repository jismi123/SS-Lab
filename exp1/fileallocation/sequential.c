#include<stdio.h>
#include<stdlib.h>
int main()
{
	int i,j,n,f[50],st,c,k,index,count=0,len;
	for(i=0;i<50;i++)
	{
		f[i]=0;
	}
	printf("Files allocated are:\n");
	x:count=0;
	printf("Enter starting block and length of files:");
	scanf("%d%d",&st,&len);
	for(k=st;k<(st+len);k++)
	{
	if(f[k]==0)
		count++;
	}
	if(len==count)
	{
		for(j=st;j<(st+len);j++)
		{
			if(f[j]==0)
			{
				f[j]=1;
				printf("%d\t%d\n",j,f[j]);
			}
		}
		if(j!=(st+len-1))
		printf("File is allocated to disk\n");
			
	}
	else
	{
		printf("The file is not allocated\n");
	}
	printf("Do you want to enter more files(Yes-1/No-0):");
	scanf("%d",&c);
	if(c==1)
		goto x;
	else
		exit(0);
		
}
	



/*


------------OUTPUT------------

Files allocated are:
Enter starting block and length of files:17 4
17	1
18	1
19	1
20	1
File is allocated to disk
Do you want to enter more files(Yes-1/No-0):1
Enter starting block and length of files:21 3
21	1
22	1
23	1
File is allocated to disk
Do you want to enter more files(Yes-1/No-0):0

*/
