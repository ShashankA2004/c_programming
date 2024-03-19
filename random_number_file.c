#include<stdio.h>
#include<stdlib.h>
void inc(int a[100],int n);
int main()
{
    int b[100];
    int i,lower=0,upper=100,num;
    FILE *ptr1,*ptr2,*ptr3;
    ptr2=fopen("arr.txt","w");
    ptr3=fopen("arr2.txt","w");
    for(i=0;i<10;i++)
    {
        num=(rand()%(upper-lower+1))+lower;
        b[i]=num;
    }
    for(i=0;i<10;i++)
    {
        printf("%d\t",b[i]);
        fprintf(ptr2,"%d\n",b[i]);
    }
    inc(b,10);
    printf("\n");

    for(i=0;i<10;i++)
    {
        printf("%d\t",b[i]);
        fprintf(ptr3,"%d\n",b[i]);
    }
}

void inc(int a[100],int n)
{
    int i,j,temp;
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-1-i;j++)
        {
            if(a[j]>a[j+1])
            {
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }
}


