#include<stdio.h>
void area(int ,int *,int *);
main()
{
    int r,a,c;
    printf("enter radius\n");
    scanf("%d",&r);
    area(r,&a,&c);
    printf("a=%d c=%d",a,c);
}

void area (int r,int *a,int *c)
{
    *a=3.142*r*r;
    *c=3.142*2*r;
}
