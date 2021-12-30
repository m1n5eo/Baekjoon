#include <stdio.h>
#include <algorithm>
using namespace std;

int main() {
    int n, k, LUD, LRL, arr[2][2];
    char ch;
    scanf("%d", &n);
    for(int i = 0; i < n*2; i++) {
        scanf(" %c", &ch);
        if(ch == 'U') LUD = 0;
        else if(ch == 'D') LUD = 1;
        else if(ch == 'R') LRL = 1;
        else if(ch == 'L') LRL = 0;
    }
    scanf("%d", &k);

    arr[LUD][LRL] = k;
    if(k == 2) {
        arr[LUD][1-LRL] = 3;
        arr[1-LUD][LRL] = 0;
        arr[1-LUD][1-LRL] = 1;
    }
    else if(k == 3) {
        arr[LUD][1-LRL] = 2;
        arr[1-LUD][LRL] = 1;
        arr[1-LUD][1-LRL] = 0;
    }
    else if(k == 0) {
        arr[LUD][1-LRL] = 1;
        arr[1-LUD][LRL] = 2;
        arr[1-LUD][1-LRL] = 3;
    }
    else {
        arr[LUD][1-LRL] = 0;
        arr[1-LUD][LRL] = 3;
        arr[1-LUD][1-LRL] = 2;
    }

    int h = 1;
    for(int i = 0; i < n; i++) h *= 2;
    for(int i = 0; i < h; i++) {
        for(int j = 0; j < h/2; j++) {
            for(int ii = 0; ii < 2; ii++) printf("%d ", arr[i%2][ii]);
        }
        printf("\n");
    }
}
