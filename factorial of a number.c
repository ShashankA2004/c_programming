#include<stdio.h>
int fact(int);
main()
{
    int n,r;
    printf("enter the valve of n\n");
    scanf("%d",&n);
    if(n>=0)
    {
        r=fact(n);
        printf("%d!=%d",n,r);
    }
    else
    {
        printf("invalid input");
    }
}

int fact(int n)
{
    int i,f=1;
    for(i=1;i<=n;i++)
    {
        f=f*i;
    }
    return f;
}
