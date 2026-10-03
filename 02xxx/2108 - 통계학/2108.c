#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    int n, arr[555555], cnt[11111] = {0, };
    double sum = 0;
    
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        sum += arr[i];
        cnt[arr[i]+4000]++;
    }

    int max_cnt = 0, max_idx, sw = 0;

    for(int i = 0; i < 11111; i++) {
        if(max_cnt < cnt[i]) {
            max_cnt = cnt[i];
            max_idx = i;
            sw = 0;
        }
        else if(sw == 0 && max_cnt == cnt[i]) {
            max_idx = i;
            sw = 1;
        }
    }
    
    qsort(arr, n, sizeof(int), compare);

    if(-sum < n && sum < 0) printf("0\n"); 
    else printf("%.0lf\n", sum/n);
    printf("%d\n", arr[n/2]);
    printf("%d\n", max_idx-4000);
    printf("%d\n", arr[n-1]-arr[0]);
}