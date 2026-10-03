#include <iostream>
#include <algorithm>
#include <stdlib.h>
using namespace std;

int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios::sync_with_stdio(false);

    int n, arr[1111], dp[1111] = {0, };

    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> arr[i];

        if(i == 0) dp[i] = 0;
        else if(i == 1) dp[i] = abs(arr[1]-arr[0]);

        int arr_min = arr[i], arr_max = arr[i];

        for(int j = i; j >= 0; j--) {
            arr_min = min(arr_min, arr[j]);
            arr_max = max(arr_max, arr[j]);

            if(j != 0) dp[i] = max(dp[i], dp[j-1]+arr_max-arr_min);
            else if(j == 0) dp[i] = max(dp[i], arr_max-arr_min);
        }
    }
    
    cout << dp[n-1];

    return 0;
}