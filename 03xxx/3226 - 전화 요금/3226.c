#include <stdio.h>

int n, res, start_h, start_m;
int start_call, end_call;

int main() {
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d:%d %d", &start_h, &start_m, &end_call);

        start_call = start_h*60 + start_m;

        for(int t = 0; t < end_call; t++) {
            if(7*60 <= start_call && start_call < 19*60) {
                start_call += 1;
                res += 10;
            }
            else {
                start_call += 1;
                res += 5;
            }

            if(start_call == 24*60) {
                start_call = 0;
            }
        }
    }
    
    printf("%d", res);
    return 0;
}