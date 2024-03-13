#include<stdio.h>
void read(float[],int);
void dis(float[],int );
int ls(float[],int,float);
main()
{
    int n,count;
    float m[100],key;
    printf("enter a number\n");
    scanf("%d",&n);
    read(m,n);
    dis(m,n);
    printf("enter a key\n");
    scanf("%f",&key);
    count=ls(m,n,key);
    printf("%d",count);
    if(count>0)
        printf("key found\n");
    else
        printf("key not found\n");
}

void read(float m[100],int n)
{
    int i;
    for(i=0;i<n;i++)
    {
    scanf("%f",&m[i]);
    }

}

void dis(float m[100],int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        printf("%f\n",m[i]);
    }
}

int ls(float m[100],int n,float key )
{
    int count=0,i;
    for(i=0;i<n;i++)
    {
        if(key==m[i])
        {
            count++;
        }
    }
    printf("\n%d\n",count);
    return count;
}
