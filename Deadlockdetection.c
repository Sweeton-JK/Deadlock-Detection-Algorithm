//Deadlock Detection

#include<stdio.h>
#define size 10

char p[size],finish[size];
int n,i,j,res,req[size][size],alloc[size][size],work[size][size],avail[size][size],flag=0;

void check(int a,int b)
    {
        if(a==res)
        {
            for(j=0;j<res;j++)
            {
                work[b][j]=work[b][j]+alloc[b][j];
                finish[b]='t';
                printf("%c ",p[b]);
            }
            
        }
        else
        {
            finish[b]='f';
        }
    }

int main()
{
    printf("Enter The Number Of Processes\n");
    scanf("%d",&n);
    
    printf("\nEnter The Number Of Resources\n");
    scanf("%d",&res);
    
    printf("\n-----Processes-----\n");
     
    for(i=0;i<n;i++)
    {
        printf("\nEnter The Name Of The Process %d\n",i+1);
        scanf("%s",&p[i]);
        
        finish[i]='f';
    }
    
    printf("\n-----Available------\n");
    
    printf("\nEnter The Available Of The Processes \n");
    
    for(i=0;i<res;i++)
    {
        scanf("%d",&avail[0][i]);
    }
    
    printf("\n------Requests-----\n");
    
    for(i=0;i<n;i++)
    {
        printf("\nEnter The Request Of The Process %d\n",i+1);
        for(j=0;j<res;j++)
        {
            scanf("%d",&req[i][j]);
        }
    }
    
    printf("\n------Allocation-----\n");
    
    for(i=0;i<n;i++)
    {
        printf("\nEnter The Allocation Of The Process %d\n",i+1);
        for(j=0;j<res;j++)
        {
            scanf("%d",&alloc[i][j]);
        }
    }
  
    for(j=0;j<res;j++)
    {
        work[0][j]=avail[0][j];
    }
    
    printf("\n-----Condition Checking-----\n");
    
    for(i=0;i<n;i++)
    {
        for(j=0;j<res;j++)
        {
            if(req[i][j]<=work[i][j])
            {
                flag++;
            }
        }
        check(flag,i);
    }
        
    for(i=0;i<n;i++)
    {
        printf("%c",finish[i]);
    }

}
