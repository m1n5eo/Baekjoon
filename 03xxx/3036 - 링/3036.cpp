#include <bits/stdc++.h>
using namespace std;

int n;
int arr[101], check[1001];

int main() {
    scanf("%d", &n);
    for(int i = 0; i < n; i++) scanf("%d", &arr[i]);
    for(int i = 1; i <= arr[0]; i++) {
        if(arr[0]%i == 0) {
            for(int j = i; j <= arr[0]; j+=i) check[j] = i;
        }
    }
    for(int i = arr[0]+1; i <= 1000; i++) {
        if(i%arr[0]) check[i] = check[i%arr[0]];
        else check[i] = check[arr[0]];
    }
    for(int i = 1; i < n; i++) {
        printf("%d/%d\n", arr[0]/check[arr[i]], arr[i]/check[arr[i]]);
    }
}