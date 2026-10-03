#include <stdio.h>
#include <algorithm>
using namespace std;

bool compare(int a, int b) {
    return a < b;
}

int main() {
    int n, arr[55];
    scanf("%d", &n);
    for(int i = 0; i < n; i++) scanf("%d", &arr[i]);
    sort(arr, arr+n, compare);
    if(n%2) printf("%d", arr[n/2]*arr[n/2]);
    else printf("%d", arr[n/2-1]*arr[n/2]);
}