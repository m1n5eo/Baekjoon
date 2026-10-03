#include <iostream>
#include <vector>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define INF 1234567890

int left(int x) { return x/5; }
int right(int x) { return x%5; }
int cal(int a, int b) { return a*5+b; }
int move(int s, int e) {
    if(s == 0) return 2;
    else if(s == e) return 1;
    else if((s+2)%4 == e%4) return 4;
    else return 3;
}

int solution() {
    vector<int> ddr(1, 0);
    while(true) {
        int temp; cin >> temp;
        if(temp == 0) break;
        ddr.push_back(temp);
    }

    int n = ddr.size();
    vector<vector<int>> dp(n, vector<int>(25, INF));
    dp[0][0] = 0;
    for(int i = 1; i < n; i++) {
        for(int j = 0; j < 25; j++) {
            if(dp[i-1][j] != INF) {
                if(ddr[i] != right(j)) dp[i][cal(ddr[i], right(j))] = min(dp[i][cal(ddr[i], right(j))], dp[i-1][j] + move(left(j), ddr[i]));
                if(ddr[i] != left(j)) dp[i][cal(left(j), ddr[i])] =  min(dp[i][cal(left(j), ddr[i])], dp[i-1][j] + move(right(j), ddr[i]));
            }
        }
    }
    
    int ret = INF;
    for(int j = 0; j < 25; j++) ret = min(ret, dp[n-1][j]);
    return ret;
}

int main() {
    FASTIO
    cout << solution();
}