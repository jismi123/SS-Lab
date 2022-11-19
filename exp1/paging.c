#include<stdio.h>
struct page
{
	int n;
	int p[50];
};
int frame[100];
int nof;
int no_of_frames()
{
	int i,count=0;
	for(i=0;i<nof;i++)
	{
		if(frame[i]==0)
		{
			count++;
		}
	
	}
	return count;
}
void main()
{
	int mem_size,frame_size,nop,i,j,y,pno,z,frame1,temp,k,l,topt;
	struct page process[50];
	printf("\nEnter the main memory size in bytes:");
	scanf("%d",&mem_size);
	printf("\nEnter the page size/frame size:");
	scanf("%d",&frame_size);
	nof=mem_size/frame_size;
	printf("%d frames are present in main memory and let them be numbered from 0 to %d",nof,nof-1);
	printf("\nEnter the number of processes:");
	scanf("%d",&nop);
	for(i=0;i<nop;i++)
	{
		printf("Enter the no. of pages for process %d:",i);
		scanf("%d",&process[i].n);
	}
	for(i=0;i<nop;i++)
	{
		for(j=0;j<process[i].n;j++)
		{
			x:
			if(process[i].n>nof)
			{
				printf("only %d frames are available!this process cannot be allocates!",nof);
				for(j=0;j<process[i].n;j++)
				{
					process[i].p[j]=-1;
				}
				break;
			}
			printf("\nPage no %d of process %d is allocated to which frame:",j,i);
			scanf("%d",&frame1);
			k=frame1;
			if(frame[k]==0 && frame1<nof)
			{
				frame[k]=1;
				process[i].p[j]=frame1;
			}
			else
			{
				if(frame1>=nof)
				{
					printf("\n\t-Error! %d is out of bound of frame.",frame1);
				}
				//printf("\n Already allocated frame:");
				y=no_of_frames();
				printf("\nnumber of free frames:%d",y);
				printf("\nThe free frames are:\n");
				int o;
				for(o=0;o<nof;o++)
				{
					if(frame[o]==0)
					{
						printf("%d",o);
					}
				}
				if(y==0 || y<process[i].n)
				{
					printf("\nNO enough frames are free to be allocated to this process!");
					printf("\nEnter the process to be terminated:");
					scanf("%d",&pno);
					for(z=0;z<process[pno].n;z++)
					{
						temp=process[pno].p[z];
						l=temp;
						frame[l]=0;
						process[pno].p[z]=-1;
					}
					goto x;
				}
				else
				{
					goto x;
				}
			}
		}
	}
	printf("\n-------------------Page Table-----------\n");
	for(i=0;i<nop;i++)
	{
		printf("\n----------------------------------------");
		printf("\nPage no\t\tProcess no\tFrame no");
		printf("\n----------------------------------------");
		for(j=0;j<process[i].n;j++)
		{
			printf("\n%d\t\t%d\t\t%d",j,i,process[i].p[j]);
		}
	}
	printf("\n");
}





/*

------------------OUTPUT---------------

Enter the main memory size in bytes:1000

Enter the page size/frame size:100
10 frames are present in main memory and let them be numbered from 0 to 9
Enter the number of processes:3
Enter the no. of pages for process 0:5
Enter the no. of pages for process 1:4
Enter the no. of pages for process 2:5

Page no 0 of process 0 is allocated to which frame:0

Page no 1 of process 0 is allocated to which frame:2

Page no 2 of process 0 is allocated to which frame:4

Page no 3 of process 0 is allocated to which frame:6

Page no 4 of process 0 is allocated to which frame:8

Page no 0 of process 1 is allocated to which frame:1

Page no 1 of process 1 is allocated to which frame:1

number of free frames:4
The free frames are:
3579
Page no 1 of process 1 is allocated to which frame:3

Page no 2 of process 1 is allocated to which frame:5

Page no 3 of process 1 is allocated to which frame:7

Page no 0 of process 2 is allocated to which frame:6

number of free frames:1
The free frames are:
9
NO enough frames are free to be allocated to this process!
Enter the process to be terminated:1

Page no 0 of process 2 is allocated to which frame:1

Page no 1 of process 2 is allocated to which frame:3

Page no 2 of process 2 is allocated to which frame:5

Page no 3 of process 2 is allocated to which frame:7

Page no 4 of process 2 is allocated to which frame:9

-------------------Page Table-----------

----------------------------------------
Page no		Process no	Frame no
----------------------------------------
0		0		0
1		0		2
2		0		4
3		0		6
4		0		8
----------------------------------------
Page no		Process no	Frame no
----------------------------------------
0		1		-1
1		1		-1
2		1		-1
3		1		-1
----------------------------------------
Page no		Process no	Frame no
----------------------------------------
0		2		1
1		2		3
2		2		5
3		2		7
4		2		9
				

*/		
