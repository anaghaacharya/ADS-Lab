#include<stdio.h>

int check_safe(int n,int m,int i, int j)
{
    if(i<0||i>=n)
     return 0;
    if(j<0||j>=m)
     return 0;
    return 1;
}

void island(int I[][50],int n, int m, int i, int j)
{
    if(check_safe(n,m,i,j)&&I[i][j]==1)
    {
        I[i][j]=0;
        island(I,n,m,i-1,j-1);
        island(I,n,m,i-1,j);
        island(I,n,m,i-1,j+1);
        island(I,n,m,i,j-1);
        island(I,n,m,i,j+1);
        island(I,n,m,i+1,j-1);
        island(I,n,m,i+1,j);
        island(I,n,m,i+1,j+1);
    }
}

int no_of_islands(int I[][50],int n, int m) 
{
    int count=0;
    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
         if(I[i][j]==1)
         {
             count++;
             island(I,n,m,i,j);
         }
    }
if(count==0)
 return 0;
return count;
}


int main()
{
    int i,j,n,m;
    int I[50][50];
    printf("Enter the number of rows and columns\n");
    scanf("%d %d",&n,&m);
    printf("Enter the values:\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            scanf("%d",&I[i][j]);
        }
    }
   printf("\nTotal number of islands : %d", no_of_islands(I,n,m));
    return 0;
}
