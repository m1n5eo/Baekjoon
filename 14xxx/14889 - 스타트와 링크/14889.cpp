#include <bits/stdc++.h>
using namespace std;

int n, k, startSum, linkSum;
int dap = 1234567890;
int print[22], print2[22], check[22], ability[22][22];

void func(int cnt, int idx) {
    if(cnt == n/2) {
        if(print[0] != 0) return;
        startSum = 0; linkSum = 0;
        int c = 0;
        for(int i = 0; i < n; i++) {
            if(check[i] == 0) print2[c++] = i;
        }
        for(int i = 0; i < n/2; i++) {
            for(int j = i+1; j < n/2; j++) {
                startSum += ability[print[i]][print[j]];
                linkSum += ability[print2[i]][print2[j]];
            }
        }
        dap = min(dap, abs(startSum-linkSum));
        return;
    }
    for(int i = idx; i < n; i++) {
        print[cnt] = i;
        check[i] = 1;
        func(cnt+1, i+1);
        check[i] = 0;
    }
}

int main() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> k;
            ability[min(i,j)][max(i,j)] += k;
        }
    }
    func(0, 0);
    cout << dap;
}