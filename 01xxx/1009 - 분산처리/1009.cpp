#include <bits/stdc++.h>
using namespace std;

int t, n, m;
int arr[11][11];

void setting() {
    for(int i = 1; i <= 4; i++) arr[0][i] = 10;
    for(int i = 1; i < 10; i++) arr[i][1] = i;
    for(int i = 1; i < 10; i++) {
        for(int j = 2; j <= 4; j++) {
            arr[i][j] = (arr[i][j-1]*i)%10;
        }
    }
    for(int i = 0; i < 10; i++) arr[i][0] = arr[i][4];
}

int main() {
    setting();
    cin >> t;
    for(int i = 0; i < t; i++) {
        cin >> n >> m;
        cout << arr[n%10][m%4] << "\n";
    }
}