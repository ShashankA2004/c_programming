#include<stdio.h>
void read(int[],int);
void dis(int[],int);
void inc(int [],int);
main()
{
    int n;
    int a[100];
    printf("Enter the valve of n\n");
    scanf("%d",&n);
    read(a,n);
    dis(a,n);
    printf("\n");
    inc(a,n);
    printf("\n");
    dis(a,n);
}
void read(int a[100],int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
}
void dis(int a[100],int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        printf("%d\t",a[i]);
    }
}
void inc(int a[100],int n)
{
    int i,j,temp;
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-1-i;j++)
        {
            if(a[j]>a[j+1])
            {
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }
}
