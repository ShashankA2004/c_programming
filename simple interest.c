#include<stdio.h>
main()
{
    float P;
    float T;
    float R;
    float  SI;
    printf("enter the valve of P\n");
    scanf("%f%f%f",&P,&T,&R);
    SI=P*T*R/100;
    printf("SIMPLE INTEREST=%f",SI);
}
