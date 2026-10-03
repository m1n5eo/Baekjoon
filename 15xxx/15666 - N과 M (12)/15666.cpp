#include <bits/stdc++.h>
using namespace std;

int n, m, temp;
int arr[11], print[11];

void func(int cnt, int idx) {
    if(cnt == m) {
        for(int i = 0; i < m; i++) cout << print[i] << " ";
        cout << endl;
        return;
    }
    for(int i = idx; i < n; i++) {
        print[cnt] = arr[i];
        func(cnt+1, i);
    }
}

int main() {
    cin >> n >> m;
    temp = n;
    for(int i = 0; i < n; i++) cin >> arr[i];
    sort(arr, arr+n);
    for(int i = 1; i < temp; i++) {
        if(arr[i-1] == arr[i]) {
            arr[i-1] = 1234567890;
            n--;
        }
    }
    sort(arr, arr+temp);
    func(0, 0);
}