#include<stdio.h>
void multi(int);
main()
{
    int n;
    printf("enter the valve of n\n");
    scanf("%d",&n);
    multi(n);
}

void multi(int n)
{
    int s=1,i;
    for(i=1;i<=10;i++)
    {
        s=i*n;
        printf("%d*%d=%d\n",n,i,s);
    }
}
