#include<stdio.h>
int arm(int);
main ()
{
    int n,sum;
    printf("enter a number\n");
    scanf("%d",&n);
    sum=arm(n);
    if(sum==n)
        printf("armstrong number");
    else
    printf("not armstrong number\n");

}

int arm(int n)
{
    int i;
    int ld,s=0,count=0;
    i=n;
    for(;n!=0;)
    {
        count++;
        n=n/10;
    }
    printf("%d\n",count);
    for(;i!=0;)
    {
        ld=i%10;
        s=s+(pow(ld,count));
        i=i/10;
    }
    printf("%d\n",s);
    return s;
}

