#include <stdio.h>
#include <algorithm>
using namespace std;

int main() {
    int n, k, arr[5001], sum = 0;
    scanf("%d %d", &n, &k);
    for(int i = 0; i < n; i++) scanf("%d", &arr[i]);
    sort(arr, arr+n);
    for(int i = n-1; i >= n-k; i--) sum += arr[i]-(n-i-1);
    printf("%d", sum);
}
