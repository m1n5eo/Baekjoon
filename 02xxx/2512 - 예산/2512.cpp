#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, arr[10003], money;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) scanf("%d", &arr[i]);
    scanf("%d", &money);
    sort(arr, arr+n);
    int left = 0, right = arr[n-1];

    while(left <= right) {
        int mid = (left+right)/2, cnt = 0, sum = 0;
        for(int i = 0; i < n; i++) {
            if(mid < arr[i]) {
                sum = sum + mid;
            }
            else sum = sum + arr[i];
        }
        if(sum > money) right = mid-1;
        else if(sum <= money) {
            left = mid+1;
        }
    }
    printf("%d", right);
}
