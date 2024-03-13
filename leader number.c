#include<stdio.h>
void read(int[],int);
void dis(int[],int);
void lead(int [],int);
main()
{
    int n;
    int a[100];
    printf("Enter the valve of n\n");
    scanf("%d",&n);
    read(a,n);
    dis(a,n);
    printf("\n");
    lead(a,n);



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
void lead(int a[100],int n)
{
    int i,j,flag=1;
    for(i=0;i<n;i++)
    {
        flag=1;
        for(j=i+1;j<n;j++)
        {
            if(a[i]<a[j])
            {
                flag=0;
                break;
            }
        }
        if(flag==0)
            printf("%d is  not a leader number\n",a[i]);
        else
            printf("%d is a leader number\n",a[i]);

    }
}
