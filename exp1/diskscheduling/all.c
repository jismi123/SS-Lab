#include<stdio.h>
#include<stdlib.h>
void FCFS(int [],int,int);
void SCAN(int [],int,int);
void CSCAN(int [],int,int);
void main()
{
	int n,i,intialhead,ch;
	printf("\n Disk Scheduling Algorithm\n Enter the number of request:");
	scanf("%d",&n);
	int req[n];
	printf("Enter the sequence:");
	for(i=0;i<n;i++)
	{
		scanf("%d",&req[i]);
	}
	printf("Enter the intial head:");
	scanf("%d",&intialhead);
	do
	{
		printf("\n 1.FCFS\t2.SCAN\t3.C-SCAN\t4.EXIT\nEnter your choice:");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
			{
				printf("FCFS disk sceduling");
				FCFS(req,intialhead,n);
				break;
			}
			case 2:
			{
				printf("SCAN disk sceduling");
				SCAN(req,intialhead,n);
				break;
			}
			case 3:
			{
				printf("C-SCAN disk sceduling");
				CSCAN(req,intialhead,n);
				break;
			}
			case 4:
			{
				printf("Exiting!!!");
				break;
			}
			default: printf("Invalid choice!!!");
		}
	}while(ch!=4);
int fflush(FILE *stream);
}

void FCFS(int p[],int intial,int n)
{
	int i,total=0;
	for(i=0;i<n;i++)
	{
		total=total+abs(p[i]-intial);
		intial=p[i];
	}
	printf("\n Total head movements:%d\n",total);
}

void SCAN(int p[],int intial,int n)
{
	int disksize,d,i,j,total;
	printf("Enter the disk size:");
	scanf("%d",&disksize);
	printf("Direction: 1.High 2.Low\nEnter the head movement direction:");
	scanf("%d",&d);
	for(i=0;i<n;i++)
	{
		for(j=0;j<n-i-1;j++)
		{
			if(p[j]>p[j+1])
			{	
				int temp;
				temp=p[j];
				p[j]=p[j+1];
				p[j+1]=temp;
			}
		}
	}
	int index;
	for(i=0;i<n;i++)
	{
		if(intial<p[i])
		{
			index=i;
			break;
		}
	}
	
	if(d==1)
	{
		for(i=index;i<n;i++)
		{
			total=total+abs(p[i]-intial);
			intial=p[i];
		}
		total=total+abs(disksize-p[i-1]-1);
		intial=disksize-1;
		for(i=index-1;i>=0;i--)
		{
			total=total+abs(p[i]-intial);
			intial=p[i];
		}
	}
	else
	{
		for(i=index-1;i>=0;i--)
		{
			total=total+abs(p[i]-intial);
			intial=p[i];
		}
		total=total+abs(p[i+1]-0);
		intial=0;
		
		for(i=index;i<n;i++)
		{
			total=total+abs(p[i]-intial);
			intial=p[i];
		}
	}
	
	printf("\n Total head movements:%d\n",total);
}

void CSCAN(int p[],int intial,int n)
{
	int disksize,d,i,j,total;
	printf("Enter the disk size:");
	scanf("%d",&disksize);
	printf("Direction: 1.High 2.Low\nEnter the head movement direction:");
	scanf("%d",&d);
	for(i=0;i<n;i++)
	{
		for(j=0;j<n-i-1;j++)
		{
			if(p[j]>p[j+1])
			{	
				int temp;
				temp=p[j];
				p[j]=p[j+1];
				p[j+1]=temp;
			}
		}
	
	}
	int index;
	for(i=0;i<n;i++)
	{
		if(intial<p[i])
		{
			index=i;
			break;
		}
	}
	
		
	if(d==1)
	{
		for(i=index;i<n;i++)
		{
			total=total+abs(p[i]-intial);
			intial=p[i];
		}
		total=total+abs(disksize-p[i-1]-1);
		total=total+abs(disksize-1-0);
		intial=0;
		for(i=0;i<index;i++)
		{
			total=total+abs(p[i]-intial);
			intial=p[i];
		}
	}
	else
	{
		for(i=index-1;i>=0;i--)
		{
			total=total+abs(p[i]-intial);
			intial=p[i];
		}
		total=total+abs(p[i+1]-0);
		total=total+abs(disksize-1-0);
		intial=disksize-1;
		
		
		for(i=n-1;i>=index;i--)
		{
			total=total+abs(p[i]-intial);
			intial=p[i];
		}
	}
	
	printf("\n Total head movements:%d\n",total);
}

