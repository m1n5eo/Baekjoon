#include <stdio.h>
#include <algorithm>
using namespace std;

int main() {
    int n, sum = 0, a[111], b[111];
    scanf("%d", &n);
    for(int i = 0; i < n; i++) scanf("%d", &a[i]);
    for(int i = 0; i < n; i++) scanf("%d", &b[i]);
    sort(a, a+n);
    sort(b, b+n);
    for(int i = 0; i < n; i++) {
        sum = sum + a[i]*b[n-i-1];
    }
    printf("%d", sum);
}