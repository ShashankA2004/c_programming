#include<stdio.h>
void read(int a[5][5],int r,int c)
{
    int i,j;
        for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            scanf("%d\t",&a[i][j]);
        }
    }
}

void dis(int a[5][5],int r,int c)
{
    int i,j;
        for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            printf("%d\t",a[i][j]);
        }
        printf("\n");
    }
}
int c1,r2,r1,c2;
void mul(int a[r1][c1],int b[r2][c2],int result[r1][c2])
{
    printf("%d\t%d",c1,r2);

    int i,k,j;
    printf("\n\n");
    for(i=0;i<r1;i++)
    {
        printf("hiijih");
        for(j=0;j<c2;j++)
        {
            result[i][j]=0;
            for(k=0;k<r2;k++)
            {
                result[i][j] += a[i][k]*b[k][j];
            }
            printf("%d\t",result[i][j]);
        }
        printf("\n");
    }

}
int main()
{
    int a[5][5];
    int s[5][5];
    int r1,r2,c1,c2;
    int b[5][5];
    printf("enter the number of rows and columns of matrices 1\n");
    scanf("%d%d",&r1,&c1);
    read(a,r1,c1);
    dis(a,r1,c1);
    printf("\n");
    printf("enter the number of rows and columns of matrices 2\n");
    scanf("%d%d",&r2,&c2);
    read(b,r2,c2);
    dis(b,r2,c2);
    printf("\n");
    int i,j,k;
    printf("\n\n");
    for(i=0;i<r1;i++)
    {

        for(j=0;j<c2;j++)
        {
            s[i][j]=0;
            for(k=0;k<r2;k++)
            {
                s[i][j] += a[i][k]*b[k][j];
            }
            printf("%d\t",s[i][j]);
        }
        printf("\n");
    }


}



/*
2
2
1
2
3
4
2
2
5
6
7
8
9



*/
