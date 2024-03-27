 #include<stdio.h>

int linearSearch(int A[20],int n,int key)
{
    int count=0;
    int i;
    for(i=0;i<n;i++)
    {
        if(A[i]==key)
            count++;
    }
    return count;
}

main()
{
    FILE *iptr,*optr;
    iptr=fopen("read.txt","r");
    optr=fopen("LinearSearch.txt","w");

    int n=10,A[20];
    int i;
    for(i=0;i<n;i++)
    {
        fscanf(iptr,"%d",&A[i]);
    }

    int key;
    printf("Enter key element: ");
    scanf("%d",&key);
    int num;
    num=linearSearch(A,n,key);
    fprintf(optr,"%d occurs %d times",key,num);

    fclose(iptr);
    fclose(optr);
}

