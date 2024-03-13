#include<stdio.h>
int main()
{
    int n;
    printf("enter binary number\n");
    scanf("%d",&n);
    int a=1,ans=0;
    while(n!=0)
    {
        ans=ans+(n%10)*a;
        n=n/10;
        a=a*2;
    }
    printf("\n%d",ans);
    return 0;
}
