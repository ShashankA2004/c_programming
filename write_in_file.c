#include<stdio.h>
#include<stdlib.h>
int main()
{
    FILE *input;
    int i;
    int k=553;
    input=fopen("read.txt","a");
    if(input==NULL)
    {
        perror("error:");
        exit(0);
    }
    fprintf(input,"\n%d",k);

    return 0;
}

