#include <bits/stdc++.h>
using namespace std;

int arr[22];

int main() {
    int k = 0, n;
    scanf("%d", &n);
    while(n) {
        arr[k] = n%10;
        n=n/10;
        k++;
    }

    sort(arr, arr+k);
    for(int i = k-1; i >= 0; i--) printf("%d", arr[i]);
}
