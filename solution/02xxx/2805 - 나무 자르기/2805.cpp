#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    long long int sum = 0;
    scanf("%d %d", &n, &m);
    vector <int> arr(n);
    for(int i = 0; i < n; i++) scanf("%d", &arr[i]);
    sort(arr.begin(), arr.end());

    int left = 0, right = 2000000000;
    while(left <= right) {
        int mid = (left+right)/2;
        sum = 0;
        for(int i = 0; i < n; i++) {
            if(arr[i]-mid <= 0) continue;
            else {
                sum = sum + (arr[i]-mid);
            }
        }
        if(sum >= m) left = mid+1;
        else if(sum < m) right = mid-1;
    }
    printf("%d", right);
}