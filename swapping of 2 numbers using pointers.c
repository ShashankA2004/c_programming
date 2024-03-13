#include<stdio.h>
void swap (int *,int *);
main()
{
    int a,b;
    scanf("%d%d",&a,&b);
    printf("a=%d b=%d",a,b);
    swap(&a,&b);
    printf("a=%d b=%d",a,b);
}
void swap (int *a,int *b)
{
    int t;
    t=*a;
    *a=*b;
    *b=t;
}
