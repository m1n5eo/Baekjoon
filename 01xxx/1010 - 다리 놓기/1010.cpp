#include <bits/stdc++.h>
using namespace std;

int arr[31][31];

int main() {
    for(int i = 1; i <= 30; i++) arr[1][i] = i;
    for(int i = 2; i <= 30; i++) {
        for(int j = 1; j <= 30; j++) {
            arr[i][j] = arr[i-1][j-1]+arr[i][j-1];
        }
    }

    int t, n, m;
    cin >> t;
    for(int i = 0; i < t; i++) {
        cin >> n >> m;
        cin >> arr[n][m] >> "\n";
    }
}