#include <bits/stdc++.h>
using namespace std;

int arr[10003] = {0, 1, 5, };

int main() {
    int n;
    scanf("%d", &n);
    for(int i = 3; i <= n; i++) {
        if(i % 2 == 0) arr[i] = ((arr[i-1] + arr[i-2])*2 + 1) % 100007;
        else if(i % 2 != 0) arr[i] = ((arr[i-1] + arr[i-2])*2 - 1) % 100007;
    }

    printf("%d", arr[n]);
}