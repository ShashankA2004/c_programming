#include<stdio.h>
void read(int a[3][3]);
void dis(int a[3][3]);
void sum(int a[3][3],int b[3][3],int s[33][3]);
int main()
{
    int a[3][3];
    int s[3][3];
    int i,j;
    int b[3][3];
    read(a);
    dis(a);
    printf("\n");
    read(b);
    dis(b);
    printf("\n");
    sum(a,b,s);
}

void read(int a[3][3])
{
    int i,j;
        for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            scanf("%d\t",&a[i][j]);
        }
    }
}

void dis(int a[3][3])
{
    int i,j;
        for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            printf("%d\t",a[i][j]);
        }
        printf("\n");
    }
}

void sum(int a[3][3],int b[3][3],int s[3][3])
{
    int i,j;
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
           s[i][j]=a[i][j]+b[i][j];
        }
    }
    dis(s);

}

/*
1
2
3
4
5
6
7
8
9
1
1
2
3
4
5
6
7
8
9
*/
