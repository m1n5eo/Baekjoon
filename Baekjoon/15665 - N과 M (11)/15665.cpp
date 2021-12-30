#include <bits/stdc++.h>
using namespace std;

int n, m, arr[11], print[11];

void func(int cnt) {
    if(cnt == m) {
        for(int i = 0; i < m; i++) cout << print[i] << " ";
        cout << "\n";
        return;
    }
    int k = -1;
    for(int i = 0; i < n; i++) {
        if(k != arr[i]) {
            print[cnt] = arr[i];
            k = arr[i];
            func(cnt+1);
        }
    }
}

int main() {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    cin >> n >> m;
    for(int i = 0; i < n; i++) cin >> arr[i];
    sort(arr, arr+n);
    func(0);
}