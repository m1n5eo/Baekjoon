#include <stdio.h>
#include <algorithm>

using namespace std;

int arr[100003];

int binary(int _n, int _key) {
    int left = 0, right = _n-1;
    while(left <= right) {
        int mid = (left+right) / 2;
        if(arr[mid] == _key) return 1;
        else if(arr[mid] < _key) left=mid+1;
        else right=mid-1;
    }
    return 0;
}

int main() {
    int n, m, key;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) scanf("%d", &arr[i]);
    sort(arr, arr+n);
    scanf("%d", &m);
    for(int i = 0; i < m; i++) {
        scanf("%d", &key);
        printf("%d\n", binary(n, key));
    }
}
