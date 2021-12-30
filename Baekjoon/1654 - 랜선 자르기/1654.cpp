#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    long long int k, cnt = 0, dap = 0, arr[10003];
    scanf("%lld %lld", &n, &k);
    for(int i = 0; i < n; i++) {
        scanf("%lld", &arr[i]);
    }
    sort(arr, arr+n);

    long long int left = 1, right = 33333333333, mid;
    while(left <= right) {
        mid = (left+right)/2, cnt = 0;
        for(int i = 0; i < n; i++) {
            cnt = cnt + (arr[i]/mid);
        }
        if(cnt >= k) {
            if(dap < mid) dap = mid;
            left = mid+1;
        }
        else if(cnt < k) right = mid-1;
    }
    printf("%lld", dap);
}
