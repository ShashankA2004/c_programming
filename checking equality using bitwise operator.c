#include<stdio.h>
int main()
{
    int x,y;
    printf("enter x and y\n");
    scanf("%d%d",&x,&y);
    if(!(x^y))
        printf("%d is equal to %d\n",x,y);
    else
        printf("%d is not equal to %d\n",x,y);


    return 0;


}
