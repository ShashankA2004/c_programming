#include<stdio.h>
void read(float[],int);
void dis(float[],int );
int max(float[],int);
int min(float[],int);
main()
{
    int n,c,k;
    float m[100];
    printf("enter a number\n");
    scanf("%d",&n);
    read(m,n);
    dis(m,n);
    k=max(m,n);
    printf("max=%d\n",k);
    c=min(m,n);
    printf("min=%d",c);

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

int max(float m[100],int n )
{
    int k=m[0],i,c;
    for(i=0;i<n;i++)
    {
        if(m[i]>k)
        {
            k=m[i];
            c=i+1;

        }
    }

    return k;
}

int min(float m[100],int n )
{
    int k=m[0],i,c;
    for(i=0;i<n;i++)
    {
        if(m[i]<k)
        {
            k=m[i];
            c=i+1;
        }
    }
    return k;
}
