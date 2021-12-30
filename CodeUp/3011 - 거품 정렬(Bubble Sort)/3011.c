#include <stdio.h>
#include <algorithm>

using namespace std;

int main() {
    int n, arr[1000], cnt = 0, dap = 0;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    for(int i = n - 1; i > 0; i--) {
        for(int j = 0; j < i; j++) {
            if(arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                cnt = cnt + 1;
            }
        }
        if(cnt > 0) dap = dap + 1;
        cnt = 0;
    }

    printf("%d", dap);
}