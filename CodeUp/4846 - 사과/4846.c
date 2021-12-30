#include <stdio.h>

int main()
{
    int n, student, apple, sum = 0;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d %d", &student, &apple);
        sum = sum + apple % student;
    }
    printf("%d", sum);
}