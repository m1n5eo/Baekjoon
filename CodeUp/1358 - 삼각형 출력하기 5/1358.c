#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i,j,n,k;
    scanf("%d",&n);
    k=2+(n-5)/2;
    for(i=1;i<=n/2+1;i++){
        for(j=n-i-k;j>0;j--){
            printf(" ");
        }
        for(j=0;j<i*2-1;j++){
            printf("*");
        }
        printf("\n");
    }
    return 0;
 }