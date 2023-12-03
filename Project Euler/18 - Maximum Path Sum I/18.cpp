#include <iostream>
using namespace std;

#define num 15

int arr[num][num], dp[num][num];

int main() {
    for(int i = 0; i < num; i++) {
        for(int j = 0; j <= i; j++) {
            cin >> arr[i][j];
        }
    }

    dp[0][0] = arr[0][0];

    for(int i = 1; i < num; i++) {
        dp[i][0] = dp[i-1][0] + arr[i][0];
        dp[i][i] = dp[i-1][i-1] + arr[i][i];
        for(int j = 1; j < i; j++) {
            dp[i][j] = dp[i-1][j-1] > dp[i-1][j]? dp[i-1][j-1]+arr[i][j] : dp[i-1][j]+arr[i][j];
        }
    }

    int dpMax = 0;
    for(int i = 0; i < num; i++) {
        if(dpMax < dp[num-1][i]) dpMax = dp[num-1][i];
    }
    cout << dpMax;
}