 #include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *strConc (char *str1, char *str2)
{
    int len = (strlen(str1) + strlen(str2));
    char *concatenate = (char*)malloc(len+1);
    int i=0, j=0;
    while (str1[i] != '\0') {
        concatenate[i] = str1[i];
        i++;
    }
    while (str2[j] != '\0') {
        concatenate[i+j] = str2[j];
        j++;
    }
    concatenate[i+j] = '\0';
    return concatenate;
}

char *strCap (char *str1)
{
    int i;
    int len = strlen(str1);
    char *newStr1 = (char*)malloc(len+1);
    for (i=0;i<len;i++)
        newStr1[i] = str1[i] - 32;
    newStr1[len] = '\0';
    return newStr1;
}

char *strComp (char *str1, char *str2)
{
    int x = strcmp(str1, str2);
    if (x == 0)
        return "Strings are Equal";
    else
        return "Strings are Unequal";
}

char *strCopy (char *str1)
{
    int i;
    int len = strlen(str1);
    char *newStr = (char*)malloc(len+1);
    for (i=0; i<=len; i++)
        newStr[i] = str1[i];
    return newStr;
}

char *strReverse (char *str1)
{
    int len = strlen(str1);
    int i,j;
    char *newStr = (char*)malloc(len+1);
    for (i=(len-1), j=0; i>=0; i--, j++) {
        newStr[j] = str1[i];
    }
    newStr[j] = '\0';
    return newStr;
}

int main()
{
    char str1[50];
    char str2[50];
    printf("Enter 1st string: ");
    scanf("%s", str1);
    printf("Enter 2nd string: ");
    scanf("%s", str2);

    char *concatenate = strConc(str1, str2);
    char *capitalize = strCap(str1);
    char *compare = strComp(str1, str2);
    char *copy = strCopy(str1);
    char *reverse = strReverse(str1);

    FILE *stringFile = fopen("stringOperations.txt", "w");

    fprintf(stringFile, "Concatenated String: %s\n", concatenate);
    fprintf(stringFile, "Capitalized String-1: %s\n", capitalize);
    fprintf(stringFile, "Comparison of Strings: %s\n", compare);
    fprintf(stringFile, "Copy of String-1: %s\n", copy);
    fprintf(stringFile, "Reversed String-1: %s\n", reverse);

    printf("Results written to stringOperations.txt");
    fclose(stringFile);
    return 0;
}


