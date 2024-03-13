#include <stdio.h>
int rec(int n)
{
	if (n <= 1)
		return n;

	return n + rec(n - 1);
}

int main()
{
    int n;
	printf("enter the value of n\n");
	scanf("%d",&n);
	printf("Sum = %d ", rec(n));
	return 0;
}

