#include<stdio.h>
int rev(int);
main ()
{
    int n,r;
    printf("enter a number\n");
    scanf("%d",&n);
    r=rev(n);
    r=rev(r);
    printf("reverse of number=%d",r);
}

int rev(int n)
{
    int ld,tot;
    tot=0;
    while (n!=0)
    {
        ld=n%10;
        if(ld==1)
        {
            ld=5;
        }
        tot=(tot*10)+ld;
        n=n/10;
    }
    return tot;
}

