#include <bits/stdc++.h>
using namespace std;

int n = 1, lotto[7], arr[14];

void f(int idx, int end_i) {
    if(idx == 6) {
        for(int i = 0; i < 6; i++) printf("%d ", lotto[i]);
        printf("\n");
    }
    for(int i = end_i+1; i < n; i++) {
        lotto[idx] = arr[i];
        f(idx+1, i);
    }
}
