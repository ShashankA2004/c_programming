#include<stdio.h>
#include<string.h>
int maxSatisfaction(int* satisfaction, int satisfactionSize){
    for(int i=0;i<satisfactionSize;i++){
        for(int j=i+1;j<satisfactionSize;j++){
            if(satisfaction[i]<satisfaction[j])
            {
                int temp=satisfaction[i];
                satisfaction[i]=satisfaction[j];
                satisfaction[j]=temp;
            }
        }

    }
    for(int i=0;i<5;i++)
    {
        printf("%d\t",satisfaction[i]);
    }
    printf("\n");
int ans=0,sum=0;
    for(int i=0;i<satisfactionSize;i++){
        sum+=satisfaction[i];
        if(sum<0){
            return ans;
        }
        else{
            ans+=sum;
        }

    }
    return ans;

}

