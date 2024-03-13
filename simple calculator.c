#include<stdio.h>
main()
{
    float a,b,tot;
    char c;
    printf("enter two values and operator\n");
   scanf("%f%f%*c%c",&a,&b,&c);
    switch(c)
    {
    case '+':
        tot=a+b;
        printf("%f",tot);
        break;
    case'-':
        tot=a-b;
        printf("%f'tot");
        break;
    case'*':
        tot=a*b;
        printf("%f",tot);
        break;
    case'/':if(b==0)
    printf("invalid");
          else
          {

        tot=a/b;
        printf("%f",tot);
          }
        break;
    case'%':
        tot=(int)a%(int)b;
        printf("%f",tot);
        break;
    }
}


