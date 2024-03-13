#include <stdio.h>
int main()
{
	char string1[50];
    char string2[50];
	printf("enter string1\n");
	scanf("%s",string1);
	printf("enter string2\n");
	scanf("%s",string2);
	strcat(string1,string2);
	printf("Concatenated String: %s\n", string1);
	return 0;
}

