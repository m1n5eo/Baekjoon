#include <stdio.h>

int main() {
    int n[11], ghftn = 0, Wkrtn = 0;
    for(int i = 1; i <= 10; i++) {
        scanf("%d", &n[i]);
    }
    for(int i = 1; i <= 10; i++) {
        if(n[i] % 2 != 0 && ghftn < n[i]) {
            ghftn = n[i];
        }
        else if(n[i] % 2 == 0 && Wkrtn < n[i]) {
            Wkrtn = n[i];
        }
    }
    if(ghftn != 0) printf("%d ", ghftn);
    if(Wkrtn != 0) printf("%d", Wkrtn);
}