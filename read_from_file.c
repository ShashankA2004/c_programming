#include<stdio.h>
#include<stdlib.h>
int main()
{
    FILE *input;
    int i;
    input=fopen("read.txt","r");
    if(input==NULL)
    {
        perror("error:");
        exit(0);
    }
    while(!feof(input))
    {
       fscanf(input,"%d",&i);
       printf("%d\t",i);
    }
}
