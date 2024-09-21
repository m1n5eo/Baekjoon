#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m, arr[55][55];
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }
    int maxSize = -1234567890, minNM = min(n, m);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            for(int t = 0; t < minNM; t++) {
                if(i+t >= n || j+t >= m) break;
                if(arr[i][j] == arr[i+t][j] && arr[i+t][j] == arr[i][j+t] && arr[i][j+t] == arr[i+t][j+t]) {
                    maxSize = max(maxSize, (t+1)*(t+1));
                }
            }
        }
    }
    cout << maxSize;
}