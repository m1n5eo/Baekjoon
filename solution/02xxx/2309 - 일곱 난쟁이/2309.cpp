#include <bits/stdc++.h>
using namespace std;

bool compare(int a, int b) {
    return a < b;
}

int main() {
    int sum = 0, arr[11];
    for(int i = 0; i < 9; i++) scanf("%d", &arr[i]);
    sort(arr, arr+9, compare);
    for(int i = 0; i < 9; i++) {
        for(int j = i+1; j < 9; j++) {
            for(int k = 0; k < 9; k++) {
                if(k != i && k != j) sum += arr[k];
            }
            if(sum == 100) {
                for(int k = 0; k < 9; k++) {
                    if(k != i && k != j) printf("%d\n", arr[k]);
                }
                return 0;
            }
            sum = 0;
        }
    }
}