#include <bits/stdc++.h>
using namespace std;

int arr[100000003];

int main() {
    int n, m, k, sum = 0;
    scanf("%d %d %d", &n, &m, &k);

    for(int i = 0; i < 10; i++) {
        if(i == k) arr[i] += 1;
    }
    for(int i = 10; i <= 100000000; i++) arr[i] = arr[i/10]+arr[i%10];
    for(int i = n; i <= m; i++) sum += arr[i];

    printf("%d", sum);
}