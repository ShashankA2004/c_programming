#include<stdio.h>
int gcd(int,int);
int lcm(int,int,int);
main ()
{
    int a,b,g,l;
    printf("enter 2 number\n");
    scanf("%d%d",&a,&b);
    g=gcd(a,b);
    printf("GCD of number=%d",g);
    l=lcm(g,a,b);
    printf("LCM of number=%d",l);
}

int gcd(int a,int b)
{
    int r=0;
    while(a!=0)
    {
        r=b%a;
        b=a;
        a=r;
    }

    return b;
}

int lcm(int g,int a,int b)
{
    int bc=(a*b/g);
    return bc;
}
