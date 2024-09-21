#include <bits/stdc++.h>
using namespace std;

int arr[11] = {500, 100, 50, 10, 5, 1, };

int main() {
    int n, cnt = 0;
    scanf("%d", &n);
    n = 1000 - n;

    for(int i = 0; i < 6; i++) {
        if(n / arr[i] != 0) {
            cnt = cnt + n / arr[i];
            n = n - n/arr[i]*arr[i];
        }
    }
    printf("%d", cnt);
}
