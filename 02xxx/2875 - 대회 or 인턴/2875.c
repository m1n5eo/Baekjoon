#include <stdio.h>

int min(int a, int b) {
    if(a < b) return a;
    else return b;
}

int main() {
    int woman, man, intern;
    scanf("%d %d %d", &woman, &man, &intern);

    int team = min(woman/2, man/1);
    int remain = (woman-2*team) + (man-team);

    while(remain < intern) {
        team -= 1;
        remain += 3;
    }

    printf("%d", team);
    
    return 0;
}