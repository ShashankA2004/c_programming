#include<stdio.h>
int pal(int);
main ()
{
    int n,r;
    printf("enter a number\n");
    scanf("%d",&n);
    r=pal(n);
    if (r==n)
    {
        printf("palindrome number\n");
    }
    else
    {printf("not palindrome number\n");

    }
}

int pal(int n)
{
    int ld,sum;
    sum=0;
    while(n!=0)
    {
        ld=n%10;
        sum=sum*10+ld;
        n=n/10;
    }
    printf("%d",sum);
    return sum;
}
