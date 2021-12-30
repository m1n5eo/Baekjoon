#include <stdio.h>
#include <algorithm>

using namespace std;

int arr[5000000], cnt = 0;

int main() {
    long long int a, b;
    scanf("%lld %lld", &a, &b);
    for(int i = 1; i*i <= b; i++) {
        if(a % i == 0) {
            arr[cnt] = i;
            cnt = cnt + 1;
            arr[cnt] = a/i;
            cnt = cnt + 1;
            if(b % i == 0) {
                arr[cnt] = b/i;
                cnt = cnt + 1;
            }
        }
        else if(b % i == 0) {
            arr[cnt] = i;
            cnt = cnt + 1;
            arr[cnt] = b/i;
            cnt = cnt + 1;
        }
    }
    sort(arr, arr+cnt);
    for(int i = 0; i < cnt; i++) {
        if(arr[i] == arr[i-1]) continue;
        printf("%d ", arr[i]);
    }
}