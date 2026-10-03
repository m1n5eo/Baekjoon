#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, arr[1001];
    scanf("%d", &n);
    for(int i = 0; i < n; i++) scanf("%d", &arr[i]);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(i != j) {
                if(arr[i] < arr[j]) {
                    swap(arr[i], arr[j]);
                }
            }
        }
    }
    for(int i = 0; i < n; i++) printf("%d\n", arr[i]);
}
