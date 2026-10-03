#include <iostream>
using namespace std;

struct type {
    int map;
    long long int dp;
};

int n, a, b;
type arr[111][111];

int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> arr[i][j].map;
        }
    }

    arr[0][0].dp = 1;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(arr[i][j].map == 0) continue;
            
            int dist = arr[i][j].map;

            if(i+dist < n) arr[i+dist][j].dp = arr[i+dist][j].dp + arr[i][j].dp;
            if(j+dist < n) arr[i][j+dist].dp = arr[i][j+dist].dp + arr[i][j].dp;
        }
    }

    cout << arr[n-1][n-1].dp;

    return 0;
}