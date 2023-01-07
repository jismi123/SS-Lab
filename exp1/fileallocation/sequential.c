#include<stdio.h>
#include<stdlib.h>
void main ()
{
    int i,st,len, j,c,k,count=0,f[50];
    for(i=0;i<50;i++)
    f[i]=0;
    printf("Files allocated are : \n");
    x : count = 0;
    printf("Enter starting block & length of the files : ");
    scanf("%d %d",&st,&len);
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
    }
    if(st>=80)
    printf("Cannot Allocate\n");
    else if(j!=(st+len-1))
    printf("The file is allocation to disk\n");
    else
        printf("The file is not allocated\n");
    printf("Do you want to enter more files? \n\t Yes => 1 , No => 0\nEnter your choice :");
    scanf("%d",&c);
    if(c==1)
        goto x;
    else
        exit(0);
}
	



/*


------------OUTPUT------------

Files allocated are : 
Enter starting block & length of the files : 14 3
14      1
15      1
16      1
The file is allocation to disk
Do you want to enter more files? 
         Yes => 1 , No => 0
Enter your choice :1
Enter starting block & length of the files : 14 1
The file is allocation to disk
Do you want to enter more files? 
         Yes => 1 , No => 0
Enter your choice :1
Enter starting block & length of the files : 14 4
The file is not allocated
Do you want to enter more files? 
         Yes => 1 , No => 0
Enter your choice :0


*/
