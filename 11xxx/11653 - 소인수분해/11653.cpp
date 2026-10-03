#include <bits/stdc++.h>
using namespace std;

int arr[10000001] = {1, 1, }, ss[5000001];

int main() {
    for(int i = 2; i <= 10000000; i++) {
        if(arr[i] == 0) {
            for(int j = i+i; j <= 10000000; j+=i) arr[j] = 1;
        }
    }

    int n;
    scanf("%d", &n);
    if(!arr[n]) {
        printf("%d", n);
        return 0;
    }
    for(int i = 2; i <= 10000000; i++) {
        if(!arr[i]) {
            while(n%i == 0) {
                printf("%d\n", i);
                n=n/i;
            }
        }
    }
}
