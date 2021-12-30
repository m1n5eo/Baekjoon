#include <stdio.h>

int main()
{
    int n, m;
    scanf("%d-%d", &n, &m);
    if(m/1000000==1) {
        printf("19%02d/", n/10000);
        n = n % 10000;
        printf("%02d/", n/100);
        n = n % 100;
        printf("%02d ", n);
        printf("M");
    }
    else if(m/1000000==2) {
        printf("19%02d/", n/10000);
        n = n % 10000;
        printf("%02d/", n/100);
        n = n % 100;
        printf("%02d ", n);
        printf("F");
    }
    else if(m/1000000==3) {
        printf("20%02d/", n/10000);
        n = n % 10000;
        printf("%02d/", n/100);
        n = n % 100;
        printf("%02d ", n);
        printf("M");
    }
    else {
        printf("20%02d/", n/10000);
        n = n % 10000;
        printf("%02d/", n/100);
        n = n % 100;
        printf("%02d ", n);
        printf("F");
    }
    return 0;
}