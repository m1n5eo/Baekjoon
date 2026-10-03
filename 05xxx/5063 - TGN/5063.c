#include <stdio.h>

int main() {
    int t;

    scanf("%d", &t);

    for(int i = 0; i < t; i++) {
        int r, e, c;
        
        scanf("%d %d %d", &r, &e, &c);
        
        if(r < e-c) printf("advertise\n");
        else if(r == e-c) printf("does not matter\n");
        else if(r > e-c) printf("do not advertise\n");
    }

    return 0;
}