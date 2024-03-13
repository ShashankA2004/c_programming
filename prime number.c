#include<stdio.h>
int prime(int n);
main()
{
    int n,res;
    printf("enter n ");
    scanf("%d",&n);

        res=prime(n);
        if(res==0)
            printf("%d is not a prime number\n",n);
        else
            printf("%d is prime number\n",n);

    }



int prime(int n)
{
    int k=2,flag=0;
    for(k=2;k<n;k++)
    {
        if(n%k==0)
        {
            flag=1;
            break;
        }
    }
    if (flag==0)
        return 1;
    else
        return 0;

}
