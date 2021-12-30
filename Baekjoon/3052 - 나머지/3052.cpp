#include <bits/stdc++.h>
using namespace std;

int arr[42];

int main() {
    int n, cnt = 0;
    for(int i = 1; i <= 10; i++) {
        scanf("%d", &n);
        arr[n%42]++;
    }
    for(int i = 0; i < 42; i++) {
        if(arr[i] != 0) cnt+=1;
    }
    printf("%d", cnt);
}
