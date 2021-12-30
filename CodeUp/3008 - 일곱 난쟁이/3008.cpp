#include <bits/stdc++.h>
using namespace std;

int arr[11], seven[11];

void f(int idx, int end_i, int sum) {
    if(idx == 7 && sum == 100) {
        for(int i = 0; i < 7; i++) printf("%d\n", seven[i]);
        return;
    }
    else if(sum > 100) return;
    else if(idx == 7) return;
    for(int i = end_i+1; i < 9; i++) {
        seven[idx] = arr[i];
        f(idx+1, i, sum+seven[idx]);
    }
}

int main() {
    for(int i = 0; i < 9; i++) scanf("%d", &arr[i]);
    sort(arr, arr+9);
    f(0, -1, 0);
}