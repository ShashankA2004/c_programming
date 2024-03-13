#include<stdio.h>
main()
{
    char ch;
    printf("ENTER A UPPERCASE ALPHABET\n");
    scanf("%c",&ch);
    ch=ch+32;
    printf("%c",ch);

}
